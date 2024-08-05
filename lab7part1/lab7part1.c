//
// Author: Tala Abdelmaguid 
//

#include "reversi.h"
#include <stdio.h>


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


    /* 
    1. ask for dimensions
    2. everywhere on the board: 'U'
    3. 4 middle elements are WB and BW
    4. first row: abcde (until however many dimenions) 
    5. first column: abcde (space between that and 2d array)
    */

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

//////////////////////////////////////////////////////////////////
bool positionInBounds(int n, int row, int col) {
}

////////////////////////////////////////////////////////////////
bool checkLegalInDirection(char board[][26], int n, int row, int col,
                           char colour, int deltaRow, int deltaCol) {
}

////////////////////////////////////////////////////////////////

/*
U - for unoccupied
B - occupied by black
W - occupied by white
*/

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
