// screenColor.c

/* 
    GOAL: display a simple go board on screen
*/


#include <stdio.h>
#include <tonc.h>

// .h files
#include "go_board.h"

Go_Game_State go_game;


void init_go_game() {
    
    u16 rows, columns;
    rows = columns = 0;

    // initialize all game positions to empty
    for(; rows < GO_BOARD_9X9; ++rows) {
        for(; columns < GO_BOARD_9X9; ++columns) {
            *(go_game.go_board[rows][columns]->stone_type) = EMPTY_STONE;
        }
    }
    
}
// I DID NOT GET IT TO WORK *SAD_FACE
void display_board() {
    // Load palette
	memcpy16(pal_bg_mem, go_board_simple_workingPal, go_board_simple_workingPalLen / sizeof(u16));
	// Load tiles into CBB 0
	memcpy32(&tile_mem[0][0], go_board_simple_workingTiles, go_board_simple_workingTilesLen / sizeof(u32));
	// Load map into SBB 30
	memcpy32(&se_mem[30][0], go_board_simple_workingMap, go_board_simple_workingMapLen / sizeof(u32));
    
    // set up BG0 for a 4bpp 64x32t map, using charblock 0 and screenblock 31
    REG_BG0CNT = BG_CBB(0) | BG_SBB(30) | BG_4BPP | BG_REG_64x32;
    REG_DISPCNT = DCNT_MODE0 | DCNT_BG0;
}

int main() {
    
    init_go_game();

    REG_DISPCNT= DCNT_MODE0 | DCNT_BG0;

	while(1);

	return 0;
}