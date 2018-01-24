#include "player_list.h"
#include <stdlib.h>
#include <string.h>

void add_player(player *head, char *team_name, int penguin_count) {
	if(head == NULL) {
		head = (player*) malloc(sizeof(player));
		head->points = 0;
		head->penguins = penguin_count;
		head->team_name = (char*) malloc(150 * sizeof(char));
		strcpy(head->team_name, team_name);

		head->next_player = NULL;
		return;
	}

	player *iter = head;
	while(iter->next_player) {
		iter = iter->next_player;
	}

	iter = malloc(sizeof(player));
	iter->points = 0;
	iter->penguins = penguin_count;
	iter->team_name = (char*) malloc(40 * sizeof(char));
	strcpy(iter->team_name, team_name);

	iter->next_player = NULL;
}

player* get_player(player *head, char* team_name) {
	player *iter = head;
	while(strcmp(iter->team_name, team_name) != 0) {
		iter = iter->next_player;
	}
	return iter;
}

player** get_players(player* head) {
	player **pls = (player**) malloc(sizeof(player*));

	player *iter = head;
	int i = 0;
	while(iter) {
		*pls[i] = *iter;
		i++;
	}

	return pls;
}

int exists(player *head, char* team_name) {
	if(head == NULL) return 0;
	
	player *iter = head;
	while(iter) {
		if(strcmp(iter->team_name, team_name) == 0) return 1;
		iter = iter->next_player;
	}
	return 0;
}
