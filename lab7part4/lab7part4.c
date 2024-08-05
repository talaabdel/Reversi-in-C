//
// Author: Tala Abdelmaguid
//

#include "reversi.h"
#include <stdio.h>

void printBoard(char board[][26], int n) {
    // all the elements are 'U'. the 4 middle ones are "WB" and "BW"
    for (int row=0; row<n; row++){
        for (int col=0; col<n; col++){
            board[row][col] = 'U';
            if (((n==row/2) -1) && ((n==col/2)-1)){
                 board[row][col]= 'W';
            } else if (((n==row/2)-1) && ((n==col/2))){
                board[row][col]='B';
            } else if ((n==row/2) && ((n==col/2)-1)){
                board [row][col]='B';
            } else if (((n==row/2)) && ((n==col/2))){
                board[row][col]='W';
            }
        }
    }
}

        /*
4 middle elements location
row /2 -1 and col/2 -1          row/2-1 and col/2
(row/2) and col/2 -1            row/2  and col/2
*/


bool positionInBounds(int n, int row, int col) {
}

bool checkLegalInDirection(char board[][26], int n, int row, int col,
                           char colour, int deltaRow, int deltaCol) {
}

int main(void) {
    int n;
    printf("Enter the board dimension: ");
    scanf("%d", n);
    char board[n][n];
    printBoard(board, n);

  return 0;
}
