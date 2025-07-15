// go_board.h

// Defines for board size
#define GO_BOARD_9X9 9
#define GO_BOARD_13X13 13
#define GO_BOARD_19X19 19

// Defines for stone types
#define EMPTY_STONE 0x00
#define BLACK_STONE 0x01
#define WHITE_STONE 0x10

typedef struct {
    u16 * stone_type;
    // possible other satellite data
} Stone;

typedef struct {
    // HARD CODING THIS SIZE FOR NOW... I WILL CHANGE THIS LATER
    Stone * go_board[GO_BOARD_9X9][GO_BOARD_9X9];
    
} Go_Game_State;
