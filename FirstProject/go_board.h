// go_board.h

// Defines for board size
#define GO_BRD_9X9 9
#define GO_BRD_13X13 13
#define GO_BRD_19X19 19

// typedef black and white
#define BLACK 0
#define WHITE 1

// only two types of stones so using either a one or a zero.
enum Stone{
    black_stone = 0,
    white_stone
};

typedef struct {
    bool black_stone;
    bool white_stone;
} Stone; 

// struct for the board and the board state.
typedef struct {
    Stone go_board;
    bool player_turn;
} game_state; 


// I AM HAVING TROUBLE FIGURING OUT THE BEST WAY TO STRUCTURE AND KEEP TRACK OF THE BAORDS STATE