#include "player (1).h"
#include <stdlib.h>
/*a function to create all*/
void create_players(struct Player *player1,int number_of_players,int penguins_per_player){
    int i,j;
    for(i=0;i<number_of_players;i++)
    {
        player1[i].penguins=(int*)malloc(penguins_per_player*sizeof(int));
        player1[i].points=0;

        for(j=0;j<penguins_per_player;j++)
        {
            player1[i].penguins[j]=100*(i+1)+j+1;  //every penguin is being assigned a serial number 102 103 101 etc
        }
    }
}
