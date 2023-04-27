/*
  Members:
  AZARCON, Aden
  SAYO, Trisha Alissandra
  VILLAVICENCIO, Josh Dane
  Section: S20

  Instructor: Ms. Shirley Chu
  Date Submitted: June 20, 2020
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char String30[31]; // String30 alias is to be used with a string that represents a name
typedef struct nextMove // nextMove contains previous and next coordinates from user input
{
  int prev[2]; // index 0 contains x-coordinate, index 1 contains y-coordinate
  int next[2]; // index 0 contains x-coordinate, index 1 contains y-coordinate
} NextPlayerMove;

#include "MP-Functions.c"

int main()
{
  // Applicable Sets
  int E[5][2] = {{6, 2}, {6, 4}, {7, 1}, {7, 3}, {7, 5}};
  int Y[5][2] = {{2, 2}, {2, 4}, {1, 1}, {1, 3}, {1, 5}};

  // System Variables
  int Alpha[5][2];
  int Beta[5][2];
  int aTurn;   // Either 1 (Alpha) or 0 (Beta), turn of Alpha or Beta
  int over;    // Either 1 (True) or 0 (False), if game is done/over
  int ok;      // Either 1 (True) or 0 (False), if valid move of user
  char result; // Either A (Alpha Wins) or B (Beta Wins) or D (Draw),

  // Supplementary Variables
  NextPlayerMove nMove;
	int indexA, indexB; /* used to point the index of either Alpha (indexA) or Beta (indexB) that was moved
                        will be used in updating the coordinates of the certain piece */
  String30 Player1, Player2;
  char BOARD[5][7]; // Underscore for free spaces and 'A' for alpha and 'B' for beta. 
  int i, j;

  // System Initialization
  over = 0, ok = 0, aTurn = 1;

  // initialize board array values from alpha and beta array
  for (i = 0; i < 5; i++) // iterates per row
  {
    for (j = 0; j < 7; j++) // iterates per column
      BOARD[i][j] = '_';
  }
  // initialize alpha pieces from set E and beta pieces from set Y
  for (i = 0; i < 5; i++) // iterates per row
  {
    for (j = 0; j < 2; j++) // iterates per column
    {
      Alpha[i][j] = E[i][j];
      Beta[i][j] = Y[i][j];
    }
  }
  // initialize Alpha and Beta pieces to board
  for(i = 0; i < 5; i++)
  {
    BOARD[Alpha[i][1]-1][Alpha[i][0]-1] = 'A';
    BOARD[Beta[i][1]-1][Beta[i][0]-1] = 'B';
  }
  

  // Pre-Game: Main Menu
  displayMenu(&Player1, &Player2); // array pointer to change value

  // Game Proper: System States and Behavior
  do
	{
    system("cls"); // Clear previous lines
    printf("\nTo move a piece, Input (x,y) coordinates like this:\n");
    printf("<x coordinate><space><y coordinate>\n");
    printf("Example: If you wish to move to (3,5), input: 3 5\n");
    displayBoard(BOARD); // displays the board

    if (aTurn) // aTurn starts at 1, meaning alpha starts move
    {
      printf("It's your turn, %s! (Alpha)\n", Player1);
      printf("Input the coordinates of the piece you wish to move: ");
      scanf("%d %d", &nMove.prev[0], &nMove.prev[1]);
      printf("Now input the coordinates of the space you want to move to: ");
      scanf("%d %d", &nMove.next[0], &nMove.next[1]);
      while (!ok)
      {
        /* checks if selected piece to be moved is a valid piece
				and if the chosen space to move to is a valid space */ 
				if(
              isAlpha(Alpha,nMove.prev) &&
              !isAlpha(Alpha,nMove.next) &&
              (nMove.prev[0] >= 1 && nMove.next[0] >= 1) && // min
              (nMove.prev[0] <= 7 && nMove.next[0] <= 7) && // max
              (nMove.next[1] >= 1 && nMove.next[1] >= 1) && // min
              (nMove.next[1] <= 5 && nMove.next[1] <= 5) && // max

              (nMove.prev[0] == nMove.next[0] + 1) && // Can move one column to the left
              ((nMove.prev[1] == nMove.next[1] + 1) || // Can move one row above
               (nMove.prev[1] == nMove.next[1] - 1)) // Can move one row below
					)
				{
					indexA = isAlpha(Alpha,nMove.prev) - 1;
					ok = !ok;
				}
				else
				{
          printf("WARNING: Invalid input\n\a");
          printf("Please input the coordinates of the piece you wish to move: ");
      		scanf("%d %d", &nMove.prev[0], &nMove.prev[1]);
      		printf("Please input the coordinates of a valid space you want to move to: ");
      		scanf("%d %d", &nMove.next[0], &nMove.next[1]);
				}
      }
    }
		else // aturn is 0, meaning beta has the move
    {
      printf("It's your turn, %s! (Beta)\n", Player2);
      printf("Input the coordinates of the piece you wish to move: ");
      scanf("%d %d", &nMove.prev[0], &nMove.prev[1]);
      printf("Now input the coordinates of the space you want to move to: ");
      scanf("%d %d", &nMove.next[0], &nMove.next[1]);
      while (!ok)
      {
        /* checks if selected piece to be moved is a valid piece
				and if the chosen space to move to is a valid space */ 
				if(
              isBeta(Beta,nMove.prev) &&
              !isBeta(Beta,nMove.next) &&
              (nMove.prev[0] >= 1 && nMove.next[0] >= 1) && // min
              (nMove.prev[0] <= 7 && nMove.next[0] <= 7) && // max
              (nMove.next[1] >= 1 && nMove.next[1] >= 1) && // min
              (nMove.next[1] <= 5 && nMove.next[1] <= 5) && // max

              (nMove.prev[0] == nMove.next[0] - 1) && // Can move one column to the left
              ((nMove.prev[1] == nMove.next[1] + 1) || // Can move one row above
               (nMove.prev[1] == nMove.next[1] - 1)) // Can move one row below
					)
				{
					indexA = isBeta(Beta,nMove.prev) - 1;
					ok = !ok; // confirm validation of user input
				}
				else
				{
          printf("WARNING: Invalid input\n\a");
          printf("Please input the coordinates of the piece you wish to move:");
      		scanf("%d %d", &nMove.prev[0], &nMove.prev[1]);
      		printf("Please input the coordinates of a valid space you want to move to: ");
      		scanf("%d %d", &nMove.next[0], &nMove.next[1]);
				}
      }
    }

		if(ok) // if ok is true, meaning move is valid
		{
			if(aTurn) // aTurn is 1, meaning code is for Alpha
			{
				if(isFree(Alpha,Beta,BOARD,nMove.next)) // next is on a free space
				{
                     Alpha[indexA][0] = nMove.next[0]; // x coordinate
					Alpha[indexA][1] = nMove.next[1]; // y coordinate
                    BOARD[nMove.next[1]-1][nMove.next[0]-1] = 'A';
                    BOARD[nMove.prev[1]-1][nMove.prev[0]-1] = '_';
					aTurn = !aTurn; // switch player
					ok = !ok; // revert to invalidation
				}
				else if((indexB = isBeta(Beta,nMove.next) - 1) > -1) // next is on a Beta piece
				{
					Alpha[indexA][0] = nMove.next[0]; // x coordinate
					Alpha[indexA][1] = nMove.next[1]; // y coordinate
					Beta[indexB][0] = -1;
					Beta[indexB][1] = -1;
                    BOARD[nMove.next[1]-1][nMove.next[0]-1] = 'A';
                    BOARD[nMove.prev[1]-1][nMove.prev[0]-1] = '_';
					aTurn = !aTurn; // switch player
					ok = !ok; // revert to invalidation
				}
			}
			else // aTurn is 0, meaning code is for Beta
			{
				if(isFree(Alpha,Beta,BOARD,nMove.next)) // next is on a free space
				{
					Beta[indexA][0] = nMove.next[0]; // x coordinate
					Beta[indexA][1] = nMove.next[1]; // y coordinate
                    BOARD[nMove.next[1]-1][nMove.next[0]-1] = 'B';
                    BOARD[nMove.prev[1]-1][nMove.prev[0]-1] = '_';
					aTurn = !aTurn; // switch player
					ok = !ok; // revert to invalidation
				}
				else if((indexB = isAlpha(Alpha,nMove.next) - 1 ) > -1) // next is on an Alpha piece
				{
					Beta[indexA][0] = nMove.next[0]; // x coordinate
					Beta[indexA][1] = nMove.next[1]; // y coordinate
					Alpha[indexB][0] = -1;
					Alpha[indexB][1] = -1;
                    BOARD[nMove.next[1]-1][nMove.next[0]-1] = 'B';
                    BOARD[nMove.prev[1]-1][nMove.prev[0]-1] = '_';
					aTurn = !aTurn; // switch player
					ok = !ok; // revert to invalidation
				}
				
			}
		}
		
    // Game Over (game over part in specs)
    if ((Cardinality(BOARD, 'A') == 0) || (Cardinality(BOARD, 'B') == 0))
    {
      over = 1;

      // Result Condition
      if (Cardinality(BOARD, 'B') == 0) // Alpha Wins
        result = 'A';
      else if (Cardinality(BOARD, 'A') == 0) // Beta Wins
        result = 'B';
    }

    // Post-Game: Conclusion
    if (result == 'A')
    {
        system("cls");
        displayBoard(BOARD);
    	printf("\n%s (Alpha) wins!\n", Player1);
    }
    else if (result == 'B')
    {
    	system("cls");
        displayBoard(BOARD);
        printf("\n%s (Beta) wins!\n", Player2);
    }
  	else if (result == 'D')
    {
        system("cls");
        printf("\nIt's a Draw!\n");
    }
  } while (over == 0); // System Fact 2: Winning Condition

  return 0;
}