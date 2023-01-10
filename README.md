# Dance Dance Revolution Arduino Game

**Group Members:** Andrew Yang and Dhruv Yalamanchi

## Introduction
This is the arduino code we wrote for our Spring 2022 Art of Engineering design project. We recreated Dance Dance Revolution, where a stream of randomly oriented/colored arrows flows down on a 16x32 RGB LED matrix panel. When the arrows reach the bottom of the panel, the user has to tilt the joystick in the direction of the arrow. A heart will occasionally scroll down too, in which case the user has to press a button. If the user gives an incorrect input or is too slow, the game ends and the panel displays a neat "Game Over" animation. Upon starting the game, an LCD display welcomes the player and starts a countdown. Our game plays 4 classic songs (the Undertale theme from Megalovania, the Mega Man 2 Medly, the Super Mario Bros theme, and Crab Rave), and as the game progresses, the arrows and hearts gradually fall faster and faster for increased difficulty.

## File Organization
**Arrow.h:** Header file that defines the Arrow struct and specifies its position, orientation, and color fields.

**DDR_Game.cpp:** The Arduino sketch containing the main driver code. It configures the different ports, triggers the LCD welcome, handles all the logic for gameplay and arrow detection, plays the music, updates the arrow fall speed, and displays the game over animation.

**Generate_Arrow.cpp:** Includes includes functions to plot up, down, left, and right-oriented arrows on the panel. It also handles cases where parts of the arrow are off-screen.

**LCD_Introduction.cpp:** File that contains the `lcd_introduce()` function, which displays "Welcome player, the game will start in 5... 4... 3... 2... 1... GO!!!"
