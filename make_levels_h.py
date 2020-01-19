from levels import levels
from math import ceil

def chunker(seq, size):
    return (seq[pos:pos + size] for pos in range(0, len(seq), size))

f = open("levels.h", "w")
f.write("#ifndef LEVELS_H\n")
f.write("#define LEVELS_H\n\n")

f.write(f"#define N_LEVELS {len(levels)}\n\n")

# Level data is kept in one long byte array.
# Meta information on how to access it is stored in 'struct level levels[]', defined at the bottom
f.write("const uint8_t level_data[] PROGMEM = {\n")

byte_counter = 0
offsets = []
for level_num, (w, h, data) in enumerate(levels, start=1):
    data[-1] |= (1 << 3) # Add an exit!
    
    #only keep east and south bits
    data = [((c&0b1000)>>2)|((c&0b10)>>1) for c in data]

    # Make a helpful comment in the header file about this level
    f.write(f"// Level {level_num} - {w}x{h} (offset {byte_counter})\n")
    offsets.append(byte_counter)

    for row in chunker(data, w):
        f.write("\t")
        # Since each maze cell only takes 2 bits to represent (can go east, can go south),
        # we can pack 4 of them into a single byte.
        for cell_chunk in chunker(row, 4):
            b = 0
            for i in range(min(len(cell_chunk), 4)):
                b |= cell_chunk[i] << (i*2)
            byte_counter += 1
            f.write(f"0b{b:08b},")
        f.write("\n")

f.write("};\n")
f.write("""
struct level {
	int w;
	int h;
	size_t row_size;
	size_t level_offset;
};

struct level levels[] = {
""")

# Tells the code how to access the level information out of the flat store in level_data[]
for (w, h, data), offset in zip(levels, offsets):
    row_size = ceil(len(data) / h / 4)
    f.write(f"\t{{ .w = {w}, .h = {h}, .row_size = {row_size}, .level_offset = {offset}}},\n")

f.write("};\n\n#endif // ifnedef levels_h")
f.close()
