struct Arrow {
  //position of arrow on board
  int xpos;
  int ypos;

  //color of arrow
  uint16_t color;

  //direction: 0 up 1 right 2 down 3 left
  int orientation;
};