#include <stdio.h>


void printBoard(char board[][26], int n);

int main(void) {
    
    int n;
    printf("Enter the board dimension: ");
    scanf("%d", &n); // assuming n is even and less than 26 
    char board[26][26];
    printBoard(board,n);

    char color, rowMove, columnMove; 
    printf("Enter the board configuration: ");
    do{
        scanf("%c%c%c", &color, &rowMove, &columnMove);
        board[rowMove - 'a'][color - 'a'] = color;
    } while(!(color=='!' && rowMove=='!' && columnMove=='!'));
    printBoard(board, n);

  return 0;
}

void printBoard(char board[][26], int n) {
    for (int row=0; row<n; row++){
        for (int col=0; col<n; col++){
             if ((row == n/2-1 && col==n/2-1) || (row==n/2 && col==n/2)){
                board[row][col] = 'W';
            } else if ((row == n/2-1 && col==n/2) || (row==n/2 && col==n/2-1)){
                board[row][col] = 'B';
            } else{
                board[row][col] = 'U';
        }
    }
    }
    
   printf("  "); 
   // first row: abcde
   for (int row=0; row<n;row++){
    printf("%c",'a' + row);
    }
    printf("\n");

    for(int row=0; row<n;row++){
        printf("%c ", 'a'+row);
        for(int col=0; col<n; col++){
            printf("%c", board[row][col]);
        }
        printf("\n");

    }
}
