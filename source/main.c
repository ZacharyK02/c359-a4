#include "gpio.h"
#include "uart.h"
#include "framebuffer.h"
#include "controllerDriver.h"

////////////////////////////////////Images/////////////////////////////////////
#include "UI_Elements/startButtonYellow.h"
///////////////////////////////////////////////////////////////////////////////

#define TILESIZE 32
#define SCREENWIDTH 1280
#define SCREENHEIGHT 720
#define MENUHEIGHT 80

/*
* Screen size 1280x720.
* Number of horizontal cells (1280/32 = 40).
* Number of vertical cells (640/32 = 20).
* 80 extra pixels on the top for game status.
*/

typedef struct state
{
    int health;
    int coins;
    int entities[SCREENWIDTH/TILESIZE][(SCREENHEIGHT-MENUHEIGHT)/TILESIZE];
};

enum bool {
  TRUE = 1,
  FALSE = 0
};

int pressedButtons;

void printf(char *str) {
	uart_puts(str);
}

int main()
{
    /////////////////////////////////Initialize////////////////////////////////
    enum bool levelComplete = FALSE;
    enum bool quit = FALSE;

    init_framebuffer(); // You can use framebuffer, width, height and pitch variables available in framebuffer.h
    width = 1280;
    height = 720;
    initSNES();

    ///////////////////////////////////////////////////////////////////////////

    while(!quit)
    {
        // Main screen loop
        while(!levelComplete)
        {

        }
        levelComplete = FALSE;

        // Level 1 loop
        while(!levelComplete)
        {

        }
        levelComplete = FALSE;

        // Level 2 loop
        while (!levelComplete)
        {
            
        }
        
        // End screen loop
        while(!levelComplete)
        {

        }
        levelComplete = FALSE;
    }

    drawBackground(200);
    //drawImage("startButtonYellow", 474, 128, 100, 100);

    // while(!quit)
    // {

    //     // if(!(getSNES() >> 4 & 1))
    //     // {
    //     //     drawBackground(300);
    //     // }
    //     ///////////////////////////////////Update//////////////////////////////////

    //     ///////////////////////////////////////////////////////////////////////////

        
    //     ///////////////////////////////////Clear///////////////////////////////////

    //     ///////////////////////////////////////////////////////////////////////////


    //     ////////////////////////////////////Draw///////////////////////////////////

    //     ///////////////////////////////////////////////////////////////////////////


    //     ////////////////////////////////////Quit///////////////////////////////////

    //     ///////////////////////////////////////////////////////////////////////////
    // }
    
    return 0;
}

void updateTimeRem()
{

}

void updatePlayerPos()
{

}

void drawMap()
{
    
}

void drawUI()
{

}

void drawEntitiy()
{

}

void checkCollision()
{

}

