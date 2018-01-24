#include "input_output_functions.h"
#include <stdio.h>
#include <string.h>

 int check_existing_of_player(char* filenanme,char* name)
	{
		FILE *fp;
	fp = fopen(filenanme , "r");
	if(fp == NULL) { //coundt open the file
	perror("Error opening file");
	}
	else
	{
char temp[512];
while(fgets(temp, 512, fp) != NULL) {
	if(strstr(temp,name)!=NULL)
	{ fclose(fp);
		return 1;
	}
else
	{
		fclose(fp);
		return 0;
	}
}


	}
	}

int line_count_in_text_file(char* file_name) {
	FILE *fp = fopen(file_name, "r");

	int i = 0;
	char line[250];
	while(fgets(line, sizeof(line), fp))
		i++;
	fclose(fp);
	return i;
}



int check_player_name(char* file_name, char *player_name) {
	FILE *fp = fopen(file_name, "r");
	char ch[250];
	char teamname[100];
	int j = 0;
	char temp;

	for(int i = 0; i < line_count_in_text_file(file_name); ++i) {
		fgets(ch, sizeof(ch), fp);
		if(strcmp(ch, "Programs and their score:\n") == 0) {
			while((temp = fgetc(fp)) != ':') {
				teamname[j] = temp;
				j++;
			} // player1
			teamname[j] = '\0'; // player1\0
			if(strcmp(teamname, player_name) == 0) {
				fclose(fp);
				return 1;
			} else {
				j = 0;
			}
		}
	}

	fclose(fp);
	return 0;
}

int get_points(char* file_name, char *player_name) {
	FILE *fp = fopen(file_name, "r");
	int point = 0;
	{
		char ch[250];
		char temp;
		char teamname[40];
		int j = 0, k = 0;

		for(int i = 0; i < line_count_in_text_file(file_name); ++i) {
			fgets(ch, sizeof(ch), fp);
			if(strcmp(ch, "Programs and their score:\n") == 0) {
				while((temp = fgetc(fp)) != ':') {
					teamname[j] = temp;
					j++;
				} // player1
				teamname[j] = '\0'; // player1\0
				if(strcmp(teamname, player_name) == 0) {
					fscanf(fp, "%d", &point);
					return point;
				} else {
					j = 0;
				}
			}
		}
	}
	
	return point;
}

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
void read_from_text_file_and_create_board(int board_size_X,int board_size_Y,int* board[],char *filenanme, char *name){
	FILE *fp;
	fp = fopen(filenanme , "r");
	if(fp == NULL) {
	  perror("Error opening file");

   }
   else {
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
			}
		}

		fprintf(fp, "Programs and their score:\n");
		if(!check_existing_of_player(filenanme, name)) {
			fprintf(fp, "%s: %d", name, get_points(filenanme, name));
		}

		fclose(fp);
		}
}
/*
Can later add the functionality to read and write scores/points, didnt seemed necessary now since we didnt agree on a format
*/

void write_to_text_file(int board_size_X, int board_size_Y,int* board[],char *filenanme, char *name, int points){
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
					fprintf(fp, "%d ", board[i][j]);
				}
				else{
					fprintf(fp, "%d\n", board[i][j]);
				}
		}

		}
		fprintf(fp,"Programs and their score:\n");
		for(i = 0; i < strlen(name); i++) {
			fprintf(fp, "%c", name[i]);
		}
		fprintf(fp, ": %d", points);
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
