/*
 * Programmer: Tyler Avery
 * Class: Cpts121, Fall 2018
 * Programming Lab: 12
 * Date: November 9, 2018
 *
 * Description: Plays a tic tac toe game.
*/

#ifndef _INCLUDED_TIC_H /* effectively prevents multiple #includes */

// This header file describes the "tic" struct and all accessible
// functions in the "tic" library.

// size of every attribute
#define MAX 3

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
	Cell cells[MAX][MAX];
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

#define _INCLUDED_TIC_H
#endif
