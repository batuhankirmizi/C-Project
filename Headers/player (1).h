#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
struct Player
    {
        int points;
        int* penguins; //should change it an array why a pointer ?
    };

void create_players(struct Player player1[],int number_of_players,int penguins_per_player);


#endif // PLAYER_H_INCLUDED
