/*
Programmer: Tyler Avery
Class: Cpts121, Fall 2018
Programming Lab: 06
Date: September 28, 2018

Description: Draw multiple triangles inside a triangle with recursion
*/

/*
compile with:
gcc -Wall -c draw_sierpinski.c
g++ -Wall draw_sierpinski.o grafic.o -lGdiplus -o draw_sierpinski.exe 
./draw_sierpinski
*/

#include "grafic.h"

// title your application window 
void init (const char **appTitle_pp)
{
	*appTitle_pp = "Sierpinski Triangle";
}


// draws your triangle using your points
void triangleDraw (double p0[], double p1[], double p2[])
{
	line (p0, p1);
	line (p1, p2);
	line (p2, p0);
}

// recursion - draw your interior triangles
void fractal_triangle (double p0[], double p1[], double p2[], int i)
{
	double auxp0[2], auxp1[2], auxp2[2];
	
	// base case - when you stop
	if (i > 4)
	{
		triangleDraw (p0, p1, p2);
	} else {
		// drawing step
		// sets the points for your interior triangles
		auxp0[0] = (p1[0]+ p0[0])*0.5; auxp0[1] = (p1[1]+ p0[1])*0.5;
		auxp1[0] = (p2[0]+ p1[0])*0.5; auxp1[1] = (p2[1]+ p1[1])*0.5;
		auxp2[0] = (p0[0]+ p2[0])*0.5; auxp2[1] = (p0[1]+ p2[1])*0.5;
		
		// recursion
		// repeats setting the points for the interior triangles
		fractal_triangle (p0, auxp0, auxp2, i+1);
		fractal_triangle (auxp0, p1, auxp1, i+1);
		fractal_triangle (auxp2, auxp1, p2, i+1);
		
		// super cool triangle 
		//fractal_triangle (p0, auxp1, auxp2, i+1);
		//fractal_triangle (auxp0, p1, auxp2, i+1);
		//fractal_triangle (auxp0, auxp1, p2, i+1);
	}
}

// main function
void redraw (void)
{
	// make variables
	double p0[2], p1[2], p2[2];
	
	// set variable coordinates
	p0[0] = -0.5; p0[1] = 0;
	p1[0] = 0; p1[1] = 1;
	p2[0] = 0.5; p2[1] = 0;
	
	// draw your triangle
	fractal_triangle(p0,p1,p2,0);
}
