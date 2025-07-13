// go_board.h

#include <gba_types.h>

// Defines for board size
#define GO_BRD_9X9 9
#define GO_BRD_13X13 13
#define GO_BRD_19X19 19

// typedef black and white
#define EMPTY_STONE 0x00
#define BLACK_STONE 0x01
#define WHITE_STONE 0x10

typedef struct {
    u16 * stone_type;
    // possible other satellite data
} Stone;

typedef struct {
    // will be a double array (I cannot remember the name...) using the board size defines
    Stone * go_board[GO_BRD_9X9][GO_BRD_9X9];
    
} Go_Game_State;
// struct for a stone
// struct for game board
// defines for stone types and board sizes
