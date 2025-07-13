// screenColor.c

/* 
    GOAL: display a simple go board on screen
*/

#include <stdio.h>
#include <gba_base.h>
#include <gba_video.h>
#include <tonc.h>

// .h files
#include "go_board.h"

Go_Game_State go_game;


void init_go_game() {
    // counter for looping through game board array
    u16 i, j;
    i = j = 0;

    // initialize all game positions to empty
    for(; i < GO_BRD_9X9; ++i) {
        for(; j < GO_BRD_9X9; ++j) {
            *(go_game.go_board[i][j]->stone_type) = EMPTY_STONE;
        }
    }
    
}

int main() {
    
    init_go_game();

    REG_DISPCNT= DCNT_MODE0 | DCNT_BG0;

	// Init BG 0 for text on screen entries.
	tte_init_se_default(0, BG_CBB(0)|BG_SBB(31));

	tte_write("#{P:72,64}");		// Goto (72, 64).
	tte_write("Hello World!");		// Print "Hello world!"

	while(1);

	return 0;
}