#include "player (1).h"
#include <stdlib.h>
#include <string.h>
#include "input_output_functions.h"

/*a function to create all*/
// TODO: in case of interactive mode usage, uncomment following lines:
//void create_players(struct Player *player1,int number_of_players,int penguins_per_player){
//    int i,j;
//    for(i=0;i<number_of_players;i++)
//    {
//        player1[i].penguins=(int*)malloc(penguins_per_player*sizeof(int));
//        player1[i].points=0;
//
//        for(j=0;j<penguins_per_player;j++)
//        {
//            player1[i].penguins[j]=100*(i+1)+j+1;  //every penguin is being assigned a serial number 102 103 101 etc
//        }
//    }
//}

player** add_all_the_existing_players(player *head, char *file_name) {
	player **iter = (player**) malloc(sizeof(player*));
	player *it = *iter;
	for (int i = 0; i < player_count(file_name); ++i) {
		char *t_n = (char*) malloc(50 * sizeof(char));
		strcpy(t_n, get_team(file_name, i));
		it = add_new_player(head, get_penguin_count_of(file_name, t_n, get_id(file_name, t_n)), t_n, get_id(file_name, t_n));
		iter[i] = it;
		
		if((it)->next) it = (it)->next;
	}
	return iter;
}

player* add_new_player(player* head, int penguins, char* team_name, int number) {
	if(head == NULL) {
		head = (player*) malloc(sizeof(player));
		head->points = 1;
		head->penguins = penguins;
		head->team_name = (char*) malloc((strlen(team_name) + 1) * sizeof(char));
		strcpy(head->team_name, team_name);
		head->number = number;
		head->next = NULL;

		return head;
	}

	player *iter = head;
	while(iter->next != NULL) {
		iter = iter->next;
	}

	iter = (player*) malloc(sizeof(player));
	iter->points = 1;
	iter->penguins = penguins;
	iter->team_name = (char*) malloc(50 * sizeof(char));
	strcpy(iter->team_name, team_name);
	iter->number = number;
	iter->next = NULL;
	return iter;
}

int has_player(player* head, char* team_name) {
	if(head == NULL) return 0;

	player *iter = head;
	while(iter != NULL) {
		if(strcmp(iter->team_name, team_name) == 0) return 1;

		iter = iter->next;
	}

	return 0;
}

player* get_player(player** players, int size, char *team_name) {
	for (int i = 0; i < size; ++i) {
		if(strcmp(players[i]->team_name, team_name) == 0) return players[i];
	}
	return NULL;
}
