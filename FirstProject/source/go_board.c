// screenColor.c

/* 
    First create a tic tac toe board using the sprite layer for the Xs and Os*/

#include <stdio.h>
#include <gba_base.h>
#include <gba_video.h>
#include <gba_types.h>

// .h files
#include "go_board.h"

/* Display a color on the screen using tile mode */

int main() {
    
    // set display mode and background mode
    REG_DISPCNT = MODE_0;
    REG_BG0CNT = BG_16_COLOR | BG_SIZE_0;

    while(1) {
            
    }

    return 0;
}