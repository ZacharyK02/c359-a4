#include "gpio.h"
#include "uart.h"
#include "framebuffer.h"
#include "controllerDriver.h"

////////////////////////////////////Images/////////////////////////////////////
#include "UI_Elements/startButtonYellow.h"
#include "UI_Elements/startButtonGrey.h"
#include "UI_Elements/exitButtonYellow.h"
#include "UI_Elements/exitButtonGrey.h"
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
#define RED 0xfa3434

// Macro for the clock register.
#define CLO_REG 0x7E003004

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
* -1 = Water
* Entities:
* 1 = Player
*/

int level1Map[20][40] = {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
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
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};

int level1Entities[20][40] = {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
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
                drawRect(j*TILESIZE, i*TILESIZE + MENUHEIGHT, (j+1)*TILESIZE, (i+1)*TILESIZE + MENUHEIGHT, BLACK, 0);
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
                drawRect(j*TILESIZE, i*TILESIZE + MENUHEIGHT, (j+1)*TILESIZE, (i+1)*TILESIZE + MENUHEIGHT, RED, 1);
            }
        }
    }
}

void updateEntites()
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

                if(!(pressedButtons >> 4 & 1) && yCur - 1 >= 0)//Move up
                {
                    xNew = xCur;
                    yNew = yCur - 1;
                    //color background over old pos
                }
                else if(!(pressedButtons >> 5 & 1) && yCur + 1 < (SCREENHEIGHT-MENUHEIGHT)/TILESIZE)//Move down
                {
                    xNew = xCur;
                    yNew = yCur + 1;
                }
                else if(!(pressedButtons >> 6 & 1) && xCur - 1 >= 0)//Move left
                {
                    xNew = xCur - 1;
                    yNew = yCur;
                }
                else if(!(pressedButtons >> 7 & 1) && xCur + 1 < SCREENWIDTH/TILESIZE)//Move right
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
                    drawRect(j*TILESIZE, i*TILESIZE + MENUHEIGHT, (j+1)*TILESIZE, (i+1)*TILESIZE + MENUHEIGHT, BACKGROUNDGREEN, 1);
                    drawRect(j*TILESIZE, i*TILESIZE + MENUHEIGHT, (j+1)*TILESIZE, (i+1)*TILESIZE + MENUHEIGHT, BLACK, 0);
                    return;
                }
                
            }
        }
    }
}

void updateTimeRem()
{
    unsigned deltaT = (unsigned)CLO_REG - oldTime;
    oldTime = (unsigned)CLO_REG;
    state.timeRem -= deltaT/1000;
}

bool checkCollision(x, y)
{
    // Check to see if a collision would occur when moving to position x, y
    if(state.map[x][y] != 0 || state.entities[x][y] != 0)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
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

    // Draw the map state
    drawMap();
    drawEntities();

    while(1)
    {
        pressedButtons =  getSNES();// Get current button state to update game state.
        updateEntites();
        drawEntities();
    }
}

// enum bool level2()
// {

// }