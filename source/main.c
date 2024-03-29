#include "gpio.h"
#include "uart.h"
#include "framebuffer.h"
#include "controllerDriver.h"

// ////////////////////////////////////Images/////////////////////////////////////
#include "UI_Elements/startButtonYellow.h"
#include "UI_Elements/startButtonGrey.h"
#include "UI_Elements/exitButtonYellow.h"
#include "UI_Elements/exitButtonGrey.h"
// ///////////////////////////////////////////////////////////////////////////////

// Macros for display setup
#define TILESIZE 32
#define SCREENWIDTH 1280
#define SCREENHEIGHT 720
#define MENUHEIGHT 80
#define BUTTONWIDTH 160
#define BUTTONHEIGHT 320

// Macros for colors
#define BACKGROUNDGREEN 0x32a846

/*
* Screen size 1280x720.
* Number of horizontal cells (1280/32 = 40).
* Number of vertical cells (640/32 = 20).
* 80 extra pixels on the top for game status.
*/

enum bool {
  TRUE = 1,
  FALSE = 0
};

typedef struct state
{
    int health;
    int coins;
    int entities[SCREENWIDTH/TILESIZE][(SCREENHEIGHT-MENUHEIGHT)/TILESIZE];
};

typedef struct Button
{
    int xpos;
    int ypos;
    int selected;
};

int pressedButtons;

void printf(char *str) {
	uart_puts(str);
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

int menu();
int level1();
int level2();

int main()
{
    /////////////////////////////////Initialize////////////////////////////////
    enum bool levelComplete = FALSE;
    enum bool quit = FALSE;

    init_framebuffer(); // You can use framebuffer, width, height and pitch variables available in framebuffer.h
    width = 1280;
    height = 720;
    fillScreen(BACKGROUNDGREEN);
    
    initSNES();

    ///////////////////////////////////////////////////////////////////////////
    while(1)
    {
        if(!menu())
        {
            break;
        }

        // if(!level1())
        // {
        //     continue;
        // }

        // if(!level2())
        // {
        //     continue;
        // }

    }

    fillScreen(0);
    
    return 0;
}

int menu()
{
    struct Button startButton, quitButton;
    startButton.selected = TRUE;
    quitButton.selected = FALSE;
    drawImage(startButtonGrey.pixel_data, startButtonGrey.width, startButtonGrey.height, 200, 200);
    drawImage(exitButtonYellow.pixel_data, exitButtonYellow.width, exitButtonYellow.height, 200, 300 + exitButtonYellow.height);

    while(1)
    {
        if(!(getSNES() >> 4 & 1) && quitButton.selected)
        {
            startButton.selected = TRUE;
            quitButton.selected = FALSE;
            drawImage(startButtonGrey.pixel_data, startButtonGrey.width, startButtonGrey.height, 200, 200);
            drawImage(exitButtonYellow.pixel_data, exitButtonYellow.width, exitButtonYellow.height, 200, 300 + exitButtonYellow.height);
            
        }
        else if(!(getSNES() >> 5 & 1) && startButton.selected)
        {
            startButton.selected = FALSE;
            quitButton.selected = TRUE;
            drawImage(startButtonYellow.pixel_data, startButtonYellow.width, startButtonYellow.height, 200, 200);
            drawImage(exitButtonGrey.pixel_data, exitButtonGrey.width, exitButtonGrey.height, 200, 300 + exitButtonGrey.height);
            
        }

        if(quitButton.selected && !(getSNES() >> 8 & 1))
        {
            return FALSE;
        }
        else if(startButton.selected && !(getSNES() >> 8 & 1))
        {
            return TRUE;
        }
    }
}

// enum bool level1()
// {

// }

// enum bool level2()
// {

// }