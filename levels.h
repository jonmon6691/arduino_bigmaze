#ifndef LEVELS_H
#define LEVELS_H

#define N_LEVELS 5

const uint8_t level_data[] PROGMEM = {
// Level 1 - 4x4 (offset 0)
	0b01111011,
	0b00010110,
	0b01000111,
	0b10101000,
// Level 2 - 8x8 (offset 4)
	0b10011101,0b00111010,
	0b10010101,0b01101101,
	0b00110010,0b00010101,
	0b11100110,0b01010010,
	0b00111011,0b01101010,
	0b11011100,0b01111100,
	0b11100010,0b01000010,
	0b10101010,0b10001010,
// Level 3 - 16x16 (offset 20)
	0b00110101,0b00110111,0b10011010,0b01011011,
	0b10001110,0b00111000,0b10101011,0b01010011,
	0b01101011,0b01111101,0b11011000,0b01100100,
	0b10001110,0b01000110,0b00010011,0b01011001,
	0b01110101,0b01100011,0b01010101,0b01101010,
	0b11000001,0b00101101,0b10101111,0b01001010,
	0b00111011,0b11011100,0b10110001,0b01100101,
	0b01101101,0b00110010,0b01110100,0b00110011,
	0b00100000,0b11001111,0b00010010,0b01001110,
	0b11111010,0b11100100,0b11001011,0b01010000,
	0b11001001,0b00100100,0b01010110,0b01011001,
	0b01010101,0b11100011,0b11010011,0b00111011,
	0b01110110,0b00101010,0b01010110,0b01100010,
	0b01001110,0b00101101,0b10101001,0b00001110,
	0b00110011,0b01100110,0b11011010,0b01011000,
	0b10101000,0b10001010,0b10101010,0b10101010,
// Level 4 - 64x4 (offset 84)
	0b10101101,0b10110011,0b11101001,0b01100111,0b10010110,0b10101011,0b10101010,0b11111010,0b11001101,0b11101010,0b00111010,0b01010011,0b11101101,0b10101001,0b11100101,0b00101010,
	0b01111011,0b10000010,0b00010111,0b10101100,0b11110010,0b11101001,0b10100110,0b00001101,0b01100011,0b00110111,0b10110101,0b11101110,0b00010111,0b10101110,0b00110101,0b00101110,
	0b11001100,0b01101110,0b10111000,0b00110110,0b01011011,0b11001110,0b10001000,0b11100001,0b01001101,0b01101000,0b00101111,0b01010010,0b10010001,0b00111011,0b11101110,0b00111011,
	0b00001010,0b10001010,0b10001010,0b10101010,0b10000010,0b10101000,0b10101010,0b00100010,0b00101010,0b00101010,0b10101000,0b00100010,0b00101010,0b10001000,0b00100010,0b10100010,
// Level 5 - 32x32 (offset 148)
	0b11100101,0b10110010,0b00110011,0b10001101,0b10111111,0b10100110,0b10011101,0b01011010,
	0b01110110,0b00110011,0b11110101,0b10010010,0b10010001,0b11100101,0b01110100,0b01101011,
	0b10000101,0b10010101,0b11011001,0b01101110,0b00110110,0b01001101,0b01000110,0b01101000,
	0b01011110,0b11010101,0b00011001,0b11100110,0b10100000,0b10110101,0b01110011,0b01111101,
	0b01010111,0b01010111,0b01101000,0b00001011,0b01011010,0b11001100,0b10001100,0b00010010,
	0b10110001,0b11011001,0b01111000,0b01011000,0b10101101,0b10010100,0b10101000,0b01101000,
	0b11010011,0b10000010,0b01010011,0b01010101,0b11001011,0b11001010,0b10110101,0b01100110,
	0b01000011,0b10001110,0b11001001,0b01011010,0b11010110,0b01101001,0b00101100,0b00100110,
	0b01010111,0b00101011,0b10010111,0b11100010,0b00101110,0b00111001,0b10110101,0b00110101,
	0b01010000,0b00101110,0b10110100,0b11100010,0b01001001,0b10110010,0b11000011,0b00110110,
	0b00111001,0b11111110,0b10101110,0b01011001,0b10110100,0b10011110,0b11100011,0b01101100,
	0b10011110,0b01010010,0b10011001,0b10011001,0b00101101,0b01110010,0b00101000,0b01100010,
	0b11110010,0b01000100,0b10011010,0b10110011,0b01001000,0b01000111,0b00101110,0b01001011,
	0b10000101,0b01001101,0b11000011,0b11100100,0b11111010,0b01111001,0b10100110,0b01010110,
	0b01011001,0b10111001,0b10010101,0b00101110,0b00000101,0b11001100,0b11101101,0b00111000,
	0b10001011,0b11001100,0b10010110,0b01100101,0b10110110,0b00100001,0b11010000,0b01101011,
	0b00111010,0b10110001,0b00111001,0b01010110,0b01001111,0b10010101,0b00111011,0b01010100,
	0b11001101,0b00110010,0b00101100,0b10011101,0b01100100,0b00110100,0b00111101,0b01011001,
	0b01111101,0b01011010,0b10101101,0b10000001,0b10101011,0b01101010,0b00110000,0b01110110,
	0b11000101,0b11011100,0b01110000,0b00111001,0b01100011,0b00110011,0b11111110,0b00011000,
	0b01010011,0b01000001,0b01000011,0b10100101,0b10110101,0b01010011,0b10000101,0b01101000,
	0b01100011,0b01010101,0b11010011,0b11110110,0b01101100,0b10100010,0b10011000,0b01001011,
	0b10010110,0b11100111,0b10100011,0b01010100,0b10011010,0b11011101,0b01000110,0b00101110,
	0b01101011,0b00110100,0b00110110,0b01010111,0b01111011,0b10100101,0b01100001,0b01101010,
	0b00110100,0b11100011,0b01110001,0b10010100,0b00011000,0b11100000,0b10010011,0b00011010,
	0b10011101,0b00101111,0b11011010,0b11001001,0b10111010,0b00110100,0b10101100,0b01011101,
	0b10000010,0b11101001,0b00000011,0b01001111,0b11111001,0b11110010,0b01110010,0b00100111,
	0b11111101,0b01010011,0b00111100,0b00011000,0b10001011,0b11001101,0b01010110,0b01111001,
	0b00000011,0b10010011,0b10000101,0b10001011,0b01101101,0b01100010,0b01010110,0b00010100,
	0b10010011,0b10100011,0b11001101,0b01001110,0b11001011,0b00011100,0b00001110,0b00111010,
	0b11011001,0b11001011,0b01110100,0b10011101,0b11111000,0b10010110,0b01001110,0b01111001,
	0b00001010,0b00100010,0b10001010,0b10100000,0b00001010,0b10000010,0b10001010,0b10001010,
};

struct level {
	int w;
	int h;
	size_t row_size;
	size_t level_offset;
};

struct level levels[] = {
	{ .w = 4, .h = 4, .row_size = 1, .level_offset = 0},
	{ .w = 8, .h = 8, .row_size = 2, .level_offset = 4},
	{ .w = 16, .h = 16, .row_size = 4, .level_offset = 20},
	{ .w = 64, .h = 4, .row_size = 16, .level_offset = 84},
	{ .w = 32, .h = 32, .row_size = 8, .level_offset = 148},
};

#endif // #ifnedef LEVELS_H
