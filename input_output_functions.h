#ifndef INPUT_OUTPUT_FUNCTIONS_H_INCLUDED
#define INPUT_OUTPUT_FUNCTIONS_H_INCLUDED

int get_board_size_X(char *filenanme);
int get_board_size_Y(char *filenanme);
void read_from_text_file_and_create_board(int board_size_X, int board_size_Y, int* board[], char *filenanme, char *name);
void write_to_text_file(int board_size_X,int board_size_Y, int* board[],char *filenanme, char *name, int points);
int check_existing_of_player(char* filenanme,char* name);
int line_count_in_text_file(char *file_name);
int check_player_name(char *file_name, char *player_name);
int get_points(char *file_name, char *player_name);
//void write_players(char* filename, char* name);

#endif // INPUT_OUTPUT_FUNCTIONS_H_INCLUDED
