/************** bigmaze ***************
 *    Big mazes on a little screen
 *          Jon Wallace 2020
 */

// Hack to make intellisence happy
#ifndef ARDUINO
#define ARDUINO 10810
#endif

#include <Arduino.h>
#include <avr/pgmspace.h>
#include "Adafruit_LEDBackpack.h"
#include "levels.h"

Adafruit_BicolorMatrix matrix = Adafruit_BicolorMatrix();

// Controller buttons' pin numbers
// Has to be sequential because the debounce code is lazy, ¯\_(ツ)_/¯
#define RB (14)
#define DB (15)
#define UB (16)
#define LB (17)

// Player deadzone, affects the distance from the wall where you start pushing the board
#define DZ_LO 3
#define DZ_HI 4

// super simple rising edge and debounce detector
// Warning: only works if all 4 button pin numbers are sequential
uint8_t db[4] = {0};
void on_button(int pin, int debounce, void (*callback)())
{
  if (!digitalRead(pin)) {
    if (!db[pin%4]) {
      db[pin%4] = debounce;
      callback();
    }
  } else if (db[pin%4]) db[pin%4]--;
}

// state objects
struct {
  int x;
  int y;
  int color;
} you, board;

int current_level = 0;
struct level maze;

#define SOUTH (1 << 0)
#define EAST  (1 << 1)
#define NORTH (1 << 2)
#define WEST  (1 << 3)

// Returns true if you can go in the requested direction
bool check(uint8_t direction)
{
  int x = board.x + you.x;
  int y = board.y + you.y;
  switch (direction)
  {
  case NORTH:
    if (y % 2 == 0) return true;
    if (x % 2 == 0) return false;
    return (get_cell(x/2, y/2 - 1) & SOUTH) > 0;
    break;
  
  case SOUTH:
    if (y % 2 == 0) return true;
    if (x % 2 == 0) return false;
    return (get_cell(x/2, y/2) & SOUTH) > 0;
    break;

  case EAST:
    if (y % 2 == 0) return false;
    if (x % 2 == 0) return true;
    return (get_cell(x/2, y/2) & EAST) > 0;
    break;

  case WEST:
    if (y % 2 == 0) return false;
    if (x % 2 == 0) return true;
    return (get_cell(x/2 - 1, y/2) & EAST) > 0;
    break;

  default:
    return false;
  }
}

// Button handlers
void move_up()
{
  if (!check(NORTH)) return;
  if (you.y > DZ_LO) { // creates a board movement deadzone
    you.y--;
  } else if (board.y > 0) {
    board.y--;
  } else if (you.y > 0) {
    you.y--;
  }
  update_screen();
}

void move_down()
{
  if (!check(SOUTH)) return;
  if (you.y < DZ_HI) {
    you.y++;
  } else if (board.y < maze.h*2 - 7) {
    board.y++;
  } else if (you.y < 7) {
    you.y++;
  }
  update_screen();
}

void move_left()
{
  if (!check(WEST)) return;
  if (you.x > DZ_LO) {
    you.x--;
  } else if (board.x > 0) {
    board.x--;
  } else if (you.x > 0) {
    you.x--;
  }
  update_screen();
}

void move_right()
{
  if (!check(EAST)) return;
  if (you.x < DZ_HI) {
    you.x++;
  } else if (board.x < maze.w*2 - 7) {
    board.x++;
  } else if (you.x < 7) {
    you.x++;
    if (you.x == 7) {
      // WINNER!
      board.color = you.color;
      update_screen();
      delay(1000);
      current_level = (current_level + 1) % N_LEVELS;
      setup();
      return;
    }
  }
  update_screen();
}

void update_screen()
{
  matrix.clear();
  draw_maze(board.x, board.y, board.color);
  matrix.drawPixel(you.x, you.y, you.color);
  matrix.writeDisplay();
}

uint8_t get_cell(int x, int y)
{
  int i = x / 4;
  int off = x % 4;
  if (x < 0 || x > maze.w || y < 0 || y > maze.h) {
    // Out of bounds cells are blocked
    return 0;
  } else {
    size_t cell_addr = maze.level_offset + y * maze.row_size + i;
    uint8_t maze_byte = pgm_read_byte_near(level_data + cell_addr);
    return maze_byte >> off*2 & 0b11;
  }
}

void draw_maze(int x, int y, int color)
{
  // Convert from screen coords to board coords
  int bx = x / 2;
  int by = y / 2;
  int x_off = (x+1) % 2;
  int y_off = (y+1) % 2;

  // Draw all the cells on the screen, allowing for bleed on odd cells
  for (int sy = 0 - y_off; sy < 4; sy++) {
    for (int sx = 0 - x_off; sx < 4; sx++) {
      uint8_t cell = get_cell(bx + sx, by + sy);
      x = x_off + 2*sx;
      y = y_off + 2*sy;
      matrix.drawPixel(x + 0, y + 0, LED_OFF);
      matrix.drawPixel(x + 1, y + 1, color);
      matrix.drawPixel(x + 1, y + 0, (cell & EAST) > 0 ? LED_OFF : color);
      matrix.drawPixel(x + 0, y + 1, (cell & SOUTH) > 0 ? LED_OFF : color);
    }
  }
}

void setup()
{
  Serial.begin(115200);
  Serial.println("bigmaze!");
  Serial.println(_AVR_IOXXX_H_);
  
  pinMode(RB, INPUT_PULLUP);
  pinMode(DB, INPUT_PULLUP);
  pinMode(UB, INPUT_PULLUP);
  pinMode(LB, INPUT_PULLUP);
  
  // Screen setup
  matrix.begin(0x70);
  matrix.setBrightness(6);

  // My screen is soldered in the "1" direction
  matrix.setRotation(1);

  // Init
  you.x = you.y = 1; // Start in the upper left corner
  you.color = LED_GREEN;

  board.x = board.y = 0;
  board.color = LED_RED;

  maze = levels[current_level];

  update_screen();
}

void loop()
{
  // Polling loop
  on_button(UB, 5, move_up);
  on_button(DB, 5, move_down);
  on_button(LB, 5, move_left);
  on_button(RB, 5, move_right);
}
