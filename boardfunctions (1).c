#include "boardfunctions (1).h"
#include <stdio.h>
#include<stdlib.h>



void input_data(int* number_of_players, int* penguins_per_player ) // entering data from the user
{ //function takes int pointers to modify, to get rid of global variables, the varibales are created in int main
    printf("Enter the number of players: \n");
    scanf("%d", number_of_players);
    printf("\n");
    printf("Enter the number of penguins per player: \n");
    scanf("%d", penguins_per_player);
}

void generate_fish_network(int board_size_X,int board_size_Y,int* fish_matrix[],FILE *myFile){
    int i=0, j=0;
    for(i=0; i<board_size_X; i++){
        for(j=0; j<board_size_Y; j++){
            fscanf(myFile,"%d",&fish_matrix[i][j]);


        }

    }




}

void generate_board(int board_size_X, int board_size_Y,int* board[],int* fish_matrix[]){
    int i=0, j=0;
    for(i=0; i<board_size_X; i++){
        for(j=0; j<board_size_Y; j++){
            board[i][j]=fish_matrix[i][j];
        }

    }



}

void display_board(int board_size_X,int board_size_Y, int* board[]){
    int i,j;
    char x='A';
    printf("   ");
    for(i=0; i<2*board_size_X; i++)
    {
        printf("%c  ", x+i);
    }
    printf("\n");
    printf("   ");
    for(i=0; i<2*board_size_Y; i++)
    {
        printf("-  ");
    }
    printf("\n");
    x='A';
    for(i=0; i<board_size_X; i++)
    {
        printf("%c| ", x+i);
        if(i%2==1) printf("   ");
        for(j=0; j<board_size_Y; j++)
        {
            printf("%d     ", board[i][j]);
        }
        printf("\n");
    }
}
void penguin_place_select(int board_size_X,int board_size_Y,int* board[], int penguin)
{   int key=1; // a variable that controls the do-while loop
    int i=0,j=0; //coordinates

	do{
    printf("Enter position of penguin: \n");
	scanf("%d %d", &i,&j);
    if((i<0 || i>= board_size_X) || (j<0 || j>=board_size_Y)){ // anything tha migh make the index out of bonds
        printf("Invalid coordinates! Your board size is %d x %d \n",board_size_X-1,board_size_Y-1);
        key=1; //loop repeats
	}
	else if(board[i][j]!=1){
        printf("Chosen coordinates are either occupied by another player or have more than 1 fish! Try again \n");
        key=1; //loop repeats
	}
	else{
        board[i][j]=penguin; // the penguins codename has been inserted to the tile
        printf("Penguin succesfully placed on %d , %d ! \n",i,j);
        key=0; //the loop is terminated
    }
	}
	while(key);

}
int enough_place(int board_size_X,int board_size_Y, int* board[], int number_of_players, int penguins_per_player)
{
    if(number_of_players*penguins_per_player>=board_size_X*board_size_Y){

        return 0;
    }
    else {
    int i,j,amount;
    amount=0;
    for(i=0;i<board_size_X;i++)
    {
        for(j=0;j<board_size_Y;j++)
        {
            if(board[i][j]==1)
             amount++;
        }
    }
    if(amount <=number_of_players*penguins_per_player){
        return 0;}
    else{
    return 1;}
    }
}
int how_many_players(int board_size_X, int board_size_Y, int* board[], int penguins)
{
    int i,j;
    int p=0;
    for(i=0;i<board_size_X;i++)
    {
        for(j=0;j<board_size_Y;j++)
            if(board[i][j]>3)
                p++;

    }
    int players;
    players=p/penguins;
    return players;
}
