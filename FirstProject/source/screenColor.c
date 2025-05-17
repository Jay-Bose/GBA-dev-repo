// screenColor.c

/* 
    My first .gba program will set the color of the entire screen.
After getting understanding how to set the screen/background color I will try to display a sprite then
mayba a moving sprite.
    I struggle understanding the pallettes.
*/

#include <stdio.h>
#include <gba_base.h>
#include <gba_video.h>
#include <gba_types.h>


/* Display a color on the screen using tile mode */

int main() {
    
    // set display mode and background mode
    REG_DISPCNT = MODE_0;
    REG_BG0CNT = BG_16_COLOR | BG_SIZE_0;

    while(1) {
        vid_sync();
    }

    return 0;
}