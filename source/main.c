#include "gpio.h"
#include "uart.h"
#include "framebuffer.h"
#include "controllerDriver.h"
#include "random.h"

////////////////////////////////////Images/////////////////////////////////////
#include "UI_Elements/startButtonYellow.h"
#include "UI_Elements/startButtonGrey.h"
#include "UI_Elements/exitButtonYellow.h"
#include "UI_Elements/exitButtonGrey.h"

#include "UI_Elements/noLives.h"
#include "UI_Elements/oneLife.h"
#include "UI_Elements/twoLives.h"
#include "UI_Elements/threeLives.h"
#include "UI_Elements/lives.h"
#include "UI_Elements/score.h"
#include "UI_Elements/meso.h"
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
#include "EntityAssets/potion.h"
#include "EntityAssets/snakeEInv.h"
#include "EntityAssets/snakeNInv.h"
#include "EntityAssets/snakeSInv.h"
#include "EntityAssets/snakeWInv.h"
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
#define TICKTIME 10 //microseconds "this is broken???"
#define FRAMETIME 1000000 // frame time in microseconds. Frequency of game refresh.
#define SAWCOUNT 6
#define FLAMECOUNT 4
#define INVINCIBILEDURATION 100 //game ticks of invincibility.

// Entity indices
#define PLAYER 1
#define APPLE 2
#define COIN 3
#define POTION 4
#define GOAL 5
#define SAW 6
#define FLAME 7

/*
* Screen size 1280x720.
* Number of horizontal cells (1024/32 = 32).
* Number of vertical cells (640/32 = 20).
* 80 extra pixels on the top for game status.
*/

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

int level1Map[20][32]     ={{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0},
                            {0,0,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0},
                            {0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,1,0,1,0,0,0,0,0,1,1,1,1,1,1,1,1},
                            {0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0},
                            {0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,1,1,1,1,1,1,1,0,0,1,0,0,0,0,0,0,0},
                            {1,1,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0},
                            {1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0},
                            {0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0},
                            {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0},
                            {0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};

int level1Entities[20][32]={{0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,10,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,14,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {3,3,0,0,0,0,0,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0},
                            {3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,3,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,12,0,3,0,13,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,3,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,0,0,15,0,0,0},
                            {8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};

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
    bool invincible;
    int invincibleTime;
    bool winFlag;
    
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

void updateTimeRem(int frameTime)
{   
    state.timeRem -= frameTime;
}

void intToString(int n)
{
    // Taken from the internet, just for seeing what the clock value is. REMOVE BEFORE SUBMISSION. 
    char buffer[50];
    int i = 0;

    bool isNeg = n<0;

    unsigned int n1 = isNeg ? -n : n;

    while(n1!=0)
    {
        buffer[i++] = n1%10+'0';
        n1=n1/10;
    }

    if(isNeg)
        buffer[i++] = '-';

    buffer[i] = '\0';

    for(int t = 0; t < i/2; t++)
    {
        buffer[t] ^= buffer[i-t-1];
        buffer[i-t-1] ^= buffer[t];
        buffer[t] ^= buffer[i-t-1];
    }

    if(n == 0)
    {
        buffer[0] = '0';
        buffer[1] = '\0';
    }   

    printf(buffer);
    printf("\n");
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
        drawImage(oneLife.pixel_data, oneLife.width, oneLife.height, 4*TILESIZE, TILESIZE);
    }
    else if (state.lives == 2)
    {
        drawImage(twoLives.pixel_data, twoLives.width, twoLives.height, 4*TILESIZE, TILESIZE);
    }
    else if (state.lives == 3)
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
    int ones = (state.timeRem/1000000) % 10;
    int tens = (state.timeRem/10000000) % 10;
    int hundreds = (state.timeRem/100000000) % 10;

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

void pauseMenu()
{
    /*
    In the game loop where all the stuff is updated, check if the start button has been pressed and if it has draw the 
    pause menu over the game and loop until the start button is pressed again. 
    Then when the start button is pressed again redraw the map and entities and return to the game loop
    */


}

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
            if(state.entities[i][j] == 1 && state.invincible == FALSE)// Draw a player entity
            {
                drawImage(snakeE.pixel_data, snakeE.width, snakeE.height, j*TILESIZE, i*TILESIZE + MENUHEIGHT);
                drawRect(j*TILESIZE, i*TILESIZE + MENUHEIGHT, (j+1)*TILESIZE, (i+1)*TILESIZE + MENUHEIGHT, WHITE, 0);
            }
            else if(state.entities[i][j] == 1 && state.invincible == TRUE)
            {
                drawImage(snakeEInv.pixel_data, snakeEInv.width, snakeEInv.height, j*TILESIZE, i*TILESIZE + MENUHEIGHT);
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
                drawImage(potion.pixel_data, potion.width, potion.height, j*TILESIZE, i*TILESIZE + MENUHEIGHT);
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
    // If lives are less than 4 when picking up an apple increse it by 1 and erase the apple
    else if(entityIndex == PLAYER && state.entities[y][x] == APPLE && state.lives < 3)
    {
        state.lives += 1;
        state.entities[y][x] = 0;
        return FALSE;
    }
    // If lives are 4 increse the score by 5 and still erase the apple
    else if(entityIndex == PLAYER && state.entities[y][x] == APPLE && state.lives >= 3)
    {
        state.score += 2;
        state.entities[y][x] = 0;
        return FALSE;
    }
    // When colliding with a coin increase score by 1 and erase the coin
    else if(entityIndex == PLAYER && state.entities[y][x] == COIN)
    {
        state.score++;
        state.entities[y][x] = 0;
        return FALSE;
    }
    // When colliding with a potion increase score by 1 and erase the potion
    else if(entityIndex == PLAYER && state.entities[y][x] == POTION)
    {
        state.invincible = TRUE;
        state.invincibleTime = INVINCIBILEDURATION;
        state.entities[y][x] = 0;
        return FALSE;
    }
    else if(entityIndex == PLAYER && (state.entities[y][x] >= 6 && state.entities[y][x] <= 15) && state.invincible == FALSE)
    {
        state.lives--;
        return TRUE;

    }
    else if(entityIndex == PLAYER && (state.entities[y][x] >= 12 && state.entities[y][x] <= 15) && state.invincible == TRUE)
    {
        state.entities[y][x] = 0;
        return FALSE;
    }
    else if(entityIndex == SAW && state.entities[y][x] == PLAYER && state.invincible == FALSE)
    {
        state.lives--;
        return TRUE;
    }
    else if(entityIndex == FLAME && state.entities[y][x] == PLAYER && state.invincible == FALSE)
    {
        state.lives--;
        return TRUE;
    }
    else if(entityIndex == PLAYER && state.entities[y][x] == GOAL)
    {
        state.winFlag = TRUE;
        return TRUE;
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

    if(state.invincibleTime <= 0)
    {
        state.invincible = FALSE;
    }
    else
    {
        state.invincibleTime -= 1;
    }

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
    int updated[SAWCOUNT] = {0,0,0,0,0,0};
    int index;

    for(int i = 0; i < (SCREENHEIGHT-MENUHEIGHT)/TILESIZE; i++)
    {
        for(int j = 0; j < SCREENWIDTH/TILESIZE; j++)
        {
           if(state.entities[i][j] >= 6 && state.entities[i][j] <= 8)//X direction saw
           {
                index = state.entities[i][j] - 6;
                if(updated[index] == 0)//dont update the same saw twice
                {
                    if(state.sawVel[index] == 1 )// Saw is moving to the right
                    {
                        if(!checkCollision(SAW, j+1, i) && j+1 < SCREENWIDTH/TILESIZE)// Try to move saw right again
                        {
                            state.entities[i][j+1] = state.entities[i][j];
                            state.entities[i][j] = 0;
                            drawImage(grass.pixel_data, grass.width, grass.height, j*TILESIZE, i*TILESIZE + MENUHEIGHT);
                            drawRect(j*TILESIZE, i*TILESIZE + MENUHEIGHT, (j+1)*TILESIZE, (i+1)*TILESIZE + MENUHEIGHT, WHITE, 0);
                        }
                        else
                        {
                            state.sawVel[index] = -1;
                        }
                    }
                    else// Saw is moving to the left
                    {
                        if(!checkCollision(SAW, j-1, i) && j-1 >= 0)// Try to move saw left again
                        {
                            state.entities[i][j-1] = state.entities[i][j];
                            state.entities[i][j] = 0;
                            drawImage(grass.pixel_data, grass.width, grass.height, j*TILESIZE, i*TILESIZE + MENUHEIGHT);
                            drawRect(j*TILESIZE, i*TILESIZE + MENUHEIGHT, (j+1)*TILESIZE, (i+1)*TILESIZE + MENUHEIGHT, WHITE, 0);
                        }
                        else
                        {
                            state.sawVel[index] = 1;
                        }
                    }

                    updated[index] = 1;
                }
            }
            else if(state.entities[i][j] >= 9 && state.entities[i][j] <= 11)//Y direction saw
           {
                index = state.entities[i][j] - 6;
                if(updated[index] == 0)//dont update the same saw twice
                {
                    if(state.sawVel[index] == 1 )// Saw is moving to the down
                    {
                        if(!checkCollision(SAW, j, i+1) && i+1 < SCREENWIDTH/TILESIZE)// Try to move saw down again
                        {
                            state.entities[i+1][j] = state.entities[i][j];
                            state.entities[i][j] = 0;
                            drawImage(grass.pixel_data, grass.width, grass.height, j*TILESIZE, i*TILESIZE + MENUHEIGHT);
                            drawRect(j*TILESIZE, i*TILESIZE + MENUHEIGHT, (j+1)*TILESIZE, (i+1)*TILESIZE + MENUHEIGHT, WHITE, 0);
                        }
                        else
                        {
                            state.sawVel[index] = -1;
                        }
                    }
                    else// Saw is moving to the up
                    {
                        if(!checkCollision(SAW, j, i-1) && i-1 >= 0)// Try to move saw up again
                        {
                            state.entities[i-1][j] = state.entities[i][j];
                            state.entities[i][j] = 0;
                            drawImage(grass.pixel_data, grass.width, grass.height, j*TILESIZE, i*TILESIZE + MENUHEIGHT);
                            drawRect(j*TILESIZE, i*TILESIZE + MENUHEIGHT, (j+1)*TILESIZE, (i+1)*TILESIZE + MENUHEIGHT, WHITE, 0);
                        }
                        else
                        {
                            state.sawVel[index] = 1;
                        }
                    }

                    updated[index] = 1;
                }
            }
        }
    }
}

void updateFlames()
{
    int updated[FLAMECOUNT] = {0,0,0,0};
    int index;

    int xNew, yNew;

    for(int i = 0; i < (SCREENHEIGHT-MENUHEIGHT)/TILESIZE; i++)
    {
        for(int j = 0; j < SCREENWIDTH/TILESIZE; j++)
        {
            if(state.entities[i][j] >= 12 && state.entities[i][j] <= 15)
           {
                index = state.entities[i][j] - 12;
                if(updated[index] == 0 )// Flame has been updated
                {

                    switch (rand()*(rand()/rand())%4)// An attempt to make random numbers....
                    {
                    case 0:
                        yNew = i+1;
                        xNew = j;
                        break;

                    case 1:
                        yNew = i;
                        xNew = j+1;
                        break;

                    case 2:
                        yNew = i-1;
                        xNew = j;
                        break;

                    case 3:
                        yNew = i;
                        xNew = j-1;
                        break;
                    
                    default:
                        break;
                    }
                    if(xNew < SCREENWIDTH/TILESIZE && yNew < (SCREENHEIGHT-MENUHEIGHT)/TILESIZE
                        && xNew >= 0 && yNew >= 0)
                    {
                        if(!checkCollision(FLAME, xNew, yNew))
                        {
                        state.entities[yNew][xNew] = state.entities[i][j];
                        state.entities[i][j] = 0;
                        drawImage(grass.pixel_data, grass.width, grass.height, j*TILESIZE, i*TILESIZE + MENUHEIGHT);
                        drawRect(j*TILESIZE, i*TILESIZE + MENUHEIGHT, (j+1)*TILESIZE, (i+1)*TILESIZE + MENUHEIGHT, WHITE, 0);
                        }
                    }
                    

                    updated[index] = 1;
                }
           }
        }
    }
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

    ///////////////////////////////////////////////////////////////////////////
    while(1)
    {
        menu();
        if(state.winFlag == FALSE)
        {
            break;
        }
        
        level1();
        if(state.winFlag == FALSE)
        {
            continue;
        }

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
    struct Button startButton, quitButton;
    startButton.selected = TRUE;
    quitButton.selected = FALSE;
    drawImage(startButtonGrey.pixel_data, startButtonGrey.width, startButtonGrey.height, 200, 200);
    drawImage(exitButtonYellow.pixel_data, exitButtonYellow.width, exitButtonYellow.height, 200, 300 + exitButtonYellow.height);

    // Refresh/Initilize game state
    state.lives = 3;
    state.score = 0;
    state.timeRem = 300000000; // 5 minutes = 300 seconds = 300000 milliseconds.
    state.invincible = FALSE;
    state.winFlag = FALSE;


    while(1)
    {
        pressedButtons =  getSNES();

        if(!(pressedButtons >> 4 & 1) && quitButton.selected)
        {
            startButton.selected = TRUE;
            quitButton.selected = FALSE;
            drawImage(startButtonGrey.pixel_data, startButtonGrey.width, startButtonGrey.height, 200, 200);
            drawImage(exitButtonYellow.pixel_data, exitButtonYellow.width, exitButtonYellow.height, 200, 300 + exitButtonYellow.height);
            
        }
        else if(!(pressedButtons >> 5 & 1) && startButton.selected)
        {
            startButton.selected = FALSE;
            quitButton.selected = TRUE;
            drawImage(startButtonYellow.pixel_data, startButtonYellow.width, startButtonYellow.height, 200, 200);
            drawImage(exitButtonGrey.pixel_data, exitButtonGrey.width, exitButtonGrey.height, 200, 300 + exitButtonGrey.height);
            
        }

        if(quitButton.selected && !(pressedButtons >> 8 & 1))
        {
            state.winFlag = FALSE;
            break;
        }
        else if(startButton.selected && !(pressedButtons >> 8 & 1))
        {
            state.winFlag = TRUE;
            break;
        }
    }
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

    while(getSNES() >> 3 & 1); // Wait for start button to be pressed before starting the game.

    while(state.lives > 0 && state.winFlag == FALSE && state.timeRem > 0)
    {
        pressedButtons =  getSNES();// Get current button state to update game state.
        updatePlayer();
        updateSaws();
        updateFlames();
        updateUI();
        drawEntities();
        // The wait function only works reliably for small time values so run it multiple
        // times instead of using a larger value.
        for(int i = 0; i < FRAMETIME/100; i++)
            wait(1);
        updateTimeRem(FRAMETIME/10); // I lost a fact of 10 somewhere so this is divided by 10.
    }
}

// enum bool level2()
// {

// }