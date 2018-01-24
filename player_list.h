#pragma once
#include "player (1).h"

void add_player(player*, char*, int);

player* get_player(player* head, char* team_name);

player** get_players(player *head);

int exists(player* head, char* team_name);
