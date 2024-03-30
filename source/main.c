#include "gpio.h"
#include "uart.h"
#include "framebuffer.h"
#include "controllerDriver.h"

////////////////////////////////////Images/////////////////////////////////////
#include "UI_Elements/startButtonYellow.h"
#include "UI_Elements/startButtonGrey.h"
#include "UI_Elements/exitButtonYellow.h"
#include "UI_Elements/exitButtonGrey.h"

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

void drawUI()
{

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
    // If lives are less than 4 when picking up an apple increse it by 1 and erase the apple
    else if(entityIndex == PLAYER && state.entities[y][x] == 2 && state.lives < 4)
    {
        state.lives += 1;
        state.entities[y][x] = 0;
        return FALSE;
    }
    // If lives are 4 increse the score by 5 and still erase the apple
    else if(entityIndex == PLAYER && state.entities[y][x] == 2 && state.lives >= 4)
    {
        state.score += 5;
        state.entities[y][x] = 0;
        return FALSE;
    }
    // When colliding with a coin incresse score by 1 and erase the coin
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

void updateTimeRem()
{
    unsigned deltaT = (unsigned)CLO_REG - oldTime;
    oldTime = (unsigned)CLO_REG;
    state.timeRem -= deltaT/1000;
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
        
        oldTime = (unsigned)CLO_REG; // Take note of when the level was started.
        level1();
        if(state.winFlag == FALSE)
        {
            continue;
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
    struct Button startButton, quitButton;
    startButton.selected = TRUE;
    quitButton.selected = FALSE;
    drawImage(startButtonGrey.pixel_data, startButtonGrey.width, startButtonGrey.height, 200, 200);
    drawImage(exitButtonYellow.pixel_data, exitButtonYellow.width, exitButtonYellow.height, 200, 300 + exitButtonYellow.height);

    // Refresh/Initilize game state
    state.lives = 4;
    state.score = 0;
    state.timeRem = 300000; // 5 minutes = 300 seconds = 300000 milliseconds.
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
    drawEntities();

    while(1)
    {
        pressedButtons =  getSNES();// Get current button state to update game state.
        updatePlayer();
        updateSaws();
        drawEntities();
        for(int i = 0; i < 10000; i++)
            wait(TICKTIME);
    }
}

// enum bool level2()
// {

// }