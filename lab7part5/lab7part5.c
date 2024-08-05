
#include "reversi.h"

#include <stdbool.h>
#include <stdio.h>

void printBoard(char board[][26], int boardDimensions);
void availableMoves(char board[][26], int boardDimensions, char colour1);
bool checkLegalInDirection(char board[][26], int boardDimensions, int row,
                           int col, char colour1, int deltaRow, int deltaCol);
bool positionInBounds(int boardDimensions, int neighboringRowPosition1,
                      int neighboringColPosition1);
bool validateMove(char board[][26], int boardDimensions, int row, int col,
                  char userColour1);
void flipTile(char board[][26], int boardDimensions, int row, int col, char userColour1);

/////////////////////////////////////////////////////
int main(void) {
  int boardDimensions;
  printf("Enter the board dimension:");
  scanf("%d", &boardDimensions);  // assuming n is even and less than 26
  char board[26][26];             // declared 26x26 2D array

  // initialized the board
  // all elements are 'U' except the 4 in the middle of every array
  for (int row = 0; row < boardDimensions; row++) {
    for (int col = 0; col < boardDimensions; col++) {
      // iterating through each row and col
      if (row == boardDimensions / 2 - 1 && col == boardDimensions / 2 - 1) {
        board[row][col] = 'W';
      } else if (row == boardDimensions / 2 - 1 && col == boardDimensions / 2) {
        board[row][col] = 'B';
      } else if (row == boardDimensions / 2 && col == boardDimensions / 2 - 1) {
        board[row][col] = 'B';
      } else if (row == boardDimensions / 2 && col == boardDimensions / 2) {
        board[row][col] = 'W';
      } else {
        board[row][col] = 'U';
      }
    }
  }
  printBoard(board, boardDimensions);

  char colour, newRow, newCol;
  printf("Enter board configuration: \n");
  // user must be allowed to enter board configurations
  // must use some type of loop
  // while loop with the condition thattt color,row,col cant be !!!
  // if user enters !!!, exits loop
  while (colour != '!' && newRow != '!' && newCol != '!') {
    scanf(" %c%c%c", &colour, &newRow, &newCol);
    //"Character arithmetic can be used to translate the rows/columns into array
    // indices, e.g. 'b' - 'a' equals 1"
    // to gettt the element index, i wil have to subtract the letter entered -
    // 'a' now that i have both row index and col index, i can set that
    // coordinate tooo the character of the color that the user entered in the
    // doc, must print the board again but this time with the new configurations
    int indexRow = newRow - 'a';
    int indexCol = newCol - 'a';
    board[indexRow][indexCol] = colour;
  }
  printBoard(board, boardDimensions);

  printf("Available moves for W: \n");
  availableMoves(board, boardDimensions, 'W');

  // an element in 2d array is availableee ifffffffff = 'U'
  // once an element is nott occupied
  // check in all 8 directions , calling the check legal in directions function
  // only ifff the neighboring position is in bounds of array and the opposite
  // color, then continue until the color is the same,
  // then it is an available move!!

  printf("Available moves for B: \n");
  availableMoves(board, boardDimensions, 'B');

  printf("Enter a move:\n");
  char userColour1, userRow, userCol;
  scanf(" %c%c%c", &userColour1, &userRow, &userCol);

  // for example user may enter : Wbd  
  // again this must be converted to indices usinf character arhtmetics 
  int row = userRow - 'a';
  int col = userCol -'a';

  if (validateMove(board, boardDimensions, row, col, userColour1)) {
    printf("Valid move.\n");
    flipTile(board, boardDimensions, row, col, userColour1);
    printBoard(board, boardDimensions);
  } else {
    printf("Invalid move.\n");
    printBoard(board, boardDimensions);
  }

  return 0;
}

// as long as color, row, and col are not !!! -> user will be able to enter
// board configurations

// board must be printed with new configurations:
// Wac represents white color in row a, col c
// characters are represented using ASCII code

// if we have a character representing a column then if we subtractttt ut by

/////////////////////////////////////////////////////
void printBoard(char board[][26], int boardDimensions){
  // at the top of eacccccchhhhh column, a letter must be printed
  // as i iterate thruuu the columns, i add a letter
  // first column = 'a'
  // second column = 'a'+1='b'
  // and so on

  printf("  ");
  for (int col = 0; col < boardDimensions; col++) {
    printf("%c", 'a' + col);
  }
  printf("\n");

  // start of each row, print a letter
  // col is printed as usual
  for (int row = 0; row < boardDimensions; row++) {
    printf("%c ", 'a' + row);
    for (int col = 0; col < boardDimensions; col++) {
      printf("%c", board[row][col]);
    }
    printf("\n");
  }
}
/////////////////////////////////////////////////////

void availableMoves(char board[][26], int boardDimensions, char colour1) {
  bool toBePrinted = false; 
  // loop over rows and cols to check every element
  for (int row = 0; row < boardDimensions; row++) {
    for (int col = 0; col < boardDimensions; col++) {
      if (board[row][col] == 'U') {
        // at this stage, element is not occupied. must check if the move is
        // legal
        for (int deltaRow = -1; deltaRow <= 1; deltaRow++) {
          for (int deltaCol = -1; deltaCol <= 1; deltaCol++) {
            if (checkLegalInDirection(board, boardDimensions, row, col, colour1,
                                      deltaRow, deltaCol) &&
                (deltaRow != 0 || deltaCol != 0)) {
                  toBePrinted = true ;              
              break;
            }
          }
        }
      }
      if (toBePrinted) {
        printf("%c%c\n", 'a' + row, 'a' + col);
        toBePrinted = false ; 
      }
    }


  }
}


bool positionInBounds(int boardDimensions, int neighboringRowPosition1,int neighboringColPosition1) {
  return ((neighboringRowPosition1 >=0 && neighboringRowPosition1 < boardDimensions) &&(neighboringColPosition1 >= 0 &&neighboringColPosition1 < boardDimensions));
}


bool checkLegalInDirection(char board[][26], int boardDimensions, int row,int col, char colour1, int deltaRow, int deltaCol) {
  char colour2;
  if (colour1 == 'W') {
    colour2 = 'B';
  } else if (colour1 == 'B') {
    colour2 = 'W';
  }
  
  int neighboringRowPosition1 = row + deltaRow;
  int neighboringColPosition1 = col + deltaCol;

  if (!positionInBounds(boardDimensions, neighboringRowPosition1,neighboringColPosition1) || board[neighboringRowPosition1][neighboringColPosition1] != colour2) {
    return false;
  }

  // if it is in bounds and its an opposite color, then i want to keep walking
  // downnnnn in thattt deltaRow/Col direction
  while (positionInBounds(boardDimensions, neighboringRowPosition1,neighboringColPosition1) && board[neighboringRowPosition1][neighboringColPosition1] == colour2) {
      neighboringRowPosition1 = neighboringRowPosition1 + deltaRow;
      neighboringColPosition1 = neighboringColPosition1 + deltaCol;

    if (!positionInBounds(boardDimensions, neighboringRowPosition1,neighboringColPosition1))
      return false;

    if ((board[neighboringRowPosition1][neighboringColPosition1] == colour1))    
      return true; // direction and position are available move 
  }
  return false;
}


bool validateMove(char board[][26], int boardDimensions, int row, int col,char userColour1) {
  // is the move valid? first, check if its unoccupied.
  // if it is , then go through each of the 8 directions, excluding 0,0 
  // if the move is legal (which is checked through the function)
  // then we can return true .
  if (board[row][col] == 'U') {
    for (int deltaRow = -1; deltaRow <= 1; deltaRow++) {
      for (int deltaCol = -1; deltaCol <= 1; deltaCol++) {
        if (checkLegalInDirection(board, boardDimensions, row, col, userColour1 ,deltaRow, deltaCol) &&(deltaRow != 0 || deltaCol != 0)) {
        return true;
      } 
      }
    }
  }
  return false; // return false after checking alll the directions 
}

void flipTile(char board[][26], int boardDimensions, int row, int col, char userColour1){

  char colour2;
  if (userColour1 == 'W') {
    colour2 = 'B';
  } else if (userColour1 == 'B') {
    colour2 = 'W';
  }

// go thru 8 directions 
// flip onlyyy when direction is legal
// if a direction is legal, flip tiles 
// if colour 1 = 'W', all neighboring positions should be changed to colour 2 ("B") and vice versa 
for (int deltaRow = -1; deltaRow <= 1; deltaRow++) {
      for (int deltaCol = -1; deltaCol <= 1; deltaCol++) {
        if (checkLegalInDirection(board, boardDimensions, row, col, userColour1,deltaRow, deltaCol) &&(deltaRow != 0 || deltaCol != 0)) {
          int neighboringRowPosition= row + deltaRow; 
          int neighboringColPosition= col + deltaCol;
          while(positionInBounds(boardDimensions, neighboringRowPosition,neighboringColPosition) && board[neighboringRowPosition][neighboringColPosition]==colour2){
            board[neighboringRowPosition][neighboringColPosition]=userColour1;
            neighboringRowPosition+=deltaRow;
            neighboringColPosition+=deltaCol;
          }
        }
      }
}
   board[row][col]=userColour1;
}