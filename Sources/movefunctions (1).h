#ifndef MOVEFUNCTIONS_H_INCLUDED
#define MOVEFUNCTIONS_H_INCLUDED

#include "boardfunctions (1).h"
#include "player (1).h"
/*
//moved to player.h for modular design
struct Player
    {
        int points;
        int* penguins;
    };

*/
void change_position(int board_size_X, int board_size_Y, int* board[],struct Player* p, int which_player);
int check_move(int board_size_X, int board_size_Y, int* board[],int x, int y, int jump, int movement); //not ready
//void count_points(int* board[],struct Player *p, int x, int y);
int penguins_movement(int board_size_X, int board_size_Y, int* board[],int penguins_per_player, int player);
int check_if_any_movement_is_possible(int board_size_X, int board_size_Y,int* board[], int i, int j);


//void penguin_place_select(int* board[], int size_board, int penguin);



#endif // MOVEFUNCTIONS_H_INCLUDED
