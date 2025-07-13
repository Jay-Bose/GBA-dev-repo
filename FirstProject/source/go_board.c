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
    
    u16 rows, columns;
    rows = columns = 0;

    // initialize all game positions to empty
    for(; rows < GO_BRD_9X9; ++rows) {
        for(; columns < GO_BRD_9X9; ++columns) {
            *(go_game.go_board[rows][columns]->stone_type) = EMPTY_STONE;
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