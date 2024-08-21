#include <stdio.h>
char arr[10]={'0','1','2','3','4','5','6','7','8','9'};

void showBoard();
int checkWin();
void system();

void main(){
    int player = 1;
    int input , status = -1;
    char mark; // 'x' or 'o'
    showBoard();
    
   while(status == -1)
   {
    player = (player%2==0) ?  2: 1;
    mark = (player==1)? 'X':'O';
    printf("Please enter number for player%d\n",player);
    scanf("%d",&input);
    if(input<1 || input>9){
        printf("Invalid input");
    }
    arr[input]=mark;
    
    showBoard();

    int result = checkWin();
    if(result == 1){
        printf("player %d is winner",player);
        return;
    }else if (result == 0){
        printf("Draw");
        return;
    }
    player++;

   }    
}

void showBoard(){
    system("cls");
    printf("\n\n");
    printf("---  Tic Tac Toe  ---\n\n");
    printf("       |       |     \n");
    printf("  %c    |   %c   |  %c \n",arr[1],arr[2],arr[3]);
    printf("_______|_______|_______\n");
    printf("       |       |     \n");
    printf("  %c    |   %c   |  %c \n",arr[4],arr[5],arr[6]);
    printf("_______|_______|_______\n");
    printf("       |       |     \n");
    printf("  %c    |   %c   |  %c \n",arr[7],arr[8],arr[9]);
    printf("_______|_______|_______\n");
    printf("       |       |     \n");
    printf("       |       |     \n");
    printf("\n");
    
}

int checkWin(){
    if(arr[1]==arr[2] && arr[2]==arr[3]){
        return 1;
    }
    if(arr[1]==arr[4] && arr[4]==arr[7]){
        return 1;
    }
    if(arr[4]==arr[5] && arr[5]==arr[6]){
        return 1;
    }
    if(arr[2]==arr[5] && arr[5]==arr[8]){
        return 1;
    }
    if(arr[7]==arr[8] && arr[8]==arr[9]){
        return 1;
    }
    if(arr[3]==arr[6] && arr[6]==arr[9]){
        return 1;
    }
    if(arr[1]==arr[5] && arr[5]==arr[9]){
        return 1;
    }
    if(arr[3]==arr[5] && arr[5]==arr[7]){
        return 1;
    }
    
    int count=0;
    for(int j =1; j<=9; j++){
        if(arr[j]=='X' || arr[j]=='O'){
            count++;
        }
    }
    if(count == 9){
        return 0;
    }
    return -1;
}