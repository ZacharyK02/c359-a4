#include "gpio.h"
#include "uart.h"
#include "framebuffer.h"
#include "controllerDriver.h"

////////////////////////////////////Images/////////////////////////////////////
// #include "UI_Elements/startButtonYellow.h"
// #include "UI_Elements/startButtonGrey.h"
// #include "UI_Elements/exitButtonYellow.h"
// #include "UI_Elements/exitButtonGrey.h"

#include "UI_Elements/startButton.h"
#include "UI_Elements/startButton2.h"
#include "UI_Elements/quitButton.h"
#include "UI_Elements/quitButton2.h"

#include "UI_Elements/noLives.h"
#include "UI_Elements/oneLife.h"
#include "UI_Elements/twoLives.h"
#include "UI_Elements/threeLives.h"
#include "UI_Elements/halfLife.h"
#include "UI_Elements/oneHalfLife.h"
#include "UI_Elements/twoHalfLife.h"
#include "UI_Elements/lives.h"
#include "UI_Elements/score.h"
#include "UI_Elements/zero.h"
#include "UI_Elements/one.h"
#include "UI_Elements/two.h"
#include "UI_Elements/three.h"
#include "UI_Elements/four.h"
#include "UI_Elements/five.h"
#include "UI_Elements/six.h"
#include "UI_Elements/seven.h"
#include "UI_Elements/eight.h"
#include "UI_Elements/nine.h"
#include "UI_Elements/ten.h"
#include "UI_Elements/meso.h"
#include "UI_Elements/scoreX.h"

#include "UI_Elements/time.h"
#include "UI_Elements/timeZero.h"
#include "UI_Elements/timeOne.h"
#include "UI_Elements/timeTwo.h"
#include "UI_Elements/timeThree.h"
#include "UI_Elements/timeFour.h"
#include "UI_Elements/timeFive.h"
#include "UI_Elements/timeSix.h"
#include "UI_Elements/timeSeven.h"
#include "UI_Elements/timeEight.h"
#include "UI_Elements/timeNine.h"
#include "UI_Elements/seconds.h"

#include "UI_Elements/pauseMenu.h"
#include "UI_Elements/startScreen.h"
#include "UI_Elements/restartButton.h"
#include "UI_Elements/restartButton2.h"
#include "UI_Elements/pauseQuitButton.h"
#include "UI_Elements/pauseQuitButton2.h"
#include "UI_Elements/gameOver.h"

#include "EntityAssets/grass.h"
#include "EntityAssets/rock.h"
#include "EntityAssets/apple.h"
#include "EntityAssets/coin.h"
#include "EntityAssets/goal.h"
#include "EntityAssets/flame.h"
#include "EntityAssets/saw.h"
#include "EntityAssets/snakeE.h"
#include "EntityAssets/snakeN.h"
#include "EntityAssets/snakeS.h"
#include "EntityAssets/snakeW.h"
///////////////////////////////////////////////////////////////////////////////

// Macros for display setup
#define TILESIZE 32
#define SCREENWIDTH 1024
#define SCREENHEIGHT 720
#define MENUHEIGHT 80
#define BUTTONWIDTH 160
#define BUTTONHEIGHT 320

// Macros for colors
#define BACKGROUNDGREEN 0x32a846
#define BLACK 0x000000
#define WHITE 0xffffff
#define RED 0xfa3434

// Macro for the clock register.
#define CLO_REG 0x7E003004

// Macros for game constants.
#define TICKTIME 100000
#define SAWCOUNT 6
#define FLAMECOUNT 4
<<<<<<< Updated upstream
=======
#define INVINCIBILEDURATION 100 //game ticks of invincibility.
#define SCORECONSTANT 2 // Constant to multiple score by. 
>>>>>>> Stashed changes

// Entity indices
#define PLAYER 1
#define SAW 2
#define FLAME 3

/*
* Screen size 1280x720.
* Number of horizontal cells (1024/32 = 32).
* Number of vertical cells (640/32 = 20).
* 80 extra pixels on the top for game status.
*/

unsigned oldTime;

int pressedButtons;

/*
* An empty entite or normal background tile is indicated by 0
* Map:
* 1 = Rock
* -1 = Water center
* -2 = Water top-left corner
* -3 = Water top edge
* -4 = Water top-right corner
* -5 = Water right edge
* -6 = Water bottom-right corner
* -7 = Water bottom edge
* -8 = Water bottom-left corner
* -9 = Water left edge
* Entities(use only one of each saw and flame index):
* 1 = Player
* 2 = Apple
* 3 = Coin
* 4 = Invinsibility
* 5 = Goal
* 6-8 = SawX enemies (Bounce between two barriers in x direction)
* 9-11 = SawY enemies (same as above but in the y direction)
* 12-15 = Flame enemies (Move in a psudo random direction)
*/

int level1Map[20][40] ={{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};

int level1Entities[20][40]={{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};

typedef enum{
  TRUE = 1,
  FALSE = 0
}bool;

struct State
{
    int map[(SCREENHEIGHT-MENUHEIGHT)/TILESIZE][SCREENWIDTH/TILESIZE];
    int entities[(SCREENHEIGHT-MENUHEIGHT)/TILESIZE][SCREENWIDTH/TILESIZE];
    int sawVel[SAWCOUNT];// Keeps track of the saw enemies direction of movement.
    int score;
    int lives;
    int timeRem;
    bool winFlag;
    bool restart;
    bool quit;
}state;

struct Button
{
    int xpos;
    int ypos;
    bool selected;
};

void printf(char *str) {
	uart_puts(str);
}

<<<<<<< Updated upstream
void intToString(int n)
=======
void updateTimeRem(int frameTime)
{   
    state.timeRem -= frameTime;
}

void updateScore()
>>>>>>> Stashed changes
{
    state.score = state.score + (state.timeRem/1000000) + SCORECONSTANT*state.lives; 
}

void drawUI()
{   
    // Set menu bar background to be black.
    for (int row = 0; row < MENUHEIGHT; row++)
    {
        for (int col = 0; col < SCREENWIDTH; col++)
        {
            drawPixel(col, row, BLACK);
        }
    }
    drawImage(lives.pixel_data, lives.width, lives.height, TILESIZE, TILESIZE);
    drawImage(threeLives.pixel_data, threeLives.width, threeLives.height, 4*TILESIZE, TILESIZE); // Full health at the start.
    
    // 0 score at the start. 
    drawImage(score.pixel_data, score.width, score.height, 9*TILESIZE, TILESIZE); 
    drawImage(zero.pixel_data, zero.width, zero.height, 11*TILESIZE + TILESIZE/2, TILESIZE+4); // 0 score at the start. 
    drawImage(meso.pixel_data, meso.width, meso.height, 13*TILESIZE - TILESIZE/4, TILESIZE);
    
    drawImage(time.pixel_data, time.width, time.height, 16*TILESIZE, TILESIZE); 
    // Time 300s at start initially. 
    drawImage(timeThree.pixel_data, timeThree.width, timeThree.height, 18*TILESIZE + TILESIZE/2, TILESIZE); 
    drawImage(timeZero.pixel_data, timeZero.width, timeZero.height, 19*TILESIZE-10 +  TILESIZE/2, TILESIZE); 
    drawImage(timeZero.pixel_data, timeZero.width, timeZero.height, 20*TILESIZE-20 + TILESIZE/2, TILESIZE); 
    drawImage(seconds.pixel_data, seconds.width, seconds.height, 21*TILESIZE-30 + TILESIZE/2, TILESIZE); 
}

void updateUI()
{
    // Update lives
    if (state.lives == 0)
    {
        drawImage(noLives.pixel_data, noLives.width, noLives.height, 4*TILESIZE, TILESIZE);
    }
    else if (state.lives == 1)
    {
        drawImage(halfLife.pixel_data, halfLife.width, halfLife.height, 4*TILESIZE, TILESIZE);
    }
    else if (state.lives == 2)
    {
        drawImage(oneLife.pixel_data, oneLife.width, oneLife.height, 4*TILESIZE, TILESIZE);
    }
    else if (state.lives == 3)
    {
        drawImage(oneHalfLife.pixel_data, oneHalfLife.width, oneHalfLife.height, 4*TILESIZE, TILESIZE);
    }
    else if (state.lives == 4)
    {
        drawImage(twoLives.pixel_data, twoLives.width, twoLives.height, 4*TILESIZE, TILESIZE);
    }
    else if (state.lives == 5)
    {
        drawImage(twoHalfLife.pixel_data, twoHalfLife.width, twoHalfLife.height, 4*TILESIZE, TILESIZE);
    }
    else if (state.lives == 6)
    {
        drawImage(threeLives.pixel_data, threeLives.width, threeLives.height, 4*TILESIZE, TILESIZE);
    }

    // Update score
    if (state.score == 1)
    {
        drawImage(one.pixel_data, one.width, one.height, 11*TILESIZE + TILESIZE/2, TILESIZE+4);
    }
    else if (state.score == 2)
    {
        drawImage(two.pixel_data, two.width, two.height, 11*TILESIZE + TILESIZE/2, TILESIZE+4);
    }
    else if (state.score == 3)
    {
        drawImage(three.pixel_data, three.width, three.height, 11*TILESIZE + TILESIZE/2, TILESIZE+4);
    }
    else if (state.score == 4)
    {
        drawImage(four.pixel_data, four.width, four.height, 11*TILESIZE + TILESIZE/2, TILESIZE+4);
    }
    else if (state.score == 5)
    {
        drawImage(five.pixel_data, five.width, five.height, 11*TILESIZE + TILESIZE/2, TILESIZE+4);
    }
    else if (state.score == 6)
    {
        drawImage(six.pixel_data, six.width, six.height, 11*TILESIZE + TILESIZE/2, TILESIZE+4);
    }
    else if (state.score == 7)
    {
        drawImage(seven.pixel_data, seven.width, seven.height, 11*TILESIZE + TILESIZE/2, TILESIZE+4);
    }
    else if (state.score == 8)
    {
        drawImage(eight.pixel_data, eight.width, eight.height, 11*TILESIZE + TILESIZE/2, TILESIZE+4);
    }
    else if (state.score == 9)
    {
        drawImage(nine.pixel_data, nine.width, nine.height, 11*TILESIZE + TILESIZE/2, TILESIZE+4);
    }
    else if (state.score == 10)
    {
        drawImage(ten.pixel_data, ten.width, ten.height, 11*TILESIZE + TILESIZE/2, TILESIZE+4);
    }


    // Update time
    int ones = state.timeRem % 10;
    int tens = (state.timeRem/10) % 10;
    int hundreds = (state.timeRem/100) % 10;

    if (hundreds == 0)
    {
        drawImage(timeZero.pixel_data, timeZero.width, timeZero.height, 18*TILESIZE + TILESIZE/2, TILESIZE); 
    }
    else if (hundreds == 1)
    {
        drawImage(timeOne.pixel_data, timeOne.width, timeOne.height, 18*TILESIZE + TILESIZE/2, TILESIZE); 
    }
    else if (hundreds == 2)
    {
        drawImage(timeTwo.pixel_data, timeTwo.width, timeTwo.height, 18*TILESIZE + TILESIZE/2, TILESIZE); 
    }
    else if (hundreds == 3)
    {
        drawImage(timeThree.pixel_data, timeThree.width, timeThree.height, 18*TILESIZE + TILESIZE/2, TILESIZE); 
    }
    else if (hundreds == 4)
    {
        drawImage(timeFour.pixel_data, timeFour.width, timeFour.height, 18*TILESIZE + TILESIZE/2, TILESIZE); 
    }
    else if (hundreds == 5)
    {
        drawImage(timeFive.pixel_data, timeFive.width, timeFive.height, 18*TILESIZE + TILESIZE/2, TILESIZE); 
    }
    else if (hundreds == 6)
    {
        drawImage(timeSix.pixel_data, timeSix.width, timeSix.height, 18*TILESIZE + TILESIZE/2, TILESIZE); 
    }
    else if (hundreds == 7)
    {
        drawImage(timeSeven.pixel_data, timeSeven.width, timeSeven.height, 18*TILESIZE + TILESIZE/2, TILESIZE); 
    }
    else if (hundreds == 8)
    {
        drawImage(timeEight.pixel_data, timeEight.width, timeEight.height, 18*TILESIZE + TILESIZE/2, TILESIZE); 
    }
    else if (hundreds == 9)
    {
        drawImage(timeNine.pixel_data, timeNine.width, timeNine.height, 18*TILESIZE + TILESIZE/2, TILESIZE); 
    }

    if (tens == 0)
    {
        drawImage(timeZero.pixel_data, timeZero.width, timeZero.height, 19*TILESIZE-10 + TILESIZE/2, TILESIZE);
    }
    else if (tens == 1)
    {
        drawImage(timeOne.pixel_data, timeOne.width, timeOne.height, 19*TILESIZE-10 + TILESIZE/2, TILESIZE);
    }
    else if (tens == 2)
    {
        drawImage(timeTwo.pixel_data, timeTwo.width, timeTwo.height, 19*TILESIZE-10 + TILESIZE/2, TILESIZE); 
    }
    else if (tens == 3)
    {
        drawImage(timeThree.pixel_data, timeThree.width, timeThree.height, 19*TILESIZE-10 + TILESIZE/2, TILESIZE); 
    }
    else if (tens == 4)
    {
        drawImage(timeFour.pixel_data, timeFour.width, timeFour.height, 19*TILESIZE-10 + TILESIZE/2, TILESIZE); 
    }
    else if (tens == 5)
    {
        drawImage(timeFive.pixel_data, timeFive.width, timeFive.height, 19*TILESIZE-10 + TILESIZE/2, TILESIZE); 
    }
    else if (tens == 6)
    {
        drawImage(timeSix.pixel_data, timeSix.width, timeSix.height, 19*TILESIZE-10 + TILESIZE/2, TILESIZE); 
    }
    else if (tens == 7)
    {
        drawImage(timeSeven.pixel_data, timeSeven.width, timeSeven.height, 19*TILESIZE-10 + TILESIZE/2, TILESIZE); 
    }
    else if (tens == 8)
    {
        drawImage(timeEight.pixel_data, timeEight.width, timeEight.height, 19*TILESIZE-10 + TILESIZE/2, TILESIZE); 
    }
    else if (tens == 9)
    {
        drawImage(timeNine.pixel_data, timeNine.width, timeNine.height, 19*TILESIZE-10 + TILESIZE/2, TILESIZE); 
    }


    if (ones == 0)
    {
        drawImage(timeZero.pixel_data, timeZero.width, timeZero.height, 20*TILESIZE-20 + TILESIZE/2, TILESIZE); 
    }
    else if (ones == 1)
    {
        drawImage(timeOne.pixel_data, timeOne.width, timeOne.height, 20*TILESIZE-20 + TILESIZE/2, TILESIZE);
    }
    else if (ones == 2)
    {
        drawImage(timeTwo.pixel_data, timeTwo.width, timeTwo.height, 20*TILESIZE-20 + TILESIZE/2, TILESIZE); 
    }
    else if (ones == 3)
    {
        drawImage(timeThree.pixel_data, timeThree.width, timeThree.height, 20*TILESIZE-20 + TILESIZE/2, TILESIZE); 
    }
    else if (ones == 4)
    {
        drawImage(timeFour.pixel_data, timeFour.width, timeFour.height, 20*TILESIZE-20 + TILESIZE/2, TILESIZE); 
    }
    else if (ones == 5)
    {
        drawImage(timeFive.pixel_data, timeFive.width, timeFive.height, 20*TILESIZE-20 + TILESIZE/2, TILESIZE); 
    }
    else if (ones == 6)
    {
        drawImage(timeSix.pixel_data, timeSix.width, timeSix.height, 20*TILESIZE-20 + TILESIZE/2, TILESIZE); 
    }
    else if (ones == 7)
    {
        drawImage(timeSeven.pixel_data, timeSeven.width, timeSeven.height, 20*TILESIZE-20 + TILESIZE/2, TILESIZE); 
    }
    else if (ones == 8)
    {
        drawImage(timeEight.pixel_data, timeEight.width, timeEight.height, 20*TILESIZE-20 + TILESIZE/2, TILESIZE); 
    }
    else if (ones == 9)
    {
        drawImage(timeNine.pixel_data, timeNine.width, timeNine.height, 20*TILESIZE-20 + TILESIZE/2, TILESIZE); 
    }
}

void drawPauseMenu()
{
    struct Button restart, quit;
    restart.selected = TRUE;
    quit.selected = FALSE;

    drawImage(pauseMenu.pixel_data, pauseMenu.width, pauseMenu.height, 323, 120);
    drawImage(restartButton2.pixel_data, restartButton2.width, restartButton2.height, 323+55, 120+167);
    drawImage(pauseQuitButton.pixel_data, pauseQuitButton.width, pauseQuitButton.height, 323+51, 120+297);

    while (1)
    {
        pressedButtons = getSNES();
        if (!(pressedButtons >> 3 & 1))
        {
            drawMap();
            drawEntities();
            drawUI();
            updateUI();
            break;
        }
        if (!(pressedButtons >> 4 & 1) && quit.selected)
        {
            restart.selected = TRUE;
            quit.selected = FALSE;
            drawImage(restartButton2.pixel_data, restartButton2.width, restartButton2.height, 323+55, 120+167);
            drawImage(pauseQuitButton.pixel_data, pauseQuitButton.width, pauseQuitButton.height, 323+51, 120+297);   
        }
        else if (!(pressedButtons >> 5 & 1) && restart.selected)
        {
            restart.selected = FALSE;
            quit.selected = TRUE;
            drawImage(restartButton.pixel_data, restartButton.width, restartButton.height, 323+55, 120+167);
            drawImage(pauseQuitButton2.pixel_data, pauseQuitButton2.width, pauseQuitButton2.height, 323+51, 120+297);  
        }
        if(quit.selected && !(pressedButtons >> 8 & 1))
        {
            state.quit = TRUE;
            state.restart = FALSE;
            state.winFlag = FALSE;
            break;
        }
        else if(restart.selected && !(pressedButtons >> 8 & 1))
        {
            state.quit = FALSE;
            state.restart = TRUE;
            state.winFlag = TRUE;
            break;
        }
    }
}

<<<<<<< Updated upstream
=======
void drawTile(int x, int y)
{
    if(state.map[y][x] == 0)// Draw a regular background tile
    {
        if(state.level == 1)// Level 1, Grass level
        {
            drawImage(grass.pixel_data, grass.width, grass.height, x*TILESIZE, y*TILESIZE + MENUHEIGHT);
            drawRect(x*TILESIZE, y*TILESIZE + MENUHEIGHT, (x+1)*TILESIZE, (y+1)*TILESIZE + MENUHEIGHT, WHITE, 0);
        }
        else if(state.level == 2)// Level 2, Sand level
        {
            drawImage(sand.pixel_data, sand.width, sand.height, x*TILESIZE, y*TILESIZE + MENUHEIGHT);
            drawRect(x*TILESIZE, y*TILESIZE + MENUHEIGHT, (x+1)*TILESIZE, (y+1)*TILESIZE + MENUHEIGHT, WHITE, 0);
        }
    }
    else if(state.map[y][x] == 1)// Draw an obstical tile
    {
        if(state.level == 1)// Level 1, rock obsticle
        {
            drawImage(rock.pixel_data, rock.width, rock.height, x*TILESIZE, y*TILESIZE + MENUHEIGHT);
            drawRect(x*TILESIZE, y*TILESIZE + MENUHEIGHT, (x+1)*TILESIZE, (y+1)*TILESIZE + MENUHEIGHT, WHITE, 0);
        }
        else if(state.level == 2)// Level 2, water obsticle
        {
            drawImage(water.pixel_data, water.width, water.height, x*TILESIZE, y*TILESIZE + MENUHEIGHT);
            drawRect(x*TILESIZE, y*TILESIZE + MENUHEIGHT, (x+1)*TILESIZE, (y+1)*TILESIZE + MENUHEIGHT, WHITE, 0);
        }
    }
}

>>>>>>> Stashed changes
void drawMap()
{
    fillScreen(BACKGROUNDGREEN);

    for(int i = 0; i < (SCREENHEIGHT-MENUHEIGHT)/TILESIZE; i++)
    {
        for(int j = 0; j < SCREENWIDTH/TILESIZE; j++)
        {
            if(state.map[i][j] == 0)// Draw a regular background tile
            {
                drawImage(grass.pixel_data, grass.width, grass.height, j*TILESIZE, i*TILESIZE + MENUHEIGHT);
                drawRect(j*TILESIZE, i*TILESIZE + MENUHEIGHT, (j+1)*TILESIZE, (i+1)*TILESIZE + MENUHEIGHT, WHITE, 0);
            }
            else if(state.map[i][j] == 1)// Draw a rock background tile
            {
                drawImage(rock.pixel_data, rock.width, rock.height, j*TILESIZE, i*TILESIZE + MENUHEIGHT);
                drawRect(j*TILESIZE, i*TILESIZE + MENUHEIGHT, (j+1)*TILESIZE, (i+1)*TILESIZE + MENUHEIGHT, WHITE, 0);
            }
        }
    }
}

void drawEntities()
{
    for(int i = 0; i < (SCREENHEIGHT-MENUHEIGHT)/TILESIZE; i++)
    {
        for(int j = 0; j < SCREENWIDTH/TILESIZE; j++)
        {
            if(state.entities[i][j] == 1)// Draw a player entity
            {
                drawImage(snakeE.pixel_data, snakeE.width, snakeE.height, j*TILESIZE, i*TILESIZE + MENUHEIGHT);
                drawRect(j*TILESIZE, i*TILESIZE + MENUHEIGHT, (j+1)*TILESIZE, (i+1)*TILESIZE + MENUHEIGHT, WHITE, 0);
            }
            else if(state.entities[i][j] == 2)// Draw a apple entity
            {
                drawImage(apple.pixel_data, apple.width, apple.height, j*TILESIZE, i*TILESIZE + MENUHEIGHT);
                drawRect(j*TILESIZE, i*TILESIZE + MENUHEIGHT, (j+1)*TILESIZE, (i+1)*TILESIZE + MENUHEIGHT, WHITE, 0);
            }
            else if(state.entities[i][j] == 3)// Draw a coin entity
            {
                drawImage(coin.pixel_data, coin.width, coin.height, j*TILESIZE, i*TILESIZE + MENUHEIGHT);
                drawRect(j*TILESIZE, i*TILESIZE + MENUHEIGHT, (j+1)*TILESIZE, (i+1)*TILESIZE + MENUHEIGHT, WHITE, 0);
            }
            else if(state.entities[i][j] == 4)// Draw a invinsibility power up entity
            {
                drawImage(coin.pixel_data, coin.width, coin.height, j*TILESIZE, i*TILESIZE + MENUHEIGHT);
                drawRect(j*TILESIZE, i*TILESIZE + MENUHEIGHT, (j+1)*TILESIZE, (i+1)*TILESIZE + MENUHEIGHT, WHITE, 0);
            }
            else if(state.entities[i][j] == 5)// Draw a goal entity
            {
                drawImage(goal.pixel_data, goal.width, goal.height, j*TILESIZE, i*TILESIZE + MENUHEIGHT);
                drawRect(j*TILESIZE, i*TILESIZE + MENUHEIGHT, (j+1)*TILESIZE, (i+1)*TILESIZE + MENUHEIGHT, WHITE, 0);
            }
            else if(state.entities[i][j] >= 6 && state.entities[i][j] <= 11)// Draw a saw entity
            {
                drawImage(saw.pixel_data, saw.width, saw.height, j*TILESIZE, i*TILESIZE + MENUHEIGHT);
                drawRect(j*TILESIZE, i*TILESIZE + MENUHEIGHT, (j+1)*TILESIZE, (i+1)*TILESIZE + MENUHEIGHT, WHITE, 0);
            }
            else if(state.entities[i][j] >= 12 && state.entities[i][j] <= 15)// Draw a flame entity
            {
                drawImage(flame.pixel_data, flame.width, flame.height, j*TILESIZE, i*TILESIZE + MENUHEIGHT);
                drawRect(j*TILESIZE, i*TILESIZE + MENUHEIGHT, (j+1)*TILESIZE, (i+1)*TILESIZE + MENUHEIGHT, WHITE, 0);
            }
        }
    }
}

bool checkCollision(int entityIndex, int x, int y)
{
    // Check to see if a collision would occur when moving to position x, y
    if(state.map[y][x] != 0)
    {
        return TRUE;
    }
    // If lives are less than 4 when picking up an apple increase it by 1 and erase the apple
    else if(entityIndex == PLAYER && state.entities[y][x] == 2 && state.lives < 4)
    {
        state.lives += 1;
        state.entities[y][x] = 0;
        return FALSE;
    }
    // If lives are 4 increase the score by 5 and still erase the apple
    else if(entityIndex == PLAYER && state.entities[y][x] == 2 && state.lives >= 4)
    {
        state.score += 5;
        state.entities[y][x] = 0;
        return FALSE;
    }
    // When colliding with a coin increase score by 1 and erase the coin
    else if(entityIndex == PLAYER && state.entities[y][x] == 3)
    {
        state.score++;
        state.entities[y][x] = 0;
        return FALSE;
    }
    else if(state.entities[y][x] != 0)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }

}

void updatePlayer()
{
    int xCur, yCur;
    int xNew, yNew;

    // Update player
    for(int i = 0; i < (SCREENHEIGHT-MENUHEIGHT)/TILESIZE; i++)
    {
        for(int j = 0; j < SCREENWIDTH/TILESIZE; j++)
        {
            if(state.entities[i][j] == 1)// get player pos
            {
                xCur = j;
                yCur = i;

                if(!(pressedButtons >> 4 & 1) && yCur - 1 >= 0 && !checkCollision(PLAYER, xCur, yCur - 1))//Move up
                {
                    xNew = xCur;
                    yNew = yCur - 1;
                    //color background over old pos
                }
                else if(!(pressedButtons >> 5 & 1) && yCur + 1 < (SCREENHEIGHT-MENUHEIGHT)/TILESIZE && !checkCollision(PLAYER, xCur, yCur + 1))//Move down
                {
                    xNew = xCur;
                    yNew = yCur + 1;
                }
                else if(!(pressedButtons >> 6 & 1) && xCur - 1 >= 0 && !checkCollision(PLAYER, xCur - 1, yCur))//Move left
                {
                    xNew = xCur - 1;
                    yNew = yCur;
                }
                else if(!(pressedButtons >> 7 & 1) && xCur + 1 < SCREENWIDTH/TILESIZE && !checkCollision(PLAYER, xCur + 1, yCur))//Move right
                {
                    xNew = xCur + 1;
                    yNew = yCur;
                }
                else
                {
                    xNew = xCur;
                    yNew = yCur;
                }

                if(xNew != xCur || yNew != yCur)
                {
                    state.entities[yCur][xCur] = 0;
                    state.entities[yNew][xNew] = 1;
                    drawImage(grass.pixel_data, grass.width, grass.height, xCur*TILESIZE, yCur*TILESIZE + MENUHEIGHT);
                    drawRect(j*TILESIZE, i*TILESIZE + MENUHEIGHT, (j+1)*TILESIZE, (i+1)*TILESIZE + MENUHEIGHT, WHITE, 0);
                    return;
                }
                
            }
        }
    }
}

void updateSaws()
{
    int count = 0;

    for(int i = 0; i < (SCREENHEIGHT-MENUHEIGHT)/TILESIZE; i++)
    {
        for(int j = 0; j < SCREENWIDTH/TILESIZE; j++)
        {
           if(state.entities[i][j] >= 6 && state.entities[i][j] <= 8)//X direction saw
           {
                if(state.entities[i][j] == (count + SAWCOUNT))//dont update the same saw twice
                {
                    if(state.sawVel[count] == 1 )// Saw is moving to the right
                    {
                        if(!checkCollision(SAW, j, i+1))// Try to move saw right again
                        {
                            state.entities[i+1][j] = (count+SAWCOUNT);
                            state.entities[i][j] = 0;
                            drawImage(grass.pixel_data, grass.width, grass.height, j*TILESIZE, i*TILESIZE + MENUHEIGHT);
                            drawRect(j*TILESIZE, i*TILESIZE + MENUHEIGHT, (j+1)*TILESIZE, (i+1)*TILESIZE + MENUHEIGHT, WHITE, 0);
                        }
                        else
                        {
                            state.sawVel[count] = -1;
                        }
                    }
                    else// Saw is moving to the left
                    {
                        if(!checkCollision(SAW, j, i-1))// Try to move saw left again
                        {
                            state.entities[i-1][j] = (count+SAWCOUNT);
                            state.entities[i][j] = 0;
                            drawImage(grass.pixel_data, grass.width, grass.height, j*TILESIZE, i*TILESIZE + MENUHEIGHT);
                            drawRect(j*TILESIZE, i*TILESIZE + MENUHEIGHT, (j+1)*TILESIZE, (i+1)*TILESIZE + MENUHEIGHT, WHITE, 0);
                        }
                        else
                        {
                            state.sawVel[count] = 1;
                        }
                    }

                    count++;
                }
            }
            else if(state.entities[i][j] >= 9 && state.entities[i][j] <= 11)//Y direction saw
            {
                if(state.entities[i][j] == (count + SAWCOUNT))//dont update the same saw twice
                {
                    if(state.sawVel[count] == 1 )// Saw is moving to the down
                    {
                        if(!checkCollision(SAW, j+1, i))// Try to move saw down again
                        {
                            state.entities[i][j+1] = (count+SAWCOUNT);
                            state.entities[i][j] = 0;
                        }
                        else
                        {
                            state.sawVel[count] = -1;
                        }
                    }
                    else// Saw is moving to the up
                    {
                        if(!checkCollision(SAW, j-1, i))// Try to move saw up again
                        {
                            state.entities[i][j-1] = (count+SAWCOUNT);
                            state.entities[i][j] = 0;
                        }
                        else
                        {
                            state.sawVel[count] = 1;
                        }
                    }

                    count++;
                }
            }
        }
    }
}

void updateFlames()
{

}

unsigned getTime()
{
    unsigned *clo = (unsigned*)CLO_REG;
    unsigned c = *clo;
    return c;
}

void updateTimeRem()
{   
    unsigned deltaT = getTime() - oldTime;
    oldTime = getTime();
    state.timeRem -= deltaT/1000;
    //intToString(state.timeRem);
}

void menu();
void level1();
void level2();

int main()
{
    /////////////////////////////////Initialize////////////////////////////////

    init_framebuffer(); // You can use framebuffer, width, height and pitch variables available in framebuffer.h
    width = SCREENWIDTH;
    height = SCREENHEIGHT;
    fillScreen(BACKGROUNDGREEN);
    
    initSNES();

    state.restart == FALSE; 
    state.quit == FALSE; 
    ///////////////////////////////////////////////////////////////////////////
    while(1)
    {
        menu();
        if(state.winFlag == FALSE)
        {
            break;
        }
        // else if (state.winFlag == TRUE)
        // {
        //     endMenu();
        // }
        
        oldTime = getTime(); // Take note of when the level was started.
        //intToString(oldTime); // Remove before submission. Just seeing what the clock prints. 
        level1();
        if(state.restart == TRUE)
        {
            state.restart == FALSE; 
            level1();
        }
        else if (state.quit == TRUE)
        {
            state.quit == FALSE;
        }

        oldTime = (unsigned)CLO_REG; // Take note of when the level was started.
        // if(!level2())
        // {
        //     continue;
        // }

    }

    fillScreen(0);
    
    return 0;
}

void menu()
{
    struct Button start, quit;
    start.selected = TRUE;
    quit.selected = FALSE;
    drawImage(startScreen.pixel_data, startScreen.width, startScreen.height, 0, 0);
    drawImage(startButton2.pixel_data, startButton2.width, startButton2.height, 180, 424);
    drawImage(quitButton.pixel_data, quitButton.width, quitButton.height, 185, 548);

    // Refresh/Initilize game state
<<<<<<< Updated upstream
    state.lives = 4;
=======
    state.lives = 6;
>>>>>>> Stashed changes
    state.score = 0;
    state.timeRem = 300000; // 5 minutes = 300 seconds = 300000 milliseconds.
    state.winFlag = FALSE;

    while(1)
    {
        pressedButtons =  getSNES();

        if(!(pressedButtons >> 4 & 1) && quit.selected)
        {
            start.selected = TRUE;
            quit.selected = FALSE;
            drawImage(startButton2.pixel_data, startButton2.width, startButton2.height, 180, 424);
            drawImage(quitButton.pixel_data, quitButton.width, quitButton.height, 185, 548);
        }
        else if(!(pressedButtons >> 5 & 1) && start.selected)
        {
            start.selected = FALSE;
            quit.selected = TRUE;
            drawImage(startButton.pixel_data, startButton.width, startButton.height, 186, 428);
            drawImage(quitButton2.pixel_data, quitButton2.width, quitButton2.height, 186, 546);
        }

        if(quit.selected && !(pressedButtons >> 8 & 1))
        {
            state.winFlag = FALSE;
            break;
        }
        else if(start.selected && !(pressedButtons >> 8 & 1))
        {
            state.winFlag = TRUE;
            break;
        }
    }
}

void endMenu()
{
    drawImage(gameOver.pixel_data, gameOver.width, gameOver.height, 396, 300);
}

void level1()
{
    state.winFlag = FALSE;

    // Store the levelone map in the state map.
    for(int i = 0; i < (SCREENHEIGHT-MENUHEIGHT)/TILESIZE; i++)
    {
        for(int j = 0; j < SCREENWIDTH/TILESIZE; j++)
        {
            state.map[i][j] = level1Map[i][j];
        }
    }

    // Store the levelone entites in the state entites.
    for(int i = 0; i < (SCREENHEIGHT-MENUHEIGHT)/TILESIZE; i++)
    {
        for(int j = 0; j < SCREENWIDTH/TILESIZE; j++)
        {
            state.entities[i][j] = level1Entities[i][j];
        }
    }

    // Set saw enemy velocities
    for(int i = 0; i < SAWCOUNT; i++)
    {
        state.sawVel[i] = 1;
    }
    
    // Draw the map state
    drawMap();
    drawUI();
    drawEntities();

<<<<<<< Updated upstream
    while(1)
=======
    //while(getSNES() >> 3 & 1); // Wait for start button to be pressed before starting the game.

    while(state.lives > 0 && state.winFlag == FALSE && state.timeRem > 0)
>>>>>>> Stashed changes
    {
        pressedButtons = getSNES();// Get current button state to update game state.
        updatePlayer();
        updateSaws();
        updateUI();
        updateTimeRem();
        drawEntities();
        for(int i = 0; i < 10000; i++)
            wait(TICKTIME);

        if (!(pressedButtons >> 3 & 1))
        {
            drawPauseMenu();
        }
        if (state.restart == TRUE)
        {
            break;
        }
        else if (state.quit == TRUE)
        {
            break;
        }
    }
}

// enum bool level2()
// {

// }