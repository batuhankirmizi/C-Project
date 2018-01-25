#ifndef INPUT_OUTPUT_FUNCTIONS_H_INCLUDED
#define INPUT_OUTPUT_FUNCTIONS_H_INCLUDED
#include "player (1).h"

int get_board_size_X(char *filenanme);
int get_board_size_Y(char *filenanme);
void read_from_text_file_and_create_board(int board_size_X, int board_size_Y, int* board[], char *filename, player **players, int _p_size);
void write_to_text_file(int board_size_X,int board_size_Y, int* board[],char *filenanme, player **p, int _p_size);
int check_existing_of_player(char* filenanme,char* name);
int line_count_in_text_file(char *file_name);
int has_players(char *file_name); // return 1(true) if game contains some players already, otherwise return 0(false)
int player_count_p(char *file_name, player **p); // return the number of players in the game
int player_count(char *file_name); // return the number of players in the game
char* get_team(char *file_name, int team_id); // get team's name by the given id
int get_id(char *file_name, char *team_name); // get team's id by the given name
int get_number_for_new_player(char *file_name, player **p); // return the number for the new player (4, 5, 6, 7, . . . . .)
int get_penguin_count_of(char *file_name, char *team_name, int id); // return the penguin count of the team on the board
int check_player_name(char *file_name, char *player_name);
int get_points(char *file_name, char *player_name);
//void write_players(char* filename, char* name);

#endif // INPUT_OUTPUT_FUNCTIONS_H_INCLUDED
