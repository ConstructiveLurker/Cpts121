/* 
 * Programmer: Tyler Avery
 * Class: Cpts121, Fall 2018
 * Programming Lab: 04
 * Date: September 14, 2018
 *
 * Description: Print out Pascal's Triangle with user input.
*/

#include <stdio.h>

int main (void)
{
	// Get User Input
	int max_Rows = 0;

	do {
		printf ("Input a number of rows.\n");
		scanf ("%d", &max_Rows);

		if (max_Rows <= 0)
			printf ("Please input a positive integer.");
	} while (max_Rows <= 0);

	int oldRow[max_Rows + 1];
	int newRow[max_Rows + 1];

	for (int n = 0; n <= max_Rows - 1; n++)
	{
		// Indentation
		for (int i = 0; i <= max_Rows - 1 - n; i++)
			printf (" ");

		// Alter Index
		for (int m = 0; m <= n; m++)
		{
			if (m == 0)
			{
				newRow[m] = 1;
			} else if (m == n)
			{
				newRow[m] = 1;
			} else {
				newRow[m] = oldRow[m] + oldRow[m - 1];
			}

		}

		// Print Index
		for (int m = 0; m <= n; m++)
		{
			printf ("%i ", newRow[m]);
			oldRow[m] = newRow[m];
		}

		printf ("\n");
	}

	return 0;
}
