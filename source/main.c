/*
Description: An adventure version of snake as described in assignment 4.
             This was a hard assignment but a fun one. We only had time during
             the easter break to work on this so the following is our 
             best attempt given the time constraints. I hope you enjoy and 
             appreciate our attempt at a "snake" game.
             The apples increase hp or score if you have full hp.
             The coins increse score. The water bottle gives invinsibility.
             The flags are the goals. The disks are saws that can damage the
             player. The flames (with faces) are fire enemies that can also damage the player.
             They slowly move around the map at random. (The random numbers are not the most
             random given the nature of randomness, but is our attempt at doing so).

Instructions:
             After selecting start, pressing the start button should start the level. 
             However, the controller is a bit sensitive to the start button. 
             It may also bring up the pause menu if pressed too slowly. 
             Simply press start again to exit the pause menu and continue the game. 
             Pressing the start button during the gameplay will bring up the pause menu.

Authors:
Zachary Kokot (UCID: 30115582)
Rainbow Peng (UCID: 30113718)

*/
#include "gpio.h"
#include "uart.h"
#include "framebuffer.h"
#include "controllerDriver.h"
#include "random.h"

////////////////////////////////////Images/////////////////////////////////////
#include "UI_Elements/startButton.h"
#include "UI_Elements/startButton2.h"
#include "UI_Elements/quitButton.h"
#include "UI_Elements/quitButton2.h"
#include "UI_Elements/won.h"
#include "UI_Elements/lose.h"

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

#include "UI_Elements/scoreZero.h"
#include "UI_Elements/scoreOne.h"
#include "UI_Elements/scoreTwo.h"
#include "UI_Elements/scoreThree.h"
#include "UI_Elements/scoreFour.h"
#include "UI_Elements/scoreFive.h"
#include "UI_Elements/scoreSix.h"
#include "UI_Elements/scoreSeven.h"
#include "UI_Elements/scoreEight.h"
#include "UI_Elements/scoreNine.h"

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


#include "EntityAssets/grass.h"
#include "EntityAssets/sand.h"
#include "EntityAssets/rock.h"
#include "EntityAssets/water.h"
#include "EntityAssets/apple.h"
#include "EntityAssets/apple2.h"
#include "EntityAssets/coin.h"
#include "EntityAssets/coin2.h"
#include "EntityAssets/goal.h"
#include "EntityAssets/goal2.h"
#include "EntityAssets/flame.h"
#include "EntityAssets/flame2.h"
#include "EntityAssets/saw.h"
#include "EntityAssets/saw2.h"
#include "EntityAssets/snakeE.h"
#include "EntityAssets/snake2E.h"
#include "EntityAssets/snakeN.h"
#include "EntityAssets/snakeS.h"
#include "EntityAssets/snakeW.h"
#include "EntityAssets/potion.h"
#include "EntityAssets/potion2.h"
#include "EntityAssets/snakeEInv.h"
#include "EntityAssets/snake2EInv.h"
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
#define SCORECONSTANT 2 // Constant to multiple score by. 
#define SCOREOFFSET_ONESX 280 // Offset for score pngs. 
#define SCOREOFFSETY 290
#define SCOREOFFSET_TENSX 240
#define SCOREOFFSET_HUNDREDSX 200
#define ENDMENUPOS_X 259
#define ENDMENUPOS_Y 184
#define MAXHEALTH 6 // Maximum number of hearts.

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
int displayTime = 300;

/*
* An empty entite or normal background tile is indicated by 0
* Map:
* 1 = Rock/water
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

int level1Map[20][32]     ={{0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0},
                            {0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,1,0,0,1,1,1,1,1,0,0,1,0,0,1,1,1,1},
                            {0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0},
                            {1,1,1,1,1,1,1,0,0,1,0,0,1,1,1,1,0,0,1,0,0,1,1,1,1,1,1,1,1,1,0,0},
                            {0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0},
                            {1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,0,0,0},
                            {0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0},
                            {0,0,0,0,1,1,1,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0},
                            {0,0,0,0,1,0,0,0,0,1,0,0,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,1,1,1,0,0},
                            {1,1,0,0,1,0,0,1,1,1,0,0,1,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0},
                            {0,0,0,0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0},
                            {0,0,0,0,1,0,0,0,0,1,0,0,1,0,0,1,1,1,0,0,1,0,0,1,0,0,1,1,1,1,1,1},
                            {0,0,0,0,1,1,1,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0}};

int level1Entities[20][32]={{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,0,0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,3,3,0,0,0,0,0,0,0,0,0,0,5},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,8,0,0,0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {1,0,0,0,0,0,0,0,0,0,9,0,0,0,0,0,0,12,0,0,0,0,0,0,13,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,14,0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {0,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {0,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,2,0,0,0,0,0,10,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2}};

int level2Map[20][32]     ={{0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0},
                            {1,1,1,0,0,0,1,0,0,1,1,1,1,1,0,0,1,1,1,1,1,0,0,1,0,0,1,1,1,1,0,0},
                            {0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0},
                            {0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0},
                            {0,0,1,1,1,0,1,1,1,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,1,1},
                            {0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0},
                            {0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0},
                            {1,1,1,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0},
                            {0,0,0,0,1,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0},
                            {0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0},
                            {1,1,1,1,1,1,0,0,0,0,1,0,0,1,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,1,1,1,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,1,1,1,1,1,1},
                            {0,0,1,0,0,1,0,0,0,0,1,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0},
                            {0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
                            {0,0,1,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,1,1,1,1,1,0,0,1,0,0,0,0,0},
                            {0,0,1,1,1,1,1,1,1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,1,0,0,1,1,1,1,1,1},
                            {0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0}};

int level2Entities[20][32]={{0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0,11,0,0,0,0,0,12,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,13,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,14,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {0,9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,3,3,0,0,0,7,0,0,0,0,0,0,0,3,3,0,0,0,0,0,0,0,0,0,0,0},
                           {10,0,0,0,0,0,3,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2}};

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
    int level;
    bool stateChange;
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

void updateTimeRem(int frameTime)
{   
    state.timeRem -= frameTime;
}

void updateScore()
{
    state.score = state.score + (state.timeRem/1000000) + SCORECONSTANT*state.lives; 
}

void winMenu()
{
    drawImage(won.pixel_data, won.width, won.height, ENDMENUPOS_X, ENDMENUPOS_Y);
    updateScore();

    int ones = (state.score) % 10;
    int tens = (state.score)/10 % 10;
    int hundreds = (state.score)/100 % 10;

    if (hundreds == 0)
    {
        drawImage(scoreZero.pixel_data, scoreZero.width, scoreZero.height, ENDMENUPOS_X+SCOREOFFSET_HUNDREDSX, ENDMENUPOS_Y+SCOREOFFSETY); 
    }
    else if (hundreds == 1)
    {
        drawImage(scoreOne.pixel_data, scoreOne.width, scoreOne.height, ENDMENUPOS_X+SCOREOFFSET_HUNDREDSX, ENDMENUPOS_Y+SCOREOFFSETY); 
    }
    else if (hundreds == 2)
    {
        drawImage(scoreTwo.pixel_data, scoreTwo.width, scoreTwo.height, ENDMENUPOS_X+SCOREOFFSET_HUNDREDSX, ENDMENUPOS_Y+SCOREOFFSETY); 
    }
    else if (hundreds == 3)
    {
        drawImage(scoreThree.pixel_data, scoreThree.width, scoreThree.height, ENDMENUPOS_X+SCOREOFFSET_HUNDREDSX, ENDMENUPOS_Y+SCOREOFFSETY); 
    }
    else if (hundreds == 4)
    {
        drawImage(scoreFour.pixel_data, scoreFour.width, scoreFour.height, ENDMENUPOS_X+SCOREOFFSET_HUNDREDSX, ENDMENUPOS_Y+SCOREOFFSETY); 
    }
    else if (hundreds == 5)
    {
        drawImage(scoreFive.pixel_data, scoreFive.width, scoreFive.height, ENDMENUPOS_X+SCOREOFFSET_HUNDREDSX, ENDMENUPOS_Y+SCOREOFFSETY); 
    }
    else if (hundreds == 6)
    {
        drawImage(scoreSix.pixel_data, scoreSix.width, scoreSix.height, ENDMENUPOS_X+SCOREOFFSET_HUNDREDSX, ENDMENUPOS_Y+SCOREOFFSETY); 
    }
    else if (hundreds == 7)
    {
        drawImage(scoreSeven.pixel_data, scoreSeven.width, scoreSeven.height, ENDMENUPOS_X+SCOREOFFSET_HUNDREDSX, ENDMENUPOS_Y+SCOREOFFSETY); 
    }
    else if (hundreds == 8)
    {
        drawImage(scoreEight.pixel_data, scoreEight.width, scoreEight.height, ENDMENUPOS_X+SCOREOFFSET_HUNDREDSX, ENDMENUPOS_Y+SCOREOFFSETY); 
    }
    else if (hundreds == 9)
    {
        drawImage(scoreNine.pixel_data, scoreNine.width, scoreNine.height, ENDMENUPOS_X+SCOREOFFSET_HUNDREDSX, ENDMENUPOS_Y+SCOREOFFSETY); 
    }

    if (tens == 0)
    {
        drawImage(scoreZero.pixel_data, scoreZero.width, scoreZero.height, ENDMENUPOS_X+SCOREOFFSET_TENSX, ENDMENUPOS_Y+SCOREOFFSETY); 
    }
    else if (tens == 1)
    {
        drawImage(scoreOne.pixel_data, scoreOne.width, scoreOne.height, ENDMENUPOS_X+SCOREOFFSET_TENSX, ENDMENUPOS_Y+SCOREOFFSETY); 
    }
    else if (tens == 2)
    {
        drawImage(scoreTwo.pixel_data, scoreTwo.width, scoreTwo.height, ENDMENUPOS_X+SCOREOFFSET_TENSX, ENDMENUPOS_Y+SCOREOFFSETY); 
    }
    else if (tens == 3)
    {
        drawImage(scoreThree.pixel_data, scoreThree.width, scoreThree.height, ENDMENUPOS_X+SCOREOFFSET_TENSX, ENDMENUPOS_Y+SCOREOFFSETY); 
    }
    else if (tens == 4)
    {
        drawImage(scoreFour.pixel_data, scoreFour.width, scoreFour.height, ENDMENUPOS_X+SCOREOFFSET_TENSX, ENDMENUPOS_Y+SCOREOFFSETY); 
    }
    else if (tens == 5)
    {
        drawImage(scoreFive.pixel_data, scoreFive.width, scoreFive.height, ENDMENUPOS_X+SCOREOFFSET_TENSX, ENDMENUPOS_Y+SCOREOFFSETY); 
    }
    else if (tens == 6)
    {
        drawImage(scoreSix.pixel_data, scoreSix.width, scoreSix.height, ENDMENUPOS_X+SCOREOFFSET_TENSX, ENDMENUPOS_Y+SCOREOFFSETY); 
    }
    else if (tens == 7)
    {
        drawImage(scoreSeven.pixel_data, scoreSeven.width, scoreSeven.height, ENDMENUPOS_X+SCOREOFFSET_TENSX, ENDMENUPOS_Y+SCOREOFFSETY); 
    }
    else if (tens == 8)
    {
        drawImage(scoreEight.pixel_data, scoreEight.width, scoreEight.height, ENDMENUPOS_X+SCOREOFFSET_TENSX, ENDMENUPOS_Y+SCOREOFFSETY); 
    }
    else if (tens == 9)
    {
        drawImage(scoreNine.pixel_data, scoreNine.width, scoreNine.height, ENDMENUPOS_X+SCOREOFFSET_TENSX, ENDMENUPOS_Y+SCOREOFFSETY); 
    }


    if (ones == 0)
    {
        drawImage(scoreZero.pixel_data, scoreZero.width, scoreZero.height, ENDMENUPOS_X+SCOREOFFSET_ONESX, ENDMENUPOS_Y+SCOREOFFSETY); 
    }
    else if (ones == 1)
    {
        drawImage(scoreOne.pixel_data, scoreOne.width, scoreOne.height, ENDMENUPOS_X+SCOREOFFSET_ONESX, ENDMENUPOS_Y+SCOREOFFSETY); 
    }
    else if (ones == 2)
    {
        drawImage(scoreTwo.pixel_data, scoreTwo.width, scoreTwo.height, ENDMENUPOS_X+SCOREOFFSET_ONESX, ENDMENUPOS_Y+SCOREOFFSETY); 
    }
    else if (ones == 3)
    {
        drawImage(scoreThree.pixel_data, scoreThree.width, scoreThree.height, ENDMENUPOS_X+SCOREOFFSET_ONESX, ENDMENUPOS_Y+SCOREOFFSETY); 
    }
    else if (ones == 4)
    {
        drawImage(scoreFour.pixel_data, scoreFour.width, scoreFour.height, ENDMENUPOS_X+SCOREOFFSET_ONESX, ENDMENUPOS_Y+SCOREOFFSETY); 
    }
    else if (ones == 5)
    {
        drawImage(scoreFive.pixel_data, scoreFive.width, scoreFive.height, ENDMENUPOS_X+SCOREOFFSET_ONESX, ENDMENUPOS_Y+SCOREOFFSETY); 
    }
    else if (ones == 6)
    {
        drawImage(scoreSix.pixel_data, scoreSix.width, scoreSix.height, ENDMENUPOS_X+SCOREOFFSET_ONESX, ENDMENUPOS_Y+SCOREOFFSETY); 
    }
    else if (ones == 7)
    {
        drawImage(scoreSeven.pixel_data, scoreSeven.width, scoreSeven.height, ENDMENUPOS_X+SCOREOFFSET_ONESX, ENDMENUPOS_Y+SCOREOFFSETY); 
    }
    else if (ones == 8)
    {
        drawImage(scoreEight.pixel_data, scoreEight.width, scoreEight.height, ENDMENUPOS_X+SCOREOFFSET_ONESX, ENDMENUPOS_Y+SCOREOFFSETY); 
    }
    else if (ones == 9)
    {
        drawImage(scoreNine.pixel_data, scoreNine.width, scoreNine.height, ENDMENUPOS_X+SCOREOFFSET_ONESX, ENDMENUPOS_Y+SCOREOFFSETY); 
    }

    pressedButtons = getSNES();
    while(getSNES() == 0b1111111111111111);  // Wait until any button is pressed. 
}

void loseMenu()
{
    drawImage(lose.pixel_data, lose.width, lose.height, ENDMENUPOS_X, ENDMENUPOS_Y);
    updateScore();

    int ones = (state.score) % 10;
    int tens = (state.score)/10 % 10;
    int hundreds = (state.score)/100 % 10;

    if (hundreds == 0)
    {
        drawImage(scoreZero.pixel_data, scoreZero.width, scoreZero.height, ENDMENUPOS_X+SCOREOFFSET_HUNDREDSX, ENDMENUPOS_Y+SCOREOFFSETY); 
    }
    else if (hundreds == 1)
    {
        drawImage(scoreOne.pixel_data, scoreOne.width, scoreOne.height, ENDMENUPOS_X+SCOREOFFSET_HUNDREDSX, ENDMENUPOS_Y+SCOREOFFSETY); 
    }
    else if (hundreds == 2)
    {
        drawImage(scoreTwo.pixel_data, scoreTwo.width, scoreTwo.height, ENDMENUPOS_X+SCOREOFFSET_HUNDREDSX, ENDMENUPOS_Y+SCOREOFFSETY); 
    }
    else if (hundreds == 3)
    {
        drawImage(scoreThree.pixel_data, scoreThree.width, scoreThree.height, ENDMENUPOS_X+SCOREOFFSET_HUNDREDSX, ENDMENUPOS_Y+SCOREOFFSETY); 
    }
    else if (hundreds == 4)
    {
        drawImage(scoreFour.pixel_data, scoreFour.width, scoreFour.height, ENDMENUPOS_X+SCOREOFFSET_HUNDREDSX, ENDMENUPOS_Y+SCOREOFFSETY); 
    }
    else if (hundreds == 5)
    {
        drawImage(scoreFive.pixel_data, scoreFive.width, scoreFive.height, ENDMENUPOS_X+SCOREOFFSET_HUNDREDSX, ENDMENUPOS_Y+SCOREOFFSETY); 
    }
    else if (hundreds == 6)
    {
        drawImage(scoreSix.pixel_data, scoreSix.width, scoreSix.height, ENDMENUPOS_X+SCOREOFFSET_HUNDREDSX, ENDMENUPOS_Y+SCOREOFFSETY); 
    }
    else if (hundreds == 7)
    {
        drawImage(scoreSeven.pixel_data, scoreSeven.width, scoreSeven.height, ENDMENUPOS_X+SCOREOFFSET_HUNDREDSX, ENDMENUPOS_Y+SCOREOFFSETY); 
    }
    else if (hundreds == 8)
    {
        drawImage(scoreEight.pixel_data, scoreEight.width, scoreEight.height, ENDMENUPOS_X+SCOREOFFSET_HUNDREDSX, ENDMENUPOS_Y+SCOREOFFSETY); 
    }
    else if (hundreds == 9)
    {
        drawImage(scoreNine.pixel_data, scoreNine.width, scoreNine.height, ENDMENUPOS_X+SCOREOFFSET_HUNDREDSX, ENDMENUPOS_Y+SCOREOFFSETY); 
    }

    if (tens == 0)
    {
        drawImage(scoreZero.pixel_data, scoreZero.width, scoreZero.height, ENDMENUPOS_X+SCOREOFFSET_TENSX, ENDMENUPOS_Y+SCOREOFFSETY); 
    }
    else if (tens == 1)
    {
        drawImage(scoreOne.pixel_data, scoreOne.width, scoreOne.height, ENDMENUPOS_X+SCOREOFFSET_TENSX, ENDMENUPOS_Y+SCOREOFFSETY); 
    }
    else if (tens == 2)
    {
        drawImage(scoreTwo.pixel_data, scoreTwo.width, scoreTwo.height, ENDMENUPOS_X+SCOREOFFSET_TENSX, ENDMENUPOS_Y+SCOREOFFSETY); 
    }
    else if (tens == 3)
    {
        drawImage(scoreThree.pixel_data, scoreThree.width, scoreThree.height, ENDMENUPOS_X+SCOREOFFSET_TENSX, ENDMENUPOS_Y+SCOREOFFSETY); 
    }
    else if (tens == 4)
    {
        drawImage(scoreFour.pixel_data, scoreFour.width, scoreFour.height, ENDMENUPOS_X+SCOREOFFSET_TENSX, ENDMENUPOS_Y+SCOREOFFSETY); 
    }
    else if (tens == 5)
    {
        drawImage(scoreFive.pixel_data, scoreFive.width, scoreFive.height, ENDMENUPOS_X+SCOREOFFSET_TENSX, ENDMENUPOS_Y+SCOREOFFSETY); 
    }
    else if (tens == 6)
    {
        drawImage(scoreSix.pixel_data, scoreSix.width, scoreSix.height, ENDMENUPOS_X+SCOREOFFSET_TENSX, ENDMENUPOS_Y+SCOREOFFSETY); 
    }
    else if (tens == 7)
    {
        drawImage(scoreSeven.pixel_data, scoreSeven.width, scoreSeven.height, ENDMENUPOS_X+SCOREOFFSET_TENSX, ENDMENUPOS_Y+SCOREOFFSETY); 
    }
    else if (tens == 8)
    {
        drawImage(scoreEight.pixel_data, scoreEight.width, scoreEight.height, ENDMENUPOS_X+SCOREOFFSET_TENSX, ENDMENUPOS_Y+SCOREOFFSETY); 
    }
    else if (tens == 9)
    {
        drawImage(scoreNine.pixel_data, scoreNine.width, scoreNine.height, ENDMENUPOS_X+SCOREOFFSET_TENSX, ENDMENUPOS_Y+SCOREOFFSETY); 
    }


    if (ones == 0)
    {
        drawImage(scoreZero.pixel_data, scoreZero.width, scoreZero.height, ENDMENUPOS_X+SCOREOFFSET_ONESX, ENDMENUPOS_Y+SCOREOFFSETY); 
    }
    else if (ones == 1)
    {
        drawImage(scoreOne.pixel_data, scoreOne.width, scoreOne.height, ENDMENUPOS_X+SCOREOFFSET_ONESX, ENDMENUPOS_Y+SCOREOFFSETY); 
    }
    else if (ones == 2)
    {
        drawImage(scoreTwo.pixel_data, scoreTwo.width, scoreTwo.height, ENDMENUPOS_X+SCOREOFFSET_ONESX, ENDMENUPOS_Y+SCOREOFFSETY); 
    }
    else if (ones == 3)
    {
        drawImage(scoreThree.pixel_data, scoreThree.width, scoreThree.height, ENDMENUPOS_X+SCOREOFFSET_ONESX, ENDMENUPOS_Y+SCOREOFFSETY); 
    }
    else if (ones == 4)
    {
        drawImage(scoreFour.pixel_data, scoreFour.width, scoreFour.height, ENDMENUPOS_X+SCOREOFFSET_ONESX, ENDMENUPOS_Y+SCOREOFFSETY); 
    }
    else if (ones == 5)
    {
        drawImage(scoreFive.pixel_data, scoreFive.width, scoreFive.height, ENDMENUPOS_X+SCOREOFFSET_ONESX, ENDMENUPOS_Y+SCOREOFFSETY); 
    }
    else if (ones == 6)
    {
        drawImage(scoreSix.pixel_data, scoreSix.width, scoreSix.height, ENDMENUPOS_X+SCOREOFFSET_ONESX, ENDMENUPOS_Y+SCOREOFFSETY); 
    }
    else if (ones == 7)
    {
        drawImage(scoreSeven.pixel_data, scoreSeven.width, scoreSeven.height, ENDMENUPOS_X+SCOREOFFSET_ONESX, ENDMENUPOS_Y+SCOREOFFSETY); 
    }
    else if (ones == 8)
    {
        drawImage(scoreEight.pixel_data, scoreEight.width, scoreEight.height, ENDMENUPOS_X+SCOREOFFSET_ONESX, ENDMENUPOS_Y+SCOREOFFSETY); 
    }
    else if (ones == 9)
    {
        drawImage(scoreNine.pixel_data, scoreNine.width, scoreNine.height, ENDMENUPOS_X+SCOREOFFSET_ONESX, ENDMENUPOS_Y+SCOREOFFSETY); 
    }
    pressedButtons = getSNES();
    while(getSNES() == 0b1111111111111111); // Wait until any button is pressed. 
}

void drawUI()
{   
    // Set menu bar background to be black.
    drawRect(0,0,SCREENWIDTH, MENUHEIGHT, BLACK, 1);
    
    drawImage(lives.pixel_data, lives.width, lives.height, TILESIZE, TILESIZE);
    
    // 0 score at the start. 
    drawImage(score.pixel_data, score.width, score.height, 9*TILESIZE, TILESIZE); 

    drawImage(meso.pixel_data, meso.width, meso.height, 14*TILESIZE - TILESIZE/2, TILESIZE);
    
    drawImage(time.pixel_data, time.width, time.height, 16*TILESIZE, TILESIZE); 
    // Time 300s at start initially. 
    // drawImage(timeThree.pixel_data, timeThree.width, timeThree.height, 18*TILESIZE + TILESIZE/2, TILESIZE); 
    // drawImage(timeZero.pixel_data, timeZero.width, timeZero.height, 19*TILESIZE-10 +  TILESIZE/2, TILESIZE); 
    // drawImage(timeZero.pixel_data, timeZero.width, timeZero.height, 20*TILESIZE-20 + TILESIZE/2, TILESIZE); 
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
    else
    {
        drawImage(threeLives.pixel_data, threeLives.width, threeLives.height, 4*TILESIZE, TILESIZE); // Full health at the start.
    }

    // Update score
    int ones = (state.score) % 10;
    int tens = (state.score/10) % 10;
    int hundreds = (state.score/100) % 10;

    if (hundreds == 0)
    {
        drawImage(timeZero.pixel_data, timeZero.width, timeZero.height, 11*TILESIZE + TILESIZE/2, TILESIZE); 
    }
    else if (hundreds == 1)
    {
        drawImage(timeOne.pixel_data, timeOne.width, timeOne.height, 11*TILESIZE + TILESIZE/2, TILESIZE); 
    }
    else if (hundreds == 2)
    {
        drawImage(timeTwo.pixel_data, timeTwo.width, timeTwo.height, 11*TILESIZE + TILESIZE/2, TILESIZE); 
    }
    else if (hundreds == 3)
    {
        drawImage(timeThree.pixel_data, timeThree.width, timeThree.height, 11*TILESIZE + TILESIZE/2, TILESIZE); 
    }
    else if (hundreds == 4)
    {
        drawImage(timeFour.pixel_data, timeFour.width, timeFour.height, 11*TILESIZE + TILESIZE/2, TILESIZE); 
    }
    else if (hundreds == 5)
    {
        drawImage(timeFive.pixel_data, timeFive.width, timeFive.height, 11*TILESIZE + TILESIZE/2, TILESIZE); 
    }
    else if (hundreds == 6)
    {
        drawImage(timeSix.pixel_data, timeSix.width, timeSix.height, 11*TILESIZE + TILESIZE/2, TILESIZE); 
    }
    else if (hundreds == 7)
    {
        drawImage(timeSeven.pixel_data, timeSeven.width, timeSeven.height, 11*TILESIZE + TILESIZE/2, TILESIZE); 
    }
    else if (hundreds == 8)
    {
        drawImage(timeEight.pixel_data, timeEight.width, timeEight.height, 11*TILESIZE + TILESIZE/2, TILESIZE); 
    }
    else if (hundreds == 9)
    {
        drawImage(timeNine.pixel_data, timeNine.width, timeNine.height, 11*TILESIZE + TILESIZE/2, TILESIZE); 
    }

    if (tens == 0)
    {
        drawImage(timeZero.pixel_data, timeZero.width, timeZero.height, 12*TILESIZE-10 + TILESIZE/2, TILESIZE);
    }
    else if (tens == 1)
    {
        drawImage(timeOne.pixel_data, timeOne.width, timeOne.height, 12*TILESIZE-8 + TILESIZE/2, TILESIZE);
    }
    else if (tens == 2)
    {
        drawImage(timeTwo.pixel_data, timeTwo.width, timeTwo.height, 12*TILESIZE-8 + TILESIZE/2, TILESIZE); 
    }
    else if (tens == 3)
    {
        drawImage(timeThree.pixel_data, timeThree.width, timeThree.height, 12*TILESIZE-8 + TILESIZE/2, TILESIZE); 
    }
    else if (tens == 4)
    {
        drawImage(timeFour.pixel_data, timeFour.width, timeFour.height, 12*TILESIZE-8 + TILESIZE/2, TILESIZE); 
    }
    else if (tens == 5)
    {
        drawImage(timeFive.pixel_data, timeFive.width, timeFive.height, 12*TILESIZE-8 + TILESIZE/2, TILESIZE); 
    }
    else if (tens == 6)
    {
        drawImage(timeSix.pixel_data, timeSix.width, timeSix.height, 12*TILESIZE-8 + TILESIZE/2, TILESIZE); 
    }
    else if (tens == 7)
    {
        drawImage(timeSeven.pixel_data, timeSeven.width, timeSeven.height, 12*TILESIZE-8 + TILESIZE/2, TILESIZE); 
    }
    else if (tens == 8)
    {
        drawImage(timeEight.pixel_data, timeEight.width, timeEight.height, 12*TILESIZE-8 + TILESIZE/2, TILESIZE); 
    }
    else if (tens == 9)
    {
        drawImage(timeNine.pixel_data, timeNine.width, timeNine.height, 12*TILESIZE-8 + TILESIZE/2, TILESIZE); 
    }


    if (ones == 0)
    {
        drawImage(timeZero.pixel_data, timeZero.width, timeZero.height, 13*TILESIZE-20 + TILESIZE/2, TILESIZE); 
    }
    else if (ones == 1)
    {
        drawImage(timeOne.pixel_data, timeOne.width, timeOne.height, 13*TILESIZE-18 + TILESIZE/2, TILESIZE);
    }
    else if (ones == 2)
    {
        drawImage(timeTwo.pixel_data, timeTwo.width, timeTwo.height, 13*TILESIZE-20 + TILESIZE/2, TILESIZE); 
    }
    else if (ones == 3)
    {
        drawImage(timeThree.pixel_data, timeThree.width, timeThree.height, 13*TILESIZE-20 + TILESIZE/2, TILESIZE); 
    }
    else if (ones == 4)
    {
        drawImage(timeFour.pixel_data, timeFour.width, timeFour.height, 13*TILESIZE-20 + TILESIZE/2, TILESIZE); 
    }
    else if (ones == 5)
    {
        drawImage(timeFive.pixel_data, timeFive.width, timeFive.height, 13*TILESIZE-20 + TILESIZE/2, TILESIZE); 
    }
    else if (ones == 6)
    {
        drawImage(timeSix.pixel_data, timeSix.width, timeSix.height, 13*TILESIZE-20 + TILESIZE/2, TILESIZE); 
    }
    else if (ones == 7)
    {
        drawImage(timeSeven.pixel_data, timeSeven.width, timeSeven.height, 13*TILESIZE-20 + TILESIZE/2, TILESIZE); 
    }
    else if (ones == 8)
    {
        drawImage(timeEight.pixel_data, timeEight.width, timeEight.height, 13*TILESIZE-20 + TILESIZE/2, TILESIZE); 
    }
    else if (ones == 9)
    {
        drawImage(timeNine.pixel_data, timeNine.width, timeNine.height, 13*TILESIZE-20 + TILESIZE/2, TILESIZE); 
    }

    // Update time
    ones = (state.timeRem/1000000) % 10;
    tens = (state.timeRem/10000000) % 10;
    hundreds = (state.timeRem/100000000) % 10;

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
            break;
        }
        else if(restart.selected && !(pressedButtons >> 8 & 1))
        {
            state.restart = TRUE;
            break;
        }
    }
}

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

void drawMap()
{
    // For all the tiles in the map draw the corrosponding tile at that location.
    for(int i = 0; i < (SCREENHEIGHT-MENUHEIGHT)/TILESIZE; i++)
    {
        for(int j = 0; j < SCREENWIDTH/TILESIZE; j++)
        {
            drawTile(j,i);
        }
    }
}

void drawEntities()
{
    // Check the entity map and draw entites corresponding to the entity index.
    // For entites which appear multiples times and need to be updated a range of
    // entity indices needed to be used to avoid updating the same entity twice.
    for(int i = 0; i < (SCREENHEIGHT-MENUHEIGHT)/TILESIZE; i++)
    {
        for(int j = 0; j < SCREENWIDTH/TILESIZE; j++)
        {
            if(state.entities[i][j] == 1 && state.invincible == FALSE && state.level == 1)// Draw a regular player entity
            {
                drawImage(snakeE.pixel_data, snakeE.width, snakeE.height, j*TILESIZE, i*TILESIZE + MENUHEIGHT);
            }
            else if(state.entities[i][j] == 1 && state.invincible == TRUE && state.level == 1)// Draw a invinsible player entity
            {
                drawImage(snakeEInv.pixel_data, snakeEInv.width, snakeEInv.height, j*TILESIZE, i*TILESIZE + MENUHEIGHT);
            }
            else if(state.entities[i][j] == 2 && state.level == 1)// Draw a apple entity
            {
                drawImage(apple.pixel_data, apple.width, apple.height, j*TILESIZE, i*TILESIZE + MENUHEIGHT);
            }
            else if(state.entities[i][j] == 3 && state.level == 1)// Draw a coin entity
            {
                drawImage(coin.pixel_data, coin.width, coin.height, j*TILESIZE, i*TILESIZE + MENUHEIGHT);
            }
            else if(state.entities[i][j] == 4 && state.level == 1)// Draw a invinsibility power up entity
            {
                drawImage(potion.pixel_data, potion.width, potion.height, j*TILESIZE, i*TILESIZE + MENUHEIGHT);
            }
            else if(state.entities[i][j] == 5 && state.level == 1)// Draw a goal entity
            {
                drawImage(goal.pixel_data, goal.width, goal.height, j*TILESIZE, i*TILESIZE + MENUHEIGHT);
            }
            else if(state.entities[i][j] >= 6 && state.entities[i][j] <= 11 && state.level == 1)// Draw a saw entity
            {
                drawImage(saw.pixel_data, saw.width, saw.height, j*TILESIZE, i*TILESIZE + MENUHEIGHT);
            }
            else if(state.entities[i][j] >= 12 && state.entities[i][j] <= 15 && state.level == 1)// Draw a flame entity
            {
                drawImage(flame.pixel_data, flame.width, flame.height, j*TILESIZE, i*TILESIZE + MENUHEIGHT);
            }
            else if(state.entities[i][j] == 1 && state.invincible == FALSE && state.level == 2)// Draw a regular player entity
            {
                drawImage(snake2E.pixel_data, snake2E.width, snake2E.height, j*TILESIZE, i*TILESIZE + MENUHEIGHT);
            }
            else if(state.entities[i][j] == 1 && state.invincible == TRUE && state.level == 2)// Draw a invinsible player entity
            {
                drawImage(snake2EInv.pixel_data, snake2EInv.width, snake2EInv.height, j*TILESIZE, i*TILESIZE + MENUHEIGHT);
            }
            else if(state.entities[i][j] == 2 && state.level == 2)// Draw a apple entity
            {
                drawImage(apple2.pixel_data, apple2.width, apple2.height, j*TILESIZE, i*TILESIZE + MENUHEIGHT);
            }
            else if(state.entities[i][j] == 3 && state.level == 2)// Draw a coin entity
            {
                drawImage(coin2.pixel_data, coin2.width, coin2.height, j*TILESIZE, i*TILESIZE + MENUHEIGHT);
            }
            else if(state.entities[i][j] == 4 && state.level == 2)// Draw a invinsibility power up entity
            {
                drawImage(potion2.pixel_data, potion2.width, potion2.height, j*TILESIZE, i*TILESIZE + MENUHEIGHT);
            }
            else if(state.entities[i][j] == 5 && state.level == 2)// Draw a goal entity
            {
                drawImage(goal2.pixel_data, goal2.width, goal2.height, j*TILESIZE, i*TILESIZE + MENUHEIGHT);
            }
            else if(state.entities[i][j] >= 6 && state.entities[i][j] <= 11 && state.level == 2)// Draw a saw entity
            {
                drawImage(saw2.pixel_data, saw2.width, saw2.height, j*TILESIZE, i*TILESIZE + MENUHEIGHT);
            }
            else if(state.entities[i][j] >= 12 && state.entities[i][j] <= 15 && state.level == 2)// Draw a flame entity
            {
                drawImage(flame2.pixel_data, flame2.width, flame2.height, j*TILESIZE, i*TILESIZE + MENUHEIGHT);
            }
            if (state.entities[i][j] != 0)// Redraw the grid if the tile had an entity drawn.
            {
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
    // Check if that location is out of bounds.
    else if(x >= SCREENWIDTH/TILESIZE || x < 0 || y >= (SCREENHEIGHT-MENUHEIGHT)/TILESIZE || y < 0)
    {
        return TRUE;
    }
    // Collisions when a player attempts to move///////////////////////////////////////////
    // If lives are less than 4 when picking up an apple increse it by 1 and erase the apple
    else if(entityIndex == PLAYER && state.entities[y][x] == APPLE && state.lives < MAXHEALTH)
    {
        state.lives += 1;
        state.entities[y][x] = 0;
        state.stateChange = TRUE;
        return FALSE;
    }
    // If lives are 4 increse the score by 5 and still erase the apple
    else if(entityIndex == PLAYER && state.entities[y][x] == APPLE && state.lives >= MAXHEALTH)
    {
        state.score += 2;
        state.entities[y][x] = 0;
        state.stateChange = TRUE;
        return FALSE;
    }
    // When colliding with a coin increase score by 1 and erase the coin
    else if(entityIndex == PLAYER && state.entities[y][x] == COIN)
    {
        state.score++;
        state.entities[y][x] = 0;
        state.stateChange = TRUE;
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
    else if(entityIndex == PLAYER && state.entities[y][x] == GOAL)
    {
        state.winFlag = TRUE;
        return TRUE;
    }
    else if(entityIndex == PLAYER && (state.entities[y][x] >= 6 && state.entities[y][x] <= 15) && state.invincible == FALSE)
    {
        state.lives--;
        state.stateChange = TRUE;
        return TRUE;

    }
    else if(entityIndex == PLAYER && (state.entities[y][x] >= 12 && state.entities[y][x] <= 15) && state.invincible == TRUE)
    {
        state.entities[y][x] = 0;
        return FALSE;
    }
    ///////////////////////////////////////////////////////////////////////////////////////
    // Collisions when a enemy attempts to move////////////////////////////////////////////
    else if(entityIndex == SAW && state.entities[y][x] == PLAYER && state.invincible == FALSE)
    {
        state.lives--;
        state.stateChange = TRUE;
        return TRUE;
    }
    else if(entityIndex == FLAME && state.entities[y][x] == PLAYER && state.invincible == FALSE)
    {
        state.lives--;
        state.stateChange = TRUE;
        return TRUE;
    }
    ///////////////////////////////////////////////////////////////////////////////////////
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
    // Keeps track of current position and new position to move.
    int xCur, yCur;
    int xNew, yNew;

    // Checks if the power up as worn off
    if(state.invincibleTime <= 0)
    {
        state.invincible = FALSE;
    }
    else
    {
        state.invincibleTime -= 1;
    }

    // Update player position
    for(int i = 0; i < (SCREENHEIGHT-MENUHEIGHT)/TILESIZE; i++)
    {
        for(int j = 0; j < SCREENWIDTH/TILESIZE; j++)
        {
            if(state.entities[i][j] == 1)
            {   
                // Get player pos
                xCur = j;
                yCur = i;
                
                // Determine the direction of movement and if it is possible to do so.
                if(!(pressedButtons >> 4 & 1) && !checkCollision(PLAYER, xCur, yCur - 1))//Move up
                {
                    xNew = xCur;
                    yNew = yCur - 1;
                    
                }
                else if(!(pressedButtons >> 5 & 1) && !checkCollision(PLAYER, xCur, yCur + 1))//Move down
                {
                    xNew = xCur;
                    yNew = yCur + 1;
                }
                else if(!(pressedButtons >> 6 & 1) && !checkCollision(PLAYER, xCur - 1, yCur))//Move left
                {
                    xNew = xCur - 1;
                    yNew = yCur;
                }
                else if(!(pressedButtons >> 7 & 1) && !checkCollision(PLAYER, xCur + 1, yCur))//Move right
                {
                    xNew = xCur + 1;
                    yNew = yCur;
                }
                else// No movement
                {
                    xNew = xCur;
                    yNew = yCur;
                }

                if(xNew != xCur || yNew != yCur)
                {
                    //If the player moved update their position in the entity map.
                    state.entities[yCur][xCur] = 0;
                    state.entities[yNew][xNew] = 1;
                    drawTile(j,i);//color background over old pos
                    return;
                }
            }
        }
    }
}

void updateSaws()
{
    // Array to keep track of saw entites on the map and there update status.
    int updated[SAWCOUNT] = {0,0,0,0,0,0};
    int index;

    // Find saws in the map.
    for(int i = 0; i < (SCREENHEIGHT-MENUHEIGHT)/TILESIZE; i++)
    {
        for(int j = 0; j < SCREENWIDTH/TILESIZE; j++)
        {
           if(state.entities[i][j] >= 6 && state.entities[i][j] <= 8)// X direction saw
           {
                index = state.entities[i][j] - 6;
                if(updated[index] == 0)// Dont update the same saw twice
                {
                    if(state.sawVel[index] == 1 )// Saw is moving to the right
                    {
                        if(!checkCollision(SAW, j+1, i))// Try to move saw right again
                        {
                            state.entities[i][j+1] = state.entities[i][j];
                            state.entities[i][j] = 0;
                            drawTile(j,i);
                        }
                        else
                        {
                            state.sawVel[index] = -1;// Change saw direction.
                        }
                    }
                    else// Saw is moving to the left
                    {
                        if(!checkCollision(SAW, j-1, i))// Try to move saw left again
                        {
                            state.entities[i][j-1] = state.entities[i][j];
                            state.entities[i][j] = 0;
                            drawTile(j,i);
                        }
                        else
                        {
                            state.sawVel[index] = 1;// Change saw direction.
                        }
                    }
                    
                    // Mark this entity as updated.
                    updated[index] = 1;
                }
            }
            else if(state.entities[i][j] >= 9 && state.entities[i][j] <= 11)// Y direction saw
           {
                index = state.entities[i][j] - 6;
                if(updated[index] == 0)//dont update the same saw twice
                {
                    if(state.sawVel[index] == 1 )// Saw is moving to the down
                    {
                        if(!checkCollision(SAW, j, i+1))// Try to move saw down again
                        {
                            state.entities[i+1][j] = state.entities[i][j];
                            state.entities[i][j] = 0;
                            drawTile(j,i);
                        }
                        else
                        {
                            state.sawVel[index] = -1;// Change saw direction.
                        }
                    }
                    else// Saw is moving to the up
                    {
                        if(!checkCollision(SAW, j, i-1))// Try to move saw up again
                        {
                            state.entities[i-1][j] = state.entities[i][j];
                            state.entities[i][j] = 0;
                            drawTile(j,i);
                        }
                        else
                        {
                            state.sawVel[index] = 1;// Change saw direction.
                        }
                    }

                    // Mark this entity as updated.
                    updated[index] = 1;
                }
            }
        }
    }
}

void updateFlames()
{
     // Array to keep track of flame entites on the map and there update status.
    int updated[FLAMECOUNT] = {0,0,0,0};
    int index;

    int xNew, yNew; // New position for the flame entity to move.

    for(int i = 0; i < (SCREENHEIGHT-MENUHEIGHT)/TILESIZE; i++)
    {
        for(int j = 0; j < SCREENWIDTH/TILESIZE; j++)
        {
            if(state.entities[i][j] >= 12 && state.entities[i][j] <= 15)
           {
                index = state.entities[i][j] - 12;
                if(updated[index] == 0 )// Flame has been updated
                {
                    // An attempt to make random numbers.
                    switch ((rand()*rand()/rand())%4)
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

                    // If the position to move is vaild move the flame enemy there.
                    if(xNew < SCREENWIDTH/TILESIZE && yNew < (SCREENHEIGHT-MENUHEIGHT)/TILESIZE
                        && xNew >= 0 && yNew >= 0)
                    {
                        if(!checkCollision(FLAME, xNew, yNew))
                        {
                        state.entities[yNew][xNew] = state.entities[i][j];
                        state.entities[i][j] = 0;
                        drawTile(j,i);
                        }
                    }

                    // Mark this entity as updated.
                    updated[index] = 1;
                }
           }
        }
    }
}

void menu();
void level();

int main()
{
    /////////////////////////////////Initialize////////////////////////////////

    init_framebuffer(); // You can use framebuffer, width, height and pitch variables available in framebuffer.h
    width = SCREENWIDTH;
    height = SCREENHEIGHT;
    
    initSNES();

    ///////////////////////////////////////////////////////////////////////////
    while(1)
    {
        mainStart:;
        menu();
        if(state.winFlag == FALSE)
        {
            break;
        }
        
        level(1, level1Map, level1Entities);
        if(state.quit == TRUE)
        {
            goto mainStart; // Jump back to menu if the player selected to quit the level.
        }

        if(state.winFlag == FALSE)
        {
            loseMenu();
            continue;
        }

        level(2, level2Map, level2Entities);
        if(state.quit == TRUE)
        {
            goto mainStart; // Jump back to menu if the player selected to quit the level.
        }

        if(state.winFlag == FALSE)
        {
            loseMenu();
            continue;
        }
        
        winMenu();
        // all levels have been completed. Display win screen with final score
        // wait for any button to be pressed before returning to main menu.

    }

    fillScreen(BLACK);
    
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
    state.lives = 6;
    state.score = 0;
    state.timeRem = 300000000; // 5 minutes = 300 seconds = 300000 milliseconds.
    state.invincible = FALSE;
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

void initLevel(int level, int worldMap[20][32], int entityMap[20][32])
{
    state.winFlag = FALSE;
    state.restart = FALSE;
    state.quit = FALSE;
    state.level = level;

    // Store the levelone map in the state map.
    for(int i = 0; i < (SCREENHEIGHT-MENUHEIGHT)/TILESIZE; i++)
    {
        for(int j = 0; j < SCREENWIDTH/TILESIZE; j++)
        {
            state.map[i][j] = worldMap[i][j];
        }
    }

    // Store the levelone entites in the state entites.
    for(int i = 0; i < (SCREENHEIGHT-MENUHEIGHT)/TILESIZE; i++)
    {
        for(int j = 0; j < SCREENWIDTH/TILESIZE; j++)
        {
            state.entities[i][j] = entityMap[i][j];
        }
    }

    // Set saw enemy velocities
    for(int i = 0; i < SAWCOUNT; i++)
    {
        state.sawVel[i] = 1;
    }
    
    // Draw the map state
    drawUI();
    updateUI();
    drawMap();
    drawEntities();
}

void level(int level, int worldMap[20][32], int entityMap[20][32])
{
    levelStart:;

    initLevel(level, worldMap, entityMap);

    while(getSNES() >> 3 & 1); // Wait for start button to be pressed before starting the game.

    while(state.lives > 0 && state.winFlag == FALSE && state.quit == FALSE && state.timeRem > 0)
    {
        pressedButtons =  getSNES();// Get current button state to update game state.

        updatePlayer();
        updateSaws();
        updateFlames();

        if(state.stateChange == TRUE || displayTime != state.timeRem/1000000)// Only update the ui if ui elements changed.
        {
            updateUI();
            state.stateChange = FALSE;
        }
        drawEntities();
        // The wait function only works reliably for small time values so run it multiple
        // times instead of using a larger value.
        for(int i = 0; i < FRAMETIME/100; i++)
            wait(1);
        updateTimeRem(FRAMETIME/10); // I lost a factor of 10 somewhere so this is divided by 10.

        if (!(pressedButtons >> 3 & 1))// Enter the pause menu when start is pressed.
        {
            drawPauseMenu(level, worldMap, entityMap);
            if(state.restart == TRUE)
            {
                goto levelStart; // Jump back to level start if the player selected to restart the level.
            }
        }
        if(state.quit == TRUE)
        {
            break;
        }
    }
} 
