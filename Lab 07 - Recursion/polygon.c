/*
Programmer: Tyler Avery, Jim Brittain, Ethan Powers, Tim Einan, Brandi Wilder, Alexa Darrington
Class: Cpts121, Fall 2018
Programming Lab: 07
Date: October 5, 2018

Description: Draw any given polygon
*/

/*
compile with:
gcc -Wall -c polygon.c
g++ -Wall polygon.o grafic.o -lGdiplus -o polygon.exe 
./polygon
*/

#include <stdio.h>
// for M_Pi, sin(), and cos()
#include <math.h>

#include "grafic.h"

int nSides;

void init (const char **appTitle_pp)
{
	*appTitle_pp = "Draw A Polygon";
	
	int count = 1;
	
	while (count != 0)
	{
		printf ("Enter the number of sides you want your polygon to have: ");
		scanf ("%d", &nSides);
		
		if (nSides > 3)
			break;
	}
}

void redraw (void)
{
	double point_1[2], point_2[2];
	
	for (int i = 0; i <= nSides; i++)
	{
		// calculate point_1
		point_1[0] = cos((2*M_PI*i)/nSides);
		point_1[1] = sin((2*M_PI*i)/nSides);
		
		// calculate point_2
		point_2[0] = cos((2*M_PI*(i+1))/nSides);
		point_2[1] = sin((2*M_PI*(i+1))/nSides);
		
		// draw the polygon
		line (point_1, point_2); 
	}
}
