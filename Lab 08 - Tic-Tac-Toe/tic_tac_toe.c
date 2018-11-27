/*
 * Programmer: Tyler Avery
 * Class: Cpts121, Fall 2018
 * Programming Assignment: 06
 * Date: October 12, 2018
 *
 * Description: Plays a tic tac toe game.
*/

// printf and scanf
#include <stdio.h>
// srand
#include <stddef.h>
#include <time.h>
// structures
#include <stdlib.h>

// build structures
typedef struct 
{
	int row;
	int column;
} Coordinate;

typedef struct
{
	// 1 if an 'x' or an 'o', 0 otherwise
	int occupied;
	// 'x' for one player, 'o' for the other
	char symbol;
	// represents position of cell in the gameboard
	Coordinate location;
} Cell;

typedef struct
{
	Cell cells[3][3];
	int winner;
	int counter;
	int size;
	int player;
} Board;

// function prototypes
Cell createCell (int x, int y, char symbol, int status);
void getPosition (void);
int updateBoard (void);
int isWinning (Cell lastCell);
void printBoard (void);

// structure subclass
Board board;
Coordinate pos;

int main (void)
{
	srand(time(0));

	int status = 0, i, j;
	char symbol = '\0';
	Cell lastCell;

	// initialize
	board.winner = 0;
	board.counter = 0;
	board.size = 3;
	board.player = (rand()%2);

	for (i = 0; i < board.size; i++)
	{
		for (j = 0; j < board.size; j++)
		{
			board.cells[i][j] = createCell(i, j, symbol, status);
		}
	}
        
	do {
		// player turn
		printf ("\n");

		if (board.player == 0)
			printf ("Player 1's turn.\n");
		else 
			printf ("Player 2's turn.\n");

		// get player coordinates
		getPosition();

		// update last cell
		lastCell.location.row = pos.row;
		lastCell.location.column = pos.column;

		if (board.player == 0)
                        lastCell.symbol = 'X';
                else
                        lastCell.symbol = 'O';

		// see if you won
		board.winner = isWinning (lastCell);
		
		board.counter++;
		
		printBoard();

		// if you don't win, change the player
		if ((board.player == 0) && (board.winner != 1))
			board.player = 1;
		else if ((board.player == 1) && (board.winner != 1))
			board.player = 0;
		
	} while ((board.counter < 9) && (board.winner != 1));

	// win result
	if (board.counter == (board.size*board.size))
		printf ("The game is a draw!\n");
	if (board.winner == 1 && board.player == 0)
		printf ("Player 1 has won the game.\n");
	if (board.winner == 1 && board.player == 1)
		printf ("Player 2 has won the game.\n");

	return 0;
}

// Initialize empty cells
Cell createCell (int x, int y, char symbol, int status)
{	
	Cell empty;
	
	empty.occupied = status;
	empty.symbol = symbol;
	empty.location.row = x;
	empty.location.column = y;

	return  empty;
}

// Ask user for coordinates and update Board
void getPosition (void)
{
	do {
		printf ("Input your 'X' and 'Y' coordinates: ");
		scanf ("%d %d", &pos.row, &pos.column);
		printf ("\n");
	} while (updateBoard () == 1);
}

// update the Board values with user's coordinates
int updateBoard (void)
{
	// if outside of bounds
	if ((pos.row > board.size - 1) || (pos.column > board.size - 1))
	{
		printf ("Error: This cell is out of bounds. Please choose another.\n");
		return 1;
	}

	// if occupied
	if (board.cells[pos.row][pos.column].occupied == 1)
	{
		printf ("Error: This cell is occupied. Please choose another.\n");
		return 1;
	// if not occupied
	} else {
		// make cell occupied
		board.cells[pos.row][pos.column].occupied = 1;
		
		// set symbol
		if (board.player == 0)
			board.cells[pos.row][pos.column].symbol = 'X';
		else 
			board.cells[pos.row][pos.column].symbol = 'O';
		
		return 0;
	}
}

// see if vertical, horizontal, major digonal, and minor diagonal cell has the same characters
int isWinning (Cell lastCell)
{
	int i, xStatus;

	// check if vertical has the same symbol
	for (i = 0; i < board.size; i++)
	{
		if (board.cells[lastCell.location.row][i].symbol == lastCell.symbol)
		{
			xStatus = 1;
		} else {
			xStatus = 0;
			break;
		}
	}

	if (xStatus != 1)
	{
		// check if horizontal has the same symbol
		for (i = 0; i < board.size; i++)
		{
			if (board.cells[i][lastCell.location.column].symbol == lastCell.symbol)
			{
				xStatus = 1;
			} else {
				xStatus = 0;
				break;
			}
		}
	}

	// check if major diagonal has the same symbol
	if ((lastCell.location.column == lastCell.location.row) && (xStatus != 1))
	{
		for (i = 0; i < board.size; i++)
		{
			if (board.cells[i][i].symbol == lastCell.symbol)
			{
				xStatus = 1;
			} else {
				xStatus = 0;
				break;
			}
		}
	}

	// check if minor diangonal has the same symbol
	if ((lastCell.location.column == (2 - lastCell.location.row)) && (xStatus != 1))
	{
		for (i = 0; i < board.size; i++)
		{
			if (board.cells[i][2 - i].symbol == lastCell.symbol)
			{
				xStatus = 1;
			} else {
				xStatus = 0;
				break;
			}
		}
	}

	return xStatus;
}

// print the board
void printBoard (void)
{
	int i, j;

	for (i = 0; i < board.size; i++)
	{
		for (j = 0; j < board.size; j++)
		{
			if (j == 0)
				printf ("|");

			printf (" %c |", (char)board.cells[i][j].symbol);
			
			if (j == board.size - 1) 
				printf ("\n");
		}
	}
}
