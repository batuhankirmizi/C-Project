#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

typedef struct Player {
	int points; // points that this player has
	int penguins; // penguin count that this player has
	int number; // number of the player used on penguins (such as 4, 5, 6, 7 . . .)
	char *team_name; // team name of the player

	struct Player *next; // memory address of the player after this player
} player;

player** add_all_the_existing_players(player *head, char *file_name); // adds all the players currently existing in the game to the linked list
player* add_new_player(player *head, int penguins, char* team_name, int number); // add a new player to the linked list
int has_player(player *head, char *team_name); // return 1(true) if linked list contains such team name, otherwise return 0(false)
player* get_player(player** players, int size, char *team_name); // return the pointer to the player with the given team name

#endif // PLAYER_H_INCLUDED
