/*
 * Programmer: Tyler Avery
 * Class: Cpts121, Fall 2018
 * Homework Number: 03
 * Date: September 14, 2018
 *
 * Description: Have a user input an array size, values, then reverse it.
*/

#include <stdio.h>

int main (void)
{
	int array_size = 0, temp = 0;

	// Get User Input
	do {
		printf ("Input a positive value.\n");
		scanf ("%d", &array_size);

		if (array_size <= 0)
			printf ("Error: Put in a positive value.");
	} while (array_size <= 0);

	// Set Array Size
	int array[array_size + 1];

	// Get Array Values
	for (int i = 0; i <= array_size - 1; i++)
	{
		printf ("Input the array value for index %d.\n", i);
		scanf ("%i", &array[i]);
	}

	// Swap Array Values
	for (int i = 0; i <= (array_size - 1)/2; i++)
	{
		temp = array[array_size - 1 -  i];
		array [array_size - 1 - i] = array [i];
		array [i] = temp;
	}

	// Print Array
	printf ("The reverse of your array is: ");

	for (int i = 0; i <= array_size - 1; i++)
	{
		printf ("%i ", array[i]);
	}

	printf ("\n");
	
	return 0;
}
