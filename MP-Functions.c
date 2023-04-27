#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char String30[31];

/*
  Purpose: Displays the board and board game pieces
  @param: BOARD is a 2D array containing the board game pieces
  Returns: void
*/
void displayBoard(char BOARD[][7])
{
  printf(" | 1 | 2 | 3 | 4 | 5 | 6 | 7 |\n");
  printf("1| %c |   | %c |   | %c |   | %c |\n", BOARD[0][0], BOARD[0][2], BOARD[0][4], BOARD[0][6]);
  printf("2|   | %c |   | %c |   | %c |   |\n", BOARD[1][1], BOARD[1][3], BOARD[1][5]);
  printf("3| %c |   | %c |   | %c |   | %c |\n", BOARD[2][0], BOARD[2][2], BOARD[2][4], BOARD[2][6]);
  printf("4|   | %c |   | %c |   | %c |   |\n", BOARD[3][1], BOARD[3][3], BOARD[3][5]);
  printf("5| %c |   | %c |   | %c |   | %c |\n", BOARD[4][0], BOARD[4][2], BOARD[4][4], BOARD[4][6]);
}

/*
  Purpose: This function shows the Menu at the start of the program. The
  user can choose to play the game, know the mechanics, and know about the
  authors.
  @param: Player1 is a string pointer that points to Player 1's name (Alpha)
  @param: Player2 is a string pointer that points to Player 2's name (Beta)
  Returns: void
*/
void displayMenu(String30 *Player1, String30 *Player2)
{
  int MenuChoice; // contains user-input options for Main Menu (Inputs:1/2/3)
  do
	{
		printf("\n\nWELCOME TO OUR BOARDGAME!\n");
    printf("\nPRESS:\n");
    printf("[1] to Play\n");
    printf("[2] for Mechanics\n");
    printf("[3] to Know More about Creators\n");
    scanf("%d", &MenuChoice);

    // This shows the mechanics of the game.
    if (MenuChoice == 2)
		{
      printf("\nThe mechanics of the game are as follows:\n");
      printf("> Player 1 gets 5 Alpha pieces.\n");
      printf("> Player 2 gets 5 Beta pieces.\n");
      printf("> The goal is to eat all of the other player's pieces in a 7x5 grid\n");
      printf("  wherein you will move and eat diagonally.\n");
      printf("> Players can only move in VALID spaces.\n");
      printf("> The first player to eat all of the other player's pieces will be the winner!\n");
      printf("\nReady to play? Press 1 to continue. Press 0 to go back to the main menu.\n");
      scanf("%d", &MenuChoice);
      system("cls"); // Clear previous lines
    }

    // This displays the authors' info.
    if (MenuChoice == 3)
		{
      printf("\nThis board game is created by: \n");
      printf("Aden Azarcon\n");
      printf("Trisha Sayo\n");
      printf("Josh Dane Villavicencio\n\n");
      printf("This game project is in fulfillment of\n");
      printf("the Machine Project Requirement for\n");
      printf("CCDSTRU - Discrete Structures\n\n");
      printf("Instructor: Ms. Shirley Chu\n");
      printf("Date: June 19, 2022\n");
      printf("\nReady to play? Press 1 to continue. Press 0 to go back to the main menu.\n");
       scanf("%d", &MenuChoice);
      system("cls"); // Clear previous lines
    }
  } while (MenuChoice != 1); // Loops until user inputs 1 (Play)

      do
			{
        printf("Enter your name, Player 1 (Alpha): ");
        scanf("%s", *Player1);
        if (strlen(*Player1) > 30)
          printf("WARNING: Name is too long\n\a");
      } while (strlen(*Player1) > 30); // Loops until string length fits max string size

      do
			{
        printf("Enter your name, Player 2 (Beta): ");
        scanf("%s", *Player2);
        if (strlen(*Player2) > 30)
          printf("WARNING: Name is too long\n\a");
        if (strcmp(*Player1, *Player2) == 0)
          printf("ERROR: Username already in use\n\a");
      } while ((strlen(*Player2) > 30) || strcmp(*Player1, *Player2) == 0); // Loops until string length fits max string size
}

/*
  Purpose: Checks how many pieces left for either Alpha or Beta in the board
  @param: BOARD is a 2D array containing the board game pieces.
  @param: key is the search key
  Returns: nCount, number of valid elements in the set/array
*/
int Cardinality(char BOARD[][7], char key)
{
  int i, j;       // index and counter
  int nCount = 0; // return value

  for (i = 0; i <= 5; i++) // iterates per row
  {
    for (j = 0; j <= 7; j++) // iterates per column
    {
      if (BOARD[i][j] == key) // if the board piece matches the key
        nCount++;
    }
  }
  return nCount;
}

#include <stdio.h>

/*
  Purpose: Checks if a piece is Alpha's
  @param: Alpha is a 2D array containing the coordinates of the Alpha pieces
  @param: Piece is a 1D array containing the coordinate of the player's previous move
  Returns: nValid, x-coordinate of corresponding Alpha piece (if true), or 0 (if not Alpha's)
*/
int isAlpha(int Alpha[][2], int Piece[])
{
	int i; // index and counter
  	int nValid = 0;

	for(i = 0; i < 5; i++) // iterates 5 times (number of pieces upon initialization)
  	{
        if(
		    (Piece[0] == Alpha[i][0]) && // x coordinates match
		    (Piece[1] == Alpha[i][1]) // y coordinates match
		  )
    		nValid = i + 1; // assign x coordinate
  	}
	
  return nValid;
}

/*
  Purpose: Checks if a piece is Beta's
  @param: Beta is a 2D array containing the coordinates of the Beta pieces
  @param: Piece is a 1D array containing the coordinate of the player's previous move
  Returns: nValid, x-coordinate of corresponding Beta piece (if true), or 0 (if not Beta's)
*/
int isBeta(int Beta[][2], int Piece[])
{
  int i; // index and counter
  int nValid = 0;

  for(i = 0; i < 5; i++) // iterates 5 times (number of pieces upon initialization)
  {
    if(
				(Piece[0] == Beta[i][0]) && // x coordinates match
	  		(Piece[1] == Beta[i][1]) // y coordinates match
	  	)
      nValid = i + 1; // assign x coordinate
  }
  return nValid; 
} 

/*
  Purpose: Checks if the next move is a free space 
  @param: Alpha is a 2D array containing the coordinates of the Alpha pieces
	@param: Beta is a 2D array containing the coordinates of the Beta pieces
	@param: BOARD is a 2D array containing the board game pieces
  @param: Piece is a 1D array containing the coordinate of the player's previous move
  Returns: nValid, 1 if space is free or 0 if not
*/
int isFree(int Alpha[][2], int Beta[][2], char BOARD[][7], int Piece[]) 
{
	int nValid = 0;
	
	// Check if the piece is not part of Alpha/Beta, and free space on board
	if(
		!isAlpha(Alpha, Piece) && // check if piece is not part of Alpha
		!isBeta(Beta, Piece) && // check if piece is not part of Beta
		((Piece[0]%2 == 1 && Piece[1]%2 == 1) || (Piece[0]%2 == 0 && Piece[1]%2 == 0))
	  )
		nValid = 1;
  
	return nValid;
}