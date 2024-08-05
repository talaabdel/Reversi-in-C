#include <stdio.h>

void printBoard(char board[][26], int n);

int main(void) {
  int n;
  printf("Enter the board dimension: ");
  scanf("%d", &n);  // assuming n is even and less than 26
  char board[26][26];
  printBoard(board, n);

  char color, rowMove, columnMove;
  printf("Enter the board configuration: ");
  do {
    scanf("%c%c%c", &color, &rowMove, &columnMove);
    board[rowMove - 'a'][color - 'a'] = color;
  } while (!(color == '!' && rowMove == '!' && columnMove == '!'));
  printBoard(board, n);

  return 0;
}

void printBoard(char board[][26], int n) {
  for (int row = 0; row < n; row++) {
    for (int col = 0; col < n; col++) {
      if ((row == n / 2 - 1 && col == n / 2 - 1) ||
          (row == n / 2 && col == n / 2)) {
        board[row][col] = 'W';
      } else if ((row == n / 2 - 1 && col == n / 2) ||
                 (row == n / 2 && col == n / 2 - 1)) {
        board[row][col] = 'B';
      } else {
        board[row][col] = 'U';
      }
    }
  }

  printf("  ");

  // first row: abcde
  for (int row = 0; row < n; row++) {
    printf("%c", 'a' + row);
  }
  printf("\n");

  for (int row = 0; row < n; row++) {
    printf("%c ", 'a' + row);
    for (int col = 0; col < n; col++) {
      printf("%c", board[row][col]);
    }
    printf("\n");
  }
}

#include <stdbool.h>
#include <stdio.h>

void printBoard(char board[][26], int n);
void availableMoves(char board[][26], int n, char player1);
bool checkLegalInDirection(char board[][26], int n, int row, int col,
                           char colour, int deltaRow, int deltaCol);
bool positionInBounds(int n, int row, int col);

/////////////////////////////////////////////////////
int main(void) {
  int n;
  printf("Enter the board dimension: ");
  scanf("%d", &n);  // assuming n is even and less than 26
  char board[26][26];

  for (int row = 0; row < n; row++) {
    for (int col = 0; col < n; col++) {
      if ((row == n / 2 - 1 && col == n / 2 - 1) ||
          (row == n / 2 && col == n / 2)) {
        board[row][col] = 'W';
      } else if ((row == n / 2 - 1 && col == n / 2) ||
                 (row == n / 2 && col == n / 2 - 1)) {
        board[row][col] = 'B';
      } else {
        board[row][col] = 'U';
      }
    }
  }
  printBoard(board, n);

  char colour, rowMove, columnMove;
  printf("Enter the board configuration: \n");
  while (scanf(" %c%c%c", &colour, &rowMove, &columnMove) == 3 &&
         !(colour == '!' && rowMove == '!' && columnMove == '!')) {
    board[rowMove - 'a'][columnMove - 'a'] = colour;
  }
  printBoard(board, n);

  printf("Available moves for W:\n");
  availableMoves(board, n, 'W');

  printf("Available moves for B:\n");
  availableMoves(board, n, 'B');
}

/////////////////////////////////////////////////////
void printBoard(char board[][26], int n) {
  printf("  ");
  // first row: abcde
  for (int row = 0; row < n; row++) {
    printf("%c", 'a' + row);
  }
  printf("\n");

  for (int row = 0; row < n; row++) {
    printf("%c ", 'a' + row);
    for (int col = 0; col < n; col++) {
      printf("%c", board[row][col]);
    }
    printf("\n");
  }
}
/////////////////////////////////////////////////////

void availableMoves(char board[][26], int n, char player1) {
  for (int row = 0; row < n; row++) {
    for (int col = 0; col < n; col++) {
      // checking every element in array
      if (board[row][col] == 'U') {
        // once it finds an unoccupied element, it will apply each direction to
        // that element
        for (int deltaRow = -1; deltaRow <= 1; deltaRow++) {
          for (int deltaCol = -1; deltaCol <= 1; deltaCol++) {
            // only when delta row and delta col are both not 0, thenn code will
            // check if move is legal. without 0,0 total of 8 combinations
            if (deltaRow != 0 && deltaCol != 0) {
              if (checkLegalInDirection(board, n, row, col, player1, deltaRow,
                                        deltaCol)) {
                printf("%c%c", 'a' + row, 'a' + col);
              }
            }
          }
        }
      }
    }
  }
}

/////////////////////////////////////////////////////
bool positionInBounds(int n, int row, int col) {
  return (row >= 0 && row < n && col >= 0 && col < n);
}

/////////////////////////////////////////////////////
bool checkLegalInDirection(char board[][26], int n, int row, int col,
                           char colour, int deltaRow, int deltaCol) {
  int newRow = row;
  int newCol = col;

  char player2;
  if (colour == 'W') {
    player2 = 'B';
  } else {
    player2 = 'W';
  }

  for (int i = 0; i < n; i++) {
    newRow = row + i * deltaRow;
    newCol = col + i * deltaCol;
    if (!positionInBounds(newRow, newCol, n) ||
        board[newRow][newCol] != player2) {
      return false;
    } else if (board[newRow][newCol] == colour) {
      return true;
    }
  }
}
