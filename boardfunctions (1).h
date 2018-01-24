#ifndef BOARDFUNCTIONS_H_INCLUDED
#define BOARDFUNCTIONS_H_INCLUDED
#include<stdio.h>

void input_data(); // entering data from the user
void generate_fish_network(int board_size_X,int board_size_Y, int* fish_matrix[], FILE *myFile);
void generate_board(int board_size_X,int board_size_Y,int* board[],int* fish_matrix[]);
int how_many_players(int board_size_X, int board_size_Y, int* board[], int penguins);

void display_board(int board_size_X, int board_size_Y, int* board[]);
void penguin_place_select(int board_size_X,int board_size_Y,int* board[], int penguin);
int enough_place(int board_size_X,int board_size_Y, int* board[], int number_of_players, int penguins_per_player);
int board_contains(char* fn, int i);

#endif // BOARDFUNCTIONS_H_INCLUDED
