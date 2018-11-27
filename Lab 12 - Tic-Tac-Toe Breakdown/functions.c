/*
 * Programmer: Tyler Avery
 * Class: Cpts121, Fall 2018
 * Programming Lab: 12
 * Date: November 9, 2018
 *
 * Description: Tic tac toe functions.
*/

// printf and scanf
#include <stdio.h>
// structures
#include <stdlib.h>
// include our structures and functions
#include "structure.h"


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

