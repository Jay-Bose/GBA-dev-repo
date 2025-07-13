// screenColor.c

/* 
    First create a tic tac toe board using the sprite layer for the Xs and Os*/

#include <stdio.h>
#include <gba_base.h>
#include <gba_video.h>

// .h files
#include "go_board.h"

Go_Game_State * go_game;


void init_go_game() {
    // counter for looping through game board array
    u16 i, j;
    i = j = 0;

    // initialize all game positions to empty
    for(; i <= GO_BRD_9X9; ++i) {
        for(; j <= GO_BRD_9X9; ++j) {
            go_game->go_board[i][j]->stone_type = BLACK_STONE;
        }
    }
    
}

int main() {
    
    init_go_game();

    for(u16 i = 0; i <= GO_BRD_9X9; ++i) {
        for(u16 j = 0; j <= GO_BRD_9X9; ++j) {
            printf("%d, ",go_game->go_board[i][j]->stone_type);
        }
    }


    while(1) {
            
    }

    return 0;
}