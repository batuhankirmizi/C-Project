#ifndef AI_FUNCTIONS_H_INCLUDED
#define AI_FUNCTIONS_H_INCLUDED

/*
ALL DUMMY!
they have to be implemented for the last report

*/
int AI_which_penguin(int player);
void AI_penguin_place(int board_size_X, int board_size_Y,int* board[], int penguin); //this function should place the penguin according to game strategy, to do so the penguin_place function will be called
int AI_check_if_all_placed(int board_size_X, int board_size_Y, int* board[],int penguin_count, int player);
void AI_penguin_move(int board_size_X, int board_size_Y, int* board[], int player);
int AI_which_penguin(int player);


#endif // AI_FUNCTIONS_H_INCLUDED
