#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
typedef struct Player
{
	int points;
	int penguins; //should change it an array why a pointer ?
	char *team_name;

	struct Player *next_player;
} player;

//void create_players(player player1[],int number_of_players,int penguins_per_player);


#endif // PLAYER_H_INCLUDED
