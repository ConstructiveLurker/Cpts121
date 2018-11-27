/*
 * Programmer: Tyler Avery
 * Class: Cpts121, Fall 2018
 * Programming Lab: 13
 * Date: November 16, 2018
 *
 * Description: Run our program.
*/

#include <stdio.h>
#include <stdlib.h>

#include "double_stack.h"

int main (int argc, char *argv[])
{
	//double d;

	doubleStack_push(1.0);
	doubleStack_push(34.99);
	doubleStack_push(-4.5);
	doubleStack_push(2.139);
	doubleStack_push(-22.77);

	printf ("Initial Stack:\n\n");
	
	doubleStack_print();

	printf ("\n");

	return 0;
}

