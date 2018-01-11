#ifndef INPUT_OUTPUT_FUNCTIONS_H_INCLUDED
#define INPUT_OUTPUT_FUNCTIONS_H_INCLUDED

int get_board_size_X(char *filenanme);
int get_board_size_Y(char *filenanme);
void read_from_text_file_and_create_board(int bboard_size_X, int board_size_Y,int* board[], char *filenanme);
void write_to_text_file(int board_size_X,int board_size_Y, int* board[],char *filenanme, char* name);
//void write_players(char* filename, char* name);

#endif // INPUT_OUTPUT_FUNCTIONS_H_INCLUDED
