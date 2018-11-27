/*
 * Programmer: Tyler Avery
 * Class: Cpts121, Fall 2018
 * Homework Assignment: 03
 * Date: September 14, 2018
 *
 * Description: Generates an array of 100 random integers between 1 - 20, and gives the number of times each appears.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RANDOM 100
#define STATISTICS 21

int main (void)
{
	int random_array[RANDOM], array_statistics[STATISTICS];

	// Set Array Statistic to 0
	for (int i = 0; i < STATISTICS; i++)
	{
		array_statistics[i] = 0;
	}
	
	srand (time(0));

	// Generate Random Array
	for (int i = 0; i < RANDOM; i++)
	{
		random_array[i] = (rand()%20) + 1;
	}

	// Array Statistics
	for (int i = 0; i < RANDOM; i++)
	{
		int temp = random_array[i];
		array_statistics[temp]++;
	}

	printf ("The statistics for the 20 random integers are:\n");
	printf ("Integer	Repitition\n");

	for (int i = 0; i < STATISTICS; i++)
	{
		//printf ("%i\n", random_array[i]);
		if (array_statistics[i] != 0)
		{
			printf ("%7d %10d\n", i, array_statistics[i]);
		}
	}

	return 0;
}
