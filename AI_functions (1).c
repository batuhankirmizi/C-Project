#include "AI_functions.h"
#include "movefunctions (1).h"
#include <stdlib.h>

/*
ALL DUMMY!
they have to be implemented for the last report

*/

void AI_penguin_place(int board_size_X, int board_size_Y,int* board[],int player){

//gotta develop a game logic here, where to place it
//you need to know which player it is to write the penguins name
	int i=0,j=0; // gotta calculate the coordinates looking at the board
	// board[i][j]=3+player; //placing the penguin
	while(1){
		 i = rand() % board_size_X;
		 j = rand() % board_size_Y;
		 if(board[i][j]==1)
		 {
			board[i][j]=player;
			break;
		 }
	}
}


void AI_penguin_move(int board_size_X, int board_size_Y, int* board[], int player, int *points){ //a move command will be given according to the game logic/st
	//first decide which penguin to move
	//int penguin = AI_which_penguin(player); //you need to know which player to decide on which penguin to move, maybe return coordinates ?
	//move the selected penguin
	//update the board
	int i,j;
	int key=0;
	int n=3;

	while(1){
 i=rand()%7;
 j=rand()%7;

 if (board[i][j]==3+player && check_if_any_movement_is_possible(board_size_X,board_size_Y,board,i,j)==1)
	break;}
 int a,b;
 for(n=3;n>=1;n--)
{
 for(a=0;a<board_size_X;a++)
 {
	 for(b=0;b<board_size_Y;b++)
	 {
		 if(n==3) { //search for field with 3 fishes
		if(board[a][b]==3 && a==i) // left 3 fishes
		 {
			 if(check_move(board_size_X,board_size_Y,board,i,j,j-b,1)==1)
			{
				 *points += board[a][b];
			board[a][b]=board[i][j];
			board[i][j]=0;
			key=1;
			break;
			}
		 }
		if(board[a][b]==3 && a==i) // right 3 fishes
		 {
			 if(check_move(board_size_X,board_size_Y,board,i,j,b-j,2)==1)
			{
				 *points += board[a][b];
			board[a][b]=board[i][j];
			board[i][j]=0;
			key=1;
			break;
			}
		 }
		  if(board[a][b]==3 && i%2==0 && (j-(i+1-a)/2)==b && (a==i-2*(j-b) || a==i-2*(j-b)+1) ) // up-left even row 3 fishes
		 {
			 if(check_move(board_size_X,board_size_Y,board,i,j,i-a,3)==1)
			{
				 *points += board[a][b];
			board[a][b]=board[i][j];
			board[i][j]=0;
			key=1;
			break;
			}
		 }
		 if(board[a][b]==3 && i%2==1 && (j-(i-a)/2)==b && (a==i-2*(j-b) || a==i-2*(j-b)-1) ) // up-left odd row 3 fishes
		 {
			 if(check_move(board_size_X,board_size_Y,board,i,j,i-a,3)==1)
			{
				 *points += board[a][b];
			board[a][b]=board[i][j];
			board[i][j]=0;
			key=1;
			break;
			}
		 }
		 if(board[a][b]==3 && i%2==0 && (j+(i-a)/2)==b && (a==i-2*(b-j) || a==i-2*(b-j)-1)) // up-right even row 3 fishes
		 {
			 if(check_move(board_size_X,board_size_Y,board,i,j,i-a,4)==1)
			{
				 *points += board[a][b];
			board[a][b]=board[i][j];
			board[i][j]=0;
			key=1;
			break;
			}
		 }
		  if(board[a][b]==3 && i%2==1 && (j+(i-a+1)/2)==b && (a==i-2*(b-j) || a==i-2*(b-j)+1) ) // up-right odd row 3 fishes
		 {
			 if(check_move(board_size_X,board_size_Y,board,i,j,i-a,4)==1)
			{
				 *points +=board[a][b];
			board[a][b]=board[i][j];
			board[i][j]=0;
			key=1;
			break;
			}
		 }
		 if(board[a][b]==3 && i%2==0 && (j-(a-i+1)/2)==b && (a==i+2*(j-b) || a==i+2*(j-b)-1) ) // down-left even row 3 fishes
		 {
			 if(check_move(board_size_X,board_size_Y,board,i,j,a-i,5)==1)
			{
				 *points += board[a][b];
			board[a][b]=board[i][j];
			board[i][j]=0;
			key=1;
			break;
			}
		 }
		 if(board[a][b]==3 && i%2==1 && (j-(a-i)/2)==b && (a==i+2*(j-b) || a==i+2*(j-b)+1) ) // down-left odd row 3 fishes
		 {
			 if(check_move(board_size_X,board_size_Y,board,i,j,a-i,5)==1)
			{
				 *points += board[a][b];
			board[a][b]=board[i][j];
			board[i][j]=0;
			key=1;
			break;
			}
		 }
		  if(board[a][b]==3 && i%2==0 && (j+(a-i)/2)==b && (a==i+2*(b-j) || a==i+2*(b-j)+1) ) // down-right even row 3 fishes
		 {
			 if(check_move(board_size_X,board_size_Y,board,i,j,a-i,6)==1)
			{
				 *points += board[a][b];
			board[a][b]=board[i][j];
			board[i][j]=0;
			key=1;
			break;
			}
		 }
		  if(board[a][b]==3 && i%2==1 && (j+(a-i+1)/2)==b && (a==i+2*(b-j) || a==i+2*(b-j)-1) ) // down-right odd row 3 fishes
		 {
			 if(check_move(board_size_X,board_size_Y,board,i,j,a-i,6)==1)
			{
				 *points += board[a][b];
			board[a][b]=board[i][j];
			board[i][j]=0;
			key=1;
			break;
			}
		 }
		 }
		 if(n==2)// search for field with 2 fishes
		 {
		  if(board[a][b]==2 && a==i) // left 2 fishes
		 {
			 if(check_move(board_size_X,board_size_Y,board,i,j,j-b,1)==1)
			{
				 *points += board[a][b];
			board[a][b]=board[i][j];
			board[i][j]=0;
			key=1;
			break;
			}
		 }
		if(board[a][b]==2 && a==i) // right 2 fishes
		 {
			 if(check_move(board_size_X,board_size_Y,board,i,j,b-j,2)==1)
			{
				 *points += board[a][b];
			board[a][b]=board[i][j];
			board[i][j]=0;
			key=1;
			break;
			}
		 }
		  if(board[a][b]==2 && i%2==0 && (j-(i+1-a)/2)==b && (a==i-2*(j-b) || a==i-2*(j-b)+1) ) // up-left even row 2 fishes
		 {
			 if(check_move(board_size_X,board_size_Y,board,i,j,i-a,3)==1)
			{
				 *points += board[a][b];
			board[a][b]=board[i][j];
			board[i][j]=0;
			key=1;
			break;
			}
		 }
		 if(board[a][b]==2 && i%2==1 && (j-(i-a)/2)==b && (a==i-2*(j-b) || a==i-2*(j-b)-1) ) // up-left odd row 2 fishes
		 {
			 if(check_move(board_size_X,board_size_Y,board,i,j,i-a,3)==1)
			{
				 *points += board[a][b];
			board[a][b]=board[i][j];
			board[i][j]=0;
			key=1;
			break;
			}
		 }
		 if(board[a][b]==2 && i%2==0 && (j+(i-a)/2)==b && (a==i-2*(b-j) || a==i-2*(b-j)-1) ) // up-right even row 2 fishes
		 {
			 if(check_move(board_size_X,board_size_Y,board,i,j,i-a,4)==1)
			{
				 *points += board[a][b];
				board[a][b]=board[i][j];
				board[i][j]=0;
				key=1;
				break;
			}
		 }
		  if(board[a][b]==2 && i%2==1 && (j+(i-a+1)/2)==b && (a==i-2*(b-j) || a==i-2*(b-j)+1)) // up-right odd row 2 fishes
		 {
			 if(check_move(board_size_X,board_size_Y,board,i,j,i-a,4)==1)
			{
				 *points += board[a][b];
			board[a][b]=board[i][j];
			board[i][j]=0;
			key=1;
			break;
			}
		 }
		 if(board[a][b]==2 && i%2==0 && (j-(a-i+1)/2)==b && (a==i+2*(j-b) || a==i+2*(j-b)-1) ) // down-left even row 2 fishes
		 {
			 if(check_move(board_size_X,board_size_Y,board,i,j,a-i,5)==1)
			{
				 *points +=board[i][j];
			board[a][b]=board[i][j];
			board[i][j]=0;
			key=1;
			break;
			}
		 }
		 if(board[a][b]==2 && i%2==1 && (j-(a-i)/2)==b && (a==i+2*(j-b) || a==i+2*(j-b)+1) ) // down-left odd row 2 fishes
		 {
			 if(check_move(board_size_X,board_size_Y,board,i,j,a-i,5)==1)
			{

				 *points += board[a][b];
			board[a][b]=board[i][j];
			board[i][j]=0;
			key=1;
			break;
			}
		 }
		  if(board[a][b]==2 && i%2==0 && (j+(a-i)/2)==b && (a==i+2*(b-j) || a==i+2*(b-j)+1)) // down-right even row 2 fishes
		 {
			 if(check_move(board_size_X,board_size_Y,board,i,j,a-i,6)==1)
			{

				 *points += board[a][b];
			board[a][b]=board[i][j];
			board[i][j]=0;
			key=1;
			break;
			}
		 }
		  if(board[a][b]==2 && i%2==1 && (j+(a-i+1)/2)==b && (a==i+2*(b-j) || a==i+2*(b-j)-1)) // down-right odd row 2 fishes
		 {
			 if(check_move(board_size_X,board_size_Y,board,i,j,a-i,6)==1)
			{
				 *points += board[a][b];
			board[a][b]=board[i][j];
			board[i][j]=0;
			key=1;
			break;
			}
		 }
		 }
		 if(n==1) // search for field with 1 fish
		 {
		  if(board[a][b]==1 && a==i) // left 1 fish
		 {
			 if(check_move(board_size_X,board_size_Y,board,i,j,j-b,1)==1)
			{
				 *points += board[a][b];
			board[a][b]=board[i][j];
			board[i][j]=0;
			key=1;
			break;
			}
		 }
		if(board[a][b]==1 && a==i) // right 1 fish
		 {
			 if(check_move(board_size_X,board_size_Y,board,i,j,b-j,2)==1)
			{
				 *points += board[a][b];
			board[a][b]=board[i][j];
			board[i][j]=0;
			key=1;
			break;
			}
		 }
		  if(board[a][b]==1 && i%2==0 && (j-(i+1-a)/2)==b && (a==i-2*(j-b) || a==i-2*(j-b)+1) ) // up-left even row 1 fish
		 {
			 if(check_move(board_size_X,board_size_Y,board,i,j,i-a,3)==1)
			{
				 *points += board[a][b];
			board[a][b]=board[i][j];
			board[i][j]=0;
			key=1;
			break;
			}
		 }
		 if(board[a][b]==1 && i%2==1 && (j-(i-a)/2)==b && (a==i-2*(j-b) || a==i-2*(j-b)-1) ) // up-left odd row 1 fish
		 {
			 if(check_move(board_size_X,board_size_Y,board,i,j,i-a,3)==1)
			{
				 *points += board[a][b];
			board[a][b]=board[i][j];
			board[i][j]=0;
			key=1;
			break;
			}
		 }
		 if(board[a][b]==1 && i%2==0 && (j+(i-a)/2)==b && (a==i-2*(b-j) || a==i-2*(b-j)-1) ) // up-right even row 1 fish
		 {
			 if(check_move(board_size_X,board_size_Y,board,i,j,i-a,4)==1)
			{
				 *points += board[a][b];
			board[a][b]=board[i][j];
			board[i][j]=0;
			key=1;
			break;
			}
		 }
		  if(board[a][b]==1 && i%2==1 && (j+(i-a+1)/2)==b && (a==i-2*(b-j) || a==i-2*(b-j)+1) ) // up-right odd row 1 fish
		 {
			 if(check_move(board_size_X,board_size_Y,board,i,j,i-a,4)==1)
			{
				 *points += board[a][b];
			board[a][b]=board[i][j];
			board[i][j]=0;
			key=1;
			break;
			}
		 }
		 if(board[a][b]==1 && i%2==0 && (j-(a-i+1)/2)==b && (a==i+2*(j-b) || a==i+2*(j-b)-1) ) // down-left even row 1 fish
		 {
			 if(check_move(board_size_X,board_size_Y,board,i,j,a-i,5)==1)
			{
				 *points += board[a][b];
			board[a][b]=board[i][j];
			board[i][j]=0;
			key=1;
			break;
			}
		 }
		 if(board[a][b]==1 && i%2==1 && (j-(a-i)/2)==b && (a==i+2*(j-b) || a==i+2*(j-b)+1) ) // down-left odd row 1 fish
		 {
			 if(check_move(board_size_X,board_size_Y,board,i,j,a-i,5)==1)
			{
				 *points += board[a][b];
			board[a][b]=board[i][j];
			board[i][j]=0;
			key=1;
			break;
			}
		 }
		  if(board[a][b]==1 && i%2==0 && (j+(a-i)/2)==b && (a==i+2*(b-j) || a==i+2*(b-j)+1)) // down-right even row 1 fish
		 {
			 if(check_move(board_size_X,board_size_Y,board,i,j,a-i,6)==1)
			{
				 *points += board[a][b];
			board[a][b]=board[i][j];
			board[i][j]=0;
			key=1;
			break;
			}
		 }
		  if(board[a][b]==1 && i%2==1 && (j+(a-i+1)/2)==b && (a==i+2*(b-j) || a==i+2*(b-j)-1) ) // down-right odd row 1 fish
		 {
			 if(check_move(board_size_X,board_size_Y,board,i,j,a-i,6)==1)
			{
				 *points += board[a][b];
			board[a][b]=board[i][j];
			board[i][j]=0;
			key=1;
			break;
			}
		 }
		 }
	 }

	 if(key==1)
		break;
		}
		if(key==1)
		break;
}
 }


int AI_which_penguin(int player){ // decide which penguin to move -> you need to know which player it is to know which penguins you can move 102
	//the idea should be to find your penguins check their surroundings and decide which one to move
	//maybe return the coordinates ?
return 1;

//It is not neccessary, i did sth else in function AI_penguin_move which works like idea of this function

}

int AI_check_if_all_placed(int board_size_X, int board_size_Y,int* board[],int penguin_count, int player){
	int i,j;
	int how_many_penguins=0;
	for(i=0;i<board_size_X;i++)
	{
		for(j=0;j<board_size_Y;j++)
		{
			if(board[i][j]==player+3)
				how_many_penguins++;
		}

	}
if(how_many_penguins==penguin_count) //check if player placed all his penguins
	return 1;
else
	return 0;

}
