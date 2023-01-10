void mk_left(int pos[2], uint16_t color) {
  if (!(pos[0] < 2))
    matrix.drawPixel(pos[0] - 2, pos[1] + 1, color);
  if (!(pos[0] < 1)) {
    matrix.drawPixel(pos[0] - 1, pos[1] + 2, color);
    matrix.drawPixel(pos[0] - 1, pos[1] + 1, color);
  }
  if (!(pos[0] < 0)) {
    matrix.drawPixel(pos[0], pos[1] + 3, color);
    matrix.drawPixel(pos[0], pos[1] + 2, color);
    matrix.drawPixel(pos[0], pos[1] + 1, color);
    matrix.drawPixel(pos[0], pos[1], color);
    matrix.drawPixel(pos[0], pos[1] - 1, color);
    matrix.drawPixel(pos[0], pos[1] - 2, color);
    matrix.drawPixel(pos[0], pos[1] - 3, color);
  }
  if (!(pos[0] < -1)) {
    matrix.drawPixel(pos[0] + 1, pos[1] + 2, color);
    matrix.drawPixel(pos[0] + 1, pos[1] + 1, color);
  }
  if (!(pos[0] < -2)) {
    matrix.drawPixel(pos[0] + 2, pos[1] + 1, color);
  }
}

void mk_right(int pos[2], uint16_t color) {
  if (!(pos[0] < 2))
    matrix.drawPixel(pos[0] - 2, pos[1] - 1, color);
  if (!(pos[0] < 1)) {
    matrix.drawPixel(pos[0] - 1, pos[1] - 1, color);
    matrix.drawPixel(pos[0] - 1, pos[1] - 2, color);
  }
  if (!(pos[0] < 0)) {
    matrix.drawPixel(pos[0], pos[1] + 3, color);
    matrix.drawPixel(pos[0], pos[1] + 2, color);
    matrix.drawPixel(pos[0], pos[1] + 1, color);
    matrix.drawPixel(pos[0], pos[1], color);
    matrix.drawPixel(pos[0], pos[1] - 1, color);
    matrix.drawPixel(pos[0], pos[1] - 2, color);
    matrix.drawPixel(pos[0], pos[1] - 3, color);
  }
  if (!(pos[0] < -1)) {
    matrix.drawPixel(pos[0] + 1, pos[1] - 1, color);
    matrix.drawPixel(pos[0] + 1, pos[1] - 2, color);
  }
  if (!(pos[0] < -2)) {
    matrix.drawPixel(pos[0] + 2, pos[1] - 1, color);
  }
}

void mk_up(int pos[2], uint16_t color) {
  if (!(pos[0] < 3))
    matrix.drawPixel(pos[0] - 3, pos[1], color);
  if (!(pos[0] < 2)) {
    matrix.drawPixel(pos[0] - 2, pos[1] + 1, color);
    matrix.drawPixel(pos[0] - 2, pos[1], color);
    matrix.drawPixel(pos[0] - 2, pos[1] - 1, color);
  }
  if (!(pos[0] < 1)) {
    matrix.drawPixel(pos[0] - 1, pos[1] + 2, color);
    matrix.drawPixel(pos[0] - 1, pos[1] + 1, color);
    matrix.drawPixel(pos[0] - 1, pos[1], color);
    matrix.drawPixel(pos[0] - 1, pos[1] - 1, color);
    matrix.drawPixel(pos[0] - 1, pos[1] - 2, color);
  }
  for (int i = 0; i > -4; i--)
    if (!(pos[0] < i))
      matrix.drawPixel(pos[0] - i, pos[1], color);
}

void mk_down(int pos[2], uint16_t color) {
  for (int i = 3; i > -1; i--)
    if (!(pos[0] < i))
      matrix.drawPixel(pos[0] - i, pos[1], color);
  if (!(pos[0] < -1)) {
    matrix.drawPixel(pos[0] + 1, pos[1] + 2, color);
    matrix.drawPixel(pos[0] + 1, pos[1] + 1, color);
    matrix.drawPixel(pos[0] + 1, pos[1], color);
    matrix.drawPixel(pos[0] + 1, pos[1] - 1, color);
    matrix.drawPixel(pos[0] + 1, pos[1] - 2, color);
  }
  if (!(pos[0] < -2)) {
    matrix.drawPixel(pos[0] + 2, pos[1] + 1, color);
    matrix.drawPixel(pos[0] + 2, pos[1], color);
    matrix.drawPixel(pos[0] + 2, pos[1] - 1, color);
  }
  if (!(pos[0] < -3))
    matrix.drawPixel(pos[0] + 3, pos[1], color);
}

void mk_heart(int pos[2], uint16_t color) {
int x = pos[0];
int y = pos[1];

if (x >= 3) {
matrix.drawPixel(x-3, y, matrix.Color333(4,0,0));
}

if (x >= 2) {
matrix.drawPixel(x-2, y-1, matrix.Color333(4,0,0));
matrix.drawPixel(x-2, y, matrix.Color333(4,0,0));
matrix.drawPixel(x-2, y+1, matrix.Color333(4,0,0));
}

if (x >= 1) {
matrix.drawPixel(x-1, y-2, matrix.Color333(4,0,0));
matrix.drawPixel(x-1, y-1, matrix.Color333(4,0,0));
matrix.drawPixel(x-1, y, matrix.Color333(4,0,0));
matrix.drawPixel(x-1, y+1, matrix.Color333(4,0,0));
matrix.drawPixel(x-1, y+2, matrix.Color333(4,0,0));
}

if (x >= 0) {
matrix.drawPixel(x, y-3, matrix.Color333(4,0,0));
matrix.drawPixel(x, y-2, matrix.Color333(4,0,0));
matrix.drawPixel(x, y-1, matrix.Color333(4,0,0));
matrix.drawPixel(x, y, matrix.Color333(4,0,0));
matrix.drawPixel(x, y+1, matrix.Color333(4,0,0));
matrix.drawPixel(x, y+2, matrix.Color333(4,0,0));
matrix.drawPixel(x, y+3, matrix.Color333(4,0,0));
}

if (x >= -1) {
matrix.drawPixel(x+1, y-3, matrix.Color333(4,0,0));
matrix.drawPixel(x+1, y-2, matrix.Color333(4,0,0));
matrix.drawPixel(x+1, y-1, matrix.Color333(4,0,0));
matrix.drawPixel(x+1, y+1, matrix.Color333(4,0,0));
matrix.drawPixel(x+1, y+2, matrix.Color333(4,0,0));
matrix.drawPixel(x+1, y+3, matrix.Color333(4,0,0));
}

if (x >= -2) {
matrix.drawPixel(x+2, y-2, matrix.Color333(4,0,0));
matrix.drawPixel(x+2, y+2, matrix.Color333(4,0,0));
}
}

void mk_broken(int pos[2], uint16_t color) {
int x = pos[0];
int y = pos[1];

if (x >= 3) {
matrix.drawPixel(x-3, y-1, matrix.Color333(4,0,0));
}

if (x >= 2) {
matrix.drawPixel(x-2, y-2, matrix.Color333(4,0,0));
matrix.drawPixel(x-2, y-1, matrix.Color333(4,0,0));
matrix.drawPixel(x-2, y+2, matrix.Color333(4,0,0));
}

if (x >= 1) {
matrix.drawPixel(x-1, y-3, matrix.Color333(4,0,0));
matrix.drawPixel(x-1, y-2, matrix.Color333(4,0,0));
matrix.drawPixel(x-1, y+1, matrix.Color333(4,0,0));
matrix.drawPixel(x-1, y+2, matrix.Color333(4,0,0));
matrix.drawPixel(x-1, y+3, matrix.Color333(4,0,0));
}

if (x >= 0) {
matrix.drawPixel(x, y-4, matrix.Color333(4,0,0));
matrix.drawPixel(x, y-3, matrix.Color333(4,0,0));
matrix.drawPixel(x, y-2, matrix.Color333(4,0,0));
matrix.drawPixel(x, y-1, matrix.Color333(4,0,0));
matrix.drawPixel(x, y+2, matrix.Color333(4,0,0));
matrix.drawPixel(x, y+3, matrix.Color333(4,0,0));
matrix.drawPixel(x, y+4, matrix.Color333(4,0,0));
}

if (x >= -1) {
matrix.drawPixel(x+1, y-4, matrix.Color333(4,0,0));
matrix.drawPixel(x+1, y-3, matrix.Color333(4,0,0));
matrix.drawPixel(x+1, y-2, matrix.Color333(4,0,0));
matrix.drawPixel(x+1, y+2, matrix.Color333(4,0,0));
matrix.drawPixel(x+1, y+3, matrix.Color333(4,0,0));
matrix.drawPixel(x+1, y+4, matrix.Color333(4,0,0));
}

if (x >= -2) {
matrix.drawPixel(x+2, y-3, matrix.Color333(4,0,0));
matrix.drawPixel(x+2, y+3, matrix.Color333(4,0,0));
}
}