#include "input_output_functions.h"
#include <stdio.h>
#include <string.h>


int get_board_size_X(char *filenanme){ //gets the boardsize from the text file
    int board_size=-1;
    FILE *fp; //file pointer
    char str[5]; //buffer
    fp = fopen(filenanme , "r");
    if(fp == NULL) { //coundt open the file
      perror("Error opening file");
      return(-1);
   }
   else{
       fgets (str, 5, fp); //takes the fist line 7,7
        board_size=(str[0]- '0'); //take the first element and convert it to an int
   }

   fclose(fp);
   return board_size; //returns -1 if something is wrong


}

int get_board_size_Y(char *filenanme){ //gets the boardsize from the text file
    int board_size=-1;
    FILE *fp; //file pointer
    char str[5]; //buffer
    fp = fopen(filenanme , "r");
    if(fp == NULL) { //coundt open the file
      perror("Error opening file");
      return(-1);
   }
   else{
       fgets (str, 5, fp); //takes the fist line 7,7
        board_size=(str[2]- '0'); //take the first element and convert it to an int
   }

   fclose(fp);
   return board_size; //returns -1 if something is wrong


}
void read_from_text_file_and_create_board(int board_size_X,int board_size_Y,int* board[],char *filenanme ){
    FILE *fp;
    fp = fopen(filenanme , "r");
    if(fp == NULL) {
      perror("Error opening file");

   }
   else{
        //just getting rid of the board size 7,7 part, probably there is a better way :)
        int x;
        char y;
        fscanf(fp,"%d",&x);
        fscanf(fp,"%c",&y);
        fscanf(fp,"%d",&x);


        //taking the fish info from the board and copying it to the board
        int i=0, j=0;
        for(i=0; i<board_size_X; i++){
        for(j=0; j<board_size_Y; j++){
            fscanf(fp,"%d",&board[i][j]);
        }}

        fclose(fp);
        }



}
/*
Can later add the functionality to read and write scores/points, didnt seemed necessary now since we didnt agree on a format


*/

void write_to_text_file(int board_size_X, int board_size_Y,int* board[],char *filenanme, char* name){
    FILE *fp;
    fp = fopen(filenanme , "w");
    if(fp == NULL) { //coundt open the file
    perror("Error opening file");
   }
   else{

    //some mumbo jumbo to creat the exact format like the input file
    fprintf(fp, "%d,%d\n", board_size_X,board_size_Y);
    int i,j;
    for(i=0;i<board_size_X;i++){
        if((i%2)){
            fprintf(fp," "); //puts a white space to every second line
        }
        for(j=0;j<board_size_Y;j++){
                if (j<(board_size_Y-1)){
                fprintf(fp,"%d ",board[i][j]);}
                else{
                fprintf(fp,"%d\n",board[i][j]);
                }
        }

        }
        fprintf(fp,"Programs and their score:\n");
    for(i=0;i<strlen(name);i++)
    {
    fprintf(fp,"%c",name[i]);
    }
    fprintf(fp,":%d",0);

    }



    fclose(fp);
    }

/*void write_players(char* filename, char* name)
{
    FILE *fp;
    int i;
    fp = fopen(filename , "w");
    if(fp == NULL) { //coundt open the file
    perror("Error opening file");
    }
    else{
    for(i=0;i<strlen(name);i++)
    {
        fprintf(fp,"%c",name[i]);
    }
    }

}*/
