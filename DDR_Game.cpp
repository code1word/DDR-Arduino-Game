#include <RGBmatrixPanel.h>
#include <LiquidCrystal.h>
#include "Arrow.h"

#define CLK 8
#define OE  9
#define LAT A3
#define A   A0
#define B   A1
#define C   A2
#define BL  10
#define BS  11
#define PB  13
#define VRx A4
#define VRy A5
#define SW  12
#define RS  2
#define EN  3
#define D4  4
#define D5  5
#define D6  6
#define D7  7

LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);
RGBmatrixPanel matrix(A, B, C, CLK, LAT, OE, false);

bool flag = false;
bool active = false;
bool end_game = false;

struct Arrow a;
struct Arrow b;
struct Arrow c;

const int ELEMENT_COUNT_MAX = 3;
struct Arrow *arrows[ELEMENT_COUNT_MAX];

int xDirection = 0;
int yDirection = 0;
int switchState = 1;

int score = 0;
int tm = 30;

const unsigned long s1[] = {1175, 1175, 2349, 1760, 165, 1661, 165, 1568, 165, 1397, 165, 1175, 1397, 1568};
const unsigned long s2[] = {1319, 1319, 1319, 165, 1047, 1319, 1568, 165, 784, 165, 1047, 784, 659, 165, 880, 988, 932, 880, 165, 784, 1319, 1568, 1760, 1319, 1047, 1175, 988, 165, 1047, 784, 659, 165, 880, 988, 932, 880, 165, 784, 1319, 1568, 1760, 1319, 1047, 1175, 988, 165};
const unsigned long s3[] = {1760, 2794, 2349, 2349, 1760, 1760, 2637, 1047, 1047, 1760, 1760, 2637, 1047, 1047, 1568, 1568, 2349, 2349};
const unsigned long s4[] = {1047, 1047, 1047, 1047, 1047, 1175, 932, 165, 784, 831, 831, 699, 699, 784, 165, 784, 831, 932, 165, 1047, 1047, 1047, 1047, 1047, 1175, 932, 165, 784, 831, 831, 932, 932, 1047, 165, 1568, 1397, 1245, 1397, 1245, 1175, 1109, 1047, 165};
const unsigned long *songs[] = {s1, s2, s3, s4};
const unsigned long song_length[] = {sizeof(s1) / 4, sizeof(s2) / 4, sizeof(s3) / 4, sizeof(s4) / 4};
int song = 0;
int note = 0;
int pos[] = {34, 8};

struct Arrow *arr;

void setup() {
  lcd.begin(16, 2);
  lcd.clear();
  lcd_introduce();
  lcd.noDisplay();
  matrix.begin();
  pinMode(PB, OUTPUT);
  pinMode(BL, OUTPUT);
  pinMode(BS, INPUT);
  pinMode(VRx, INPUT);
  pinMode(VRy, INPUT);
  pinMode(SW, INPUT_PULLUP);
  Serial.begin(9600);
  randomSeed(analogRead(4) * analogRead(5));
  song = (int) random(sizeof(songs) / 2);
  arrows[0] = &a;
  arrows[1] = &b;
  arrows[2] = &c;
  a.ypos = 57; a.xpos = 7;
  a.color = matrix.Color333(0, 7, 7);
  a.orientation = (int) random(4);
  b.ypos = 43; b.xpos = 7;
  b.color = matrix.Color333(6, 2, 7);
  b.orientation = (int) random(4);
  c.ypos = 31; c.xpos = 7;
  c.color = matrix.Color333(3, 2, 4);
  c.orientation = (int) random(4);
}

void loop() {
  while (!end_game) {
  matrix.fillScreen(matrix.Color333(0, 0, 0));
  drawLine();
  if (flag)
    colorRegion(matrix.Color333(0, 4, 0));
    draw_star(27, 13);
    draw_star(14, 2);
    draw_star(10, 14);
    draw_star(29, 1);

  xDirection = analogRead(VRy);
  yDirection = analogRead(VRx);

  switchState = digitalRead(SW);

  renderWholeScreen(arrows);

  delay (tm);


  for (int i = 0; i < ELEMENT_COUNT_MAX; i++) {
    arr = arrows[i];
    //Serial.println(flag);
    if (arr->ypos <= 15 && !flag && arr->orientation == 4) {
      digitalWrite(BL, HIGH);
    }
    if (arr->ypos <= 7 && !flag) {
      active = true;
      //flag = true;// delete
      if (arr->orientation == 0 && yDirection < 530) {
        colorRegion(matrix.Color333(0, 4, 0));
        flag = true;
      } else if (arr->orientation == 1 && xDirection < 530) {
        colorRegion(matrix.Color333(0, 4, 0));
        flag = true;
      } else if (arr->orientation == 2 && yDirection > 840) {
        colorRegion(matrix.Color333(0, 4, 0));
        flag = true;
      } else if (arr->orientation == 3 && xDirection > 840) {
        colorRegion(matrix.Color333(0, 4, 0));
        flag = true;
      } else if (arr->orientation == 4 && digitalRead(BS) == 0) {
        colorRegion(matrix.Color333(0, 4, 0));
        digitalWrite(BL, LOW);
        flag = true;
      }
      if (flag) {
        if (note == song_length[song]) {
          tm = (int) ((tm - 10) * 0.85) + 10;
          note = 0;
        }
        tone(PB, songs[song][note % song_length[song]], 200);
        note++;
      }
      break;
    }
  }

  updateAllPositions(arrows);

  if (active)
    detectBelowScreen(arrows);
  }

  matrix.fillScreen(matrix.Color333(0, 0, 0));
  pos[0] = 16;
  pos[1] = 8;
  mk_heart(pos, matrix.Color333(4, 0, 0));
  delay (650);
  matrix.fillScreen(matrix.Color333(0, 0, 0));
  tone(PB, 165, 400);
  mk_broken(pos, matrix.Color333(4, 2, 0));
  delay (150);
  
  /*
  matrix.setTextColor(matrix.Color333(3,0,3));
  matrix.print(' ');
  matrix.print('G');
  matrix.print('A');
  matrix.print('M');
  matrix.print('E');
  
  matrix.print(' ');
  matrix.print('O');
  matrix.print('V');
  matrix.print('E');
  matrix.print('R');
  */

  end_game = false;

  while (digitalRead(BS) == 1);
  song = (int) random(sizeof(songs) / 2);
  note = 0;
  a.ypos = 57; a.xpos = 7;
  a.color = matrix.Color333(0, 7, 7);
  a.orientation = (int) random(4);
  b.ypos = 43; b.xpos = 7;
  b.color = matrix.Color333(6, 2, 7);
  b.orientation = (int) random(4);
  c.ypos = 31; c.xpos = 7;
  c.color = matrix.Color333(3, 2, 4);
  c.orientation = (int) random(4);
  tm = int ((tm - 50) * 0.85) + 50;
}


void renderArrow(struct Arrow *arr) {
  pos[0] = arr->ypos;
  pos[1] = arr->xpos;
  if (arr->orientation == 0) {
    mk_up(pos, arr->color);
  }
  else if (arr->orientation == 1) {
    mk_right(pos, arr->color);
  }
  else if (arr->orientation == 2) {
    mk_down(pos, arr->color);
  }
  else if (arr->orientation == 3) {
    mk_left(pos, arr->color);
  }
  else if (arr->orientation == 4) {
    mk_heart(pos, arr->color);
  }
}

void renderWholeScreen(struct Arrow *vec[ELEMENT_COUNT_MAX]) {
  for (int i = 0; i < ELEMENT_COUNT_MAX; i++)
    renderArrow(vec[i]);
}

void updateAllPositions(struct Arrow *vec[ELEMENT_COUNT_MAX]) {
  struct Arrow *arr;
  for (int i = 0; i < ELEMENT_COUNT_MAX; i++) {
    arr = vec[i];
    (arr->ypos)--;
  }
}

void detectBelowScreen(struct Arrow *vec[ELEMENT_COUNT_MAX]) {
  struct Arrow* arr;
  for (int i = 0; i < ELEMENT_COUNT_MAX; i++) {
    arr = vec[i];
    int pos = arr->ypos;
    if (pos < 0) {

      if (!flag) {

        digitalWrite(BL, LOW);
        active = false;
        flag = false;
        end_game = true;

      }


      arr->ypos += 40;

      flag = false;
      active = false;

      int c1, c2, c3;
      do {
        c1 = (int) random(4);
        c2 = (int) random(4);
        c3 = (int) random(4);
      } while (!(c1 || c2 || c3));

      arr->color = matrix.Color333(c1, c2, c3);
      arr->orientation = (int) random(4);
      if (songs[song][(note + 2) % song_length[song]] == 165) {
        arr->orientation = 4;
      }
    }
  }
}

void drawLine() {
  for (int i = 0; i < 16; i++)
    matrix.drawPixel(7, i, matrix.Color333(3, 3, 3));
}

void draw_star(int y, int x) {
  matrix.drawPixel(y, x, matrix.Color333(7, 5, 0));
  matrix.drawPixel(y + 1, x, matrix.Color333(7, 5, 0));
  matrix.drawPixel(y - 1, x, matrix.Color333(7, 5, 0));
  matrix.drawPixel(y, x + 1, matrix.Color333(7, 5, 0));
  matrix.drawPixel(y, x - 1, matrix.Color333(7, 5, 0));
}

void colorRegion(uint16_t color) {
  for (int i = 0; i < 16; i++) {
    for (int j = 0; j < 7; j++) {
      matrix.drawPixel(j, i, color);
    }
  }
}