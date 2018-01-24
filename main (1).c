#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <string.h>
#include "input_output_functions.h"
#include "AI_functions.h"
#include "player_list.h"

int points = 0;

player *head = NULL;

int main(int argc, char *argv[]) {
#if 0//MAKE if 1 to run this part interactive part

	srand(time(NULL)); //random seed
	int board_size_X;
	int board_size_Y;
	printf("Enter board size: \nX: ");
	scanf("%d", &board_size_X);
	printf("Y: ");
	scanf("%d",&board_size_Y);

	int i=0;
	int j=0;

	int** board=(int **)malloc(board_size_X* sizeof(int *));
	for (i=0; i<board_size_X; i++)
		 board[i] = (int *)malloc(board_size_Y * sizeof(int)); //actual grid NxN
	int** fish_matrix= (int **)malloc(board_size_X* sizeof(int *));
	for (i=0; i<board_size_Y; i++)
		 fish_matrix[i] = (int *)malloc(board_size_Y* sizeof(int));;; // another temporary NxN grid

	int number_of_players=0;
	int penguins_per_player=0;




	FILE *myFile =  fopen("Penguins_input.txt","r"); //File opened in read mode
	if (!myFile){
	   printf("Error! Could not open file");

	   exit(1);
   }


	input_data(&number_of_players,&penguins_per_player); // the player details and game setting has been acquired.

	struct Player player1[number_of_players];  // a list of players -type Struct Player has been created
	create_players(player1,number_of_players,penguins_per_player); //populates the player list



	generate_fish_network(board_size_X,board_size_Y,fish_matrix,myFile); //the fish placement, read from the txt file
	generate_board(board_size_X,board_size_Y,board,fish_matrix);

	if(enough_place(board_size_X,board_size_Y,board, number_of_players,penguins_per_player)==0)
	{
	 printf("Board is too small!!!\n");
	 exit(0);
	}

	display_board(board_size_X,board_size_Y,board); //shows the board for the first time


	for(i=0; i<penguins_per_player; i++)
	{
		for(j=0; j<number_of_players; j++)
		{
			printf("Player %d\n", j+1); //changed also to reflect the correct player number
			penguin_place_select(board_size_X,board_size_Y,board,player1[j].penguins[i]);
			display_board(board_size_X,board_size_Y, board);
		}
	}


	for(i=0;i<20;i++)
	{

	 if(penguins_movement(board_size_X,board_size_Y,board,penguins_per_player,i%number_of_players+1)==0)
	 {
		 printf("Player %d can't move. \n",i%number_of_players+1);
		 continue;
	 }

	printf("Player %d: \n",i%number_of_players+1);
	change_position(board_size_X,board_size_Y, board,&player1[i%number_of_players],i%number_of_players+1);
	system("cls");
	display_board(board_size_X,board_size_Y, board);
	printf("Points P%d: %d \n",i%number_of_players+1, player1[i%number_of_players].points);

	}
	  {
		  printf("Player %d points: %d \n",i+1,player1[i].points);
	  }

#else  //make #if 0 upwards, to run this part

 srand(time(NULL));
		if (argc == 5){ // Format : -> player1.out phase=placement penguins=3 inputboard.txt outpuboard.txt
			/*
			argv[0]= player1.out // or the name of the program
			argv[1]= phase=placement
			argv[2]= penguins=3
			argv[3]= inputboard.txt
			argv[4]= outpuboard.txt


			*/
			if(strcmp(argv[1],"phase=placement") == 0) { // if they are equal -> the second parameter phase=placement
				printf("Gotta do what you gotta do \n"); // execute accordingly
				int player_number = argv[0][6] - '0'; // use 1 to simplify and to get chance to compile our program in codeblocks //taking the player number as an int - e.g 1,2 etc. assuming program name player1, player2 etc. returns something stupid when you call it from codeblocks, need to command line compile
				int penguin_count = argv[2][9] - '0'; //penguin count acquired as an int -> converting from char to int
				printf("penguin count %d\n",penguin_count); //DEBUGGING PURPOSE
			   // printf("% d", atoi(argv[2][9]));
				//argv[3] is the input text file's name
				//argv[4] is the output files name

				int board_size_X=get_board_size_X(argv[3]); // get the board side X
				int board_size_Y=get_board_size_Y(argv[3]); // get the board side Y
				printf("board_size : %d\n",board_size_X); //DEBUGGING PURPOSE
				int** board=(int**)malloc(board_size_X* sizeof(int *));
				int i;
				for (i=0; i<board_size_Y; i++)
					board[i] = (int *) malloc(board_size_Y * sizeof(int)); // create the board, static, can be converted to dynmic if need be
				int points = 0;
				if(exists(head, argv[0]) == 0)
					add_player(head, argv[0], penguin_count);
				read_from_text_file_and_create_board(board_size_X,board_size_Y,board,argv[3],argv[0]); //read the info from the text file, populate the board

				if(AI_check_if_all_placed(board_size_X,board_size_Y,board,penguin_count,player_number)==0){ //still there are penguins to place
						AI_penguin_place(board_size_X,board_size_Y,board,player_number, &points);
				}
				else{ //all penguins have been placed
					printf("No more penguins to place \n");
					exit(1);

				}
				write_to_text_file(board_size_X,board_size_Y,board,argv[4],argv[0], points); //write to another text file after everything has been done



			}
			else{ // the argument count is ok but the second parameter is not phase=placement
				printf("Sorry, there is a mismatch in the arguments, try again!(phase=placement)");
				exit(1);
			}

	}
	// PHASE = MOVEMENT, argument count 4
	else if(argc == 4){ // Format : -> player1.out phase=movement board4.txt board5.txt
			if(strcmp(argv[1],"phase=movement") == 0){  // if they are equal -> the second parameter phase=movement
			//how_many_players(board_size_X, board_size_Y, board);
				printf("Gotta do what you gotta do \n"); // execute accordingly
				int player_number =argv[0][6]-'0'; //taking the player number as an int - e.g 1,2 etc.
				//argv[2] is the input text file's name
				//argv[3] is the output file's name

				int board_size_X=get_board_size_X(argv[2]); // get the board side X
				int board_size_Y=get_board_size_Y(argv[2]); // get the board side Y
				int** board=(int**)malloc(board_size_X* sizeof(int*));
				int i;
				for (i=0; i<board_size_X; i++)
				board[i] = (int *)malloc(board_size_Y * sizeof(int));
				char* names[200];
				read_from_text_file_and_create_board(board_size_X,board_size_Y,board,argv[2],names); //read the board configuration and store it in board
				
				char player_name[8] = "player1";
				points = get_points(argv[2], player_name);
				AI_penguin_move(board_size_X,board_size_Y,board,player_number, &points); // AI_function moves the penguin to some place - not implemented

				//change_points(argv[3],argv[0],&points);
				write_to_text_file(board_size_X,board_size_Y, board, argv[3], argv[0], points); //writes the final board config




				}



			else{ // the arguments given do not match
				printf("Sorry, there is a mismatch in the arguments, try again! (phase=movement)");
				exit(1);
			}

	}

	else{// The argument count is invalid, neither 4 nor 5
		printf("Sorry, there is a mismatch in the arguments, try again! (Neither placement nor movement)");
		exit(1);



	}

	#endif
	return 0;
}
