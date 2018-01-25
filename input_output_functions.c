#include "input_output_functions.h"
#include <stdio.h>
#include <string.h>
#include "boardfunctions (1).h"

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

int has_players(char* file_name) {
	FILE *f = fopen(file_name, "r");
	char ch[250];

	for(int i = 0; i < line_count_in_text_file(file_name); ++i) {
		fgets(ch, sizeof(ch), f);
		if(strcmp(ch, "Programs and their score:\n") == 0) {
			fclose(f);
			return 1;
		}
	}

	fclose(f);
	return 0;
 }

int player_count_p(char* file_name, player** p) {
	if(*p == NULL || (*p)->team_name == NULL) return 0;

	int s = 0;
	player *iter = *p;
	while(iter != NULL) {
		s++;
		iter = iter->next;
	}
	return s;

	//FILE *f = fopen(file_name, "r");
	// if(has_players(file_name) == 0) { // if game does not contains any players, return 0
	//	 fclose(f);
	//	 return 0;
	// }

	// char ch[250];
	// int count = 0;
	// for(int i = 0; i < line_count_in_text_file(file_name); ++i) {
	//	 fgets(ch, sizeof(ch), f);
	//	 if(strcmp(ch, "Programs and their score:\n") == 0) {
	//		 count = 1;
	//	 }
	//	 if(count > 0) count++;
	// }
	// return count;
}

int player_count(char* file_name) {
	return line_count_in_text_file(file_name) - 9 < 0 ? 0 : line_count_in_text_file(file_name) - 9;
}

char* get_team(char* file_name, int team_id) {
	FILE *fp = fopen(file_name, "r");
	int point = 0;
	{
		char ch[250];
		char temp;
		char teamname[40];
		int j = 0, id = 0;

		for(int i = 0; i < line_count_in_text_file(file_name); ++i) {
			fgets(ch, sizeof(ch), fp);
			if(strcmp(ch, "Programs and their score:\n") == 0) {
				if(id == team_id) {
					while((temp = fgetc(fp)) != ':') {
						teamname[j] = temp;
						j++;
					} // player1
					teamname[j] = '\0'; // player1\0
					return teamname;
				}
				id++;
			}
		}
	}

	return "";
}

int get_id(char* file_name, char* team_name) {
	FILE *f = fopen(file_name, "r");
	int id = 4;
	{
		char ch[250];
		char temp;
		char teamname[40];
		int j = 0;

		for(int i = 0; i < line_count_in_text_file(file_name); ++i) {
			fgets(ch, sizeof(ch), f);
			if(strcmp(ch, "Programs and their score:\n") == 0) {
				while((temp = fgetc(f)) != ':') {
					teamname[j] = temp;
					j++;
				} // player1
				teamname[j] = '\0'; // player1\0
				if(strcmp(teamname, team_name) != 0) {
					id++;
					j = 0;
					break;
				}
			}
		}
	}
	return id;
}

int get_number_for_new_player(char* file_name, player** p) {
	return player_count(file_name) + 4;
}

int get_penguin_count_of(char* file_name, char* team_name, int id) {
	FILE *f = fopen(file_name, "r");

	// and then we can count the id's in the board
	char temp;
	int count = 0;

	char ch[150];
	fgets(ch, sizeof(ch), f);
	while((temp = getc(f)) != EOF) {
		if(temp != ' ')
			if(temp - '0' == id) count++;
	}
	
	return count;
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
	FILE *fp = fopen(filenanme, "r"); //file pointer

	int b_s = getc(fp) - '0';

   fclose(fp);
   return b_s; //returns -1 if something is wrong


}

int get_board_size_Y(char *filenanme){ //gets the boardsize from the text file
	FILE *f = fopen(filenanme, "r");

	char str[4];
	fgets(str, sizeof(str), f);

	fclose(f);
	return str[2] - '0';
}
void read_from_text_file_and_create_board(int board_size_X,int board_size_Y, int *board[],char *filenanme, player **players, int _p_size){
	FILE *fp = fopen(filenanme , "r");
	if(fp == NULL) {
	  perror("Error opening file");

   }
   else {
		//just getting rid of the board size 7,7 part, probably there is a better way :)
	int x;
	   char y;
	   fscanf(fp, "%d", &x);
	   fscanf(fp, "%c", &y);
	   fscanf(fp, "%d", &x);

	   //taking the fish info from the board and copying it to the board
	   int i = 0, j = 0;
	   for(i = 0; i<board_size_X; i++) {
		   for(j = 0; j<board_size_Y; j++) {
			   fscanf(fp, "%d", &board[i][j]);
		   }
	   }

	   player *iter = *players;
	   while(iter) {
		   fprintf(fp, "%s: %d\n", iter->team_name, iter->points);
		   iter = iter->next;
	   }

		/*fprintf(fp, "Programs and their score:\n");
		for (i = 0; i < _p_size; ++i) {
			fprintf(fp, "%s: %d\n", players[i]->team_name, players[i]->points);
		}*/

		fclose(fp);
		}
}
/*
Can later add the functionality to read and write scores/points, didnt seemed necessary now since we didnt agree on a format
*/

void write_to_text_file(int board_size_X, int board_size_Y,int* board[],char *filenanme, player **p, int _p_size){
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
		for (i = 0; i < _p_size; ++i) {
			fprintf(fp, "%s: %d\n", (*p)->team_name, (*p)->points);
			(*p) = (*p)->next;
		}
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
