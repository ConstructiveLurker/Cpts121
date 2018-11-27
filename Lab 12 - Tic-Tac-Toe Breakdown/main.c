/*
 * Programmer: Tyler Avery
 * Class: Cpts121, Fall 2018
 * Programming Lab: 12
 * Date: November 9, 2018
 *
 * Description: Runs our functions.
*/

// printf and scanf
#include <stdio.h>
// srand
#include <stddef.h>
#include <time.h>
// structures
#include <stdlib.h>
// structures and function prototypes
#include "structure.h"


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

