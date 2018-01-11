#include "movefunctions (1).h"

void change_position(int board_size_X, int board_size_Y,int* board[],struct Player* p, int which_player){
    int key=1; //a value that acts as a key to the main do-while loop, removed to goto expressions
    int penguin = 0; //dummy value
    int i,j; //the coords of penguins !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    int choice=0;
    int jump=0;
    printf("Choose penguin \n");
    while(1)
    {
        scanf("%d %d",&i,&j);
        if(board[i][j]<=100 || board[i][j]/100!=which_player)
        {printf("Choose your penguin!!!\n");
        continue;
        }
        break;
    }
    do{

    while(1){ //this loop repeats it self as long as a valid choice 1-7 is given
    printf("Choose direction: \n");
    printf("Left -> 1 \n");
    printf("Right -> 2 \n");
    printf("Up-left -> 3 \n");
    printf("Up-right -> 4 \n");
    printf("Down-left -> 5 \n");
    printf("Down-right -> 6 \n");
    printf("Pass turn -> 7 \n");
    scanf("%d",&choice);
    if(choice > 0 && choice < 8){
        break;
    }
    else{
        printf("Please select an option between 1 and 7 \n");
        printf("You can skip your turn if you like! \n");
    }
    }



    switch(choice)
    {
    case 1:
        {
            printf("How many jumps? \n");
            scanf("%d", &jump);
			if(check_move(board_size_X,board_size_Y,board,i,j,jump,choice)==1) //if a movement is possible
            {
            p->points+=board[i][j-jump]; //adjusting points
            board[i][j-jump]=board[i][j]; //the code of the penguin is being copied to the new position
			board[i][j]=0; // the old position is marked with a zero, indicating an empty tile
			key=0; // the key is set to 0, which will terminate the do-while loop after the switch case is exited via break
            }
            else{ // if the specified movement is not possible, give the player a chance to reconsider
            printf("Your path is obstructed! Try another number of jumps or another direction! \n");
            key=1; //the key is set to 1 (only to show, it could have been left untouched-> it is 1 already ), the do while loop will repeat
            }
            break;
        }

    case 2: // the same algo as the previous case, didnt see reason to comment
        {
            printf("How many jumps? \n");
            scanf("%d", &jump);
			if(check_move(board_size_X,board_size_Y,board,i,j,jump,choice)==1)
           {
            p->points+=board[i][j+jump];
            board[i][j+jump]=board[i][j];
			board[i][j]=0;
			key=0;
           }
            else{
            printf("Your path is obstructed! Try another number of jumps or another direction! \n");
            key=1;
            }
            break;
        }
        case 3:
        {
            printf("How many jumps? \n");
            scanf("%d", &jump);
			if(check_move(board_size_X,board_size_Y,board,i,j,jump,choice)==1)
        {
            if(i%2==1)
            {
            p->points+=board[i-jump][j-jump/2];
            board[i-jump][j-jump/2]=board[i][j];
			board[i][j]=0;
			key=0;
            }
            else
            {
            p->points+=board[i-jump][j-(jump+1)/2];
            board[i-jump][j-(jump+1)/2]=board[i][j];
			board[i][j]=0;
			key=0;
            }

        }
        else{
            printf("Your path is obstructed! Try another number of jumps or another direction! \n");
            key=1;
        }

            break;
        }
        case 4:
            {
            printf("How many jumps? \n");
            scanf("%d", &jump);
			if(check_move(board_size_X,board_size_Y,board,i,j,jump,choice)==1)
        {
            if(i%2==0)
            {
            p->points+=board[i-jump][j+jump/2];
            board[i-jump][j+jump/2]=board[i][j];
			board[i][j]=0;
			key=0;
            }
            else
            {
            p->points+=board[i-jump][j+(jump+1)/2];
            board[i-jump][j+(jump+1)/2]=board[i][j];
			board[i][j]=0;
			key=0;
            }
        }
       else{
            printf("Your path is obstructed! Try another number of jumps or another direction! \n");
            key=1;
            }
            break;
        }
        case 5:
            {
            printf("How many jumps? \n");
            scanf("%d", &jump);
			if(check_move(board_size_X,board_size_Y,board,i,j,jump,choice)==1)
      {
             if(i%2==1)
            {
            p->points+=board[i+jump][j-jump/2];
            board[i+jump][j-jump/2]=board[i][j];
			board[i][j]=0;
			key=0;
            }
            else
            {
            p->points+=board[i+jump][j-(jump+1)/2];
            board[i+jump][j-(jump+1)/2]=board[i][j];
			board[i][j]=0;
			key=0;
            }
      }else{
            printf("Your path is obstructed! Try another number of jumps or another direction! \n");
            key=1;
            }
            break;
            }
        case 6:
        {
            printf("How many jumps? \n");
            scanf("%d", &jump);
			if(check_move(board_size_X,board_size_Y,board,i,j,jump,choice)==1)
            {
             if(i%2==0)
            {
            p->points+=board[i+jump][j+jump/2];
            board[i+jump][j+jump/2]=board[i][j];
			board[i][j]=0;
			key=0;
            }
            else
            {
            p->points+=board[i+jump][j+(jump+1)/2];
            board[i+jump][j+(jump+1)/2]=board[i][j];
			board[i][j]=0;
			key=0;
            }
            }else{
            printf("Your path is obstructed! Try another number of jumps or another direction! \n");
            key=1;
            }
            break;
        }
        case 7:
            {printf("You decided to do nothing");
            key=0;
             break;
            }





}}
while(key);


}
int check_move(int board_size_X, int board_size_Y,int* board[], int x, int y, int jump, int movement){ //dummy always correct
    int j;
if(jump<=0)
    return 0;

if(movement==1)
{
  for(j=1;j<=jump;j++)
    {   if(y-j<0 || board[x][y-j]==0 || board[x][y-j]>3)
        return 0;
    }
}

if(movement==2)
{
  for(j=1;j<=jump;j++)
    {   if(y+j>board_size_Y-1 || board[x][y+j]==0 || board[x][y+j]>3)
        return 0;}
}

if(movement==3)
{
  for(j=1;j<=jump;j++)
   {
       if(x%2==0)
        {   if(x-j<0 || (y-j/2)<0 || board[x-j][y-j/2]==0 || board[x-j][y-j/2]>3)
            { return 0;}
        }
    if(x%2==1)
        {   if(x-j<0 || (y-(j+1)/2)<0 || board[x-j][y-(j+1)/2]==0 || board[x-j][y-(j+1)/2]>3)
            { return 0;}
        }
    }
}

if(movement==4)
{
  for(j=1;j<=jump;j++)
   {
       if(x%2==1)
    {   if(x-j<0 || (y+j/2)>board_size_Y-1 || board[x-j][y+j/2]==0 || board[x-j][y+j/2]>3)
        { return 0;}
    }
    if(x%2==0)
    {   if(x-j<0 || (y+(j+1)/2)>board_size_Y-1 || board[x-j][y+(j+1)/2]==0 || board[x-j][y+(j+1)/2]>3)
        {return 0;}
    }
}
}

if(movement==5)
{
  for(j=1;j<=jump;j++)
   {
       if(x%2==0)
    {   if(x+j>board_size_X-1 || (y-j/2)<0 || board[x+j][y-j/2]==0 || board[x+j][y-j/2]>3)
        { return 0;}
    }
    if(x%2==1)
    {   if(x+j>board_size_X-1 || (y-(j+1)/2)<0 || board[x+j][y-(j+1)/2]==0 || board[x+j][y-(j+1)/2]>3)
        { return 0;}
    }
}
}

if(movement==6)
{
  for(j=1;j<=jump;j++)
   {
       if(x%2==1)
    {   if(x+j>board_size_X-1 || (y+j/2)>board_size_Y-1 || board[x+j][y+j/2]==0 || board[x+j][y+j/2]>3)
        { return 0;}
    }
    if(x%2==0)
    {   if(x+j>board_size_X-1 || (y+(j+1)/2)>board_size_Y-1 || board[x+j][y+(j+1)/2]==0 || board[x+j][y+(j+1)/2]>3)
       { return 0;}
    }
}
}
return 1;
}
 //not ready
//void count_points(int* board[],struct Player *p, int x, int y){}
int penguins_movement(int board_size_X, int board_size_Y, int* board[],int penguins_per_player, int player){
   int i,j,k,p;
p=0;
for(i=0;i<board_size_X;i++)
{
    for(j=0;j<board_size_Y;j++)
    {
        if(board[i][j]/100==player)
        {
            for(k=0;k<6;k++)
            {
                if(check_move(board_size_X,board_size_Y,board,i,j,1,k+1)==0)
                p++;

            }
            if(p%6!=0)
                break;
        }

    }
}
if(p==6*penguins_per_player)
    return 0;
else
    return 1;

}
