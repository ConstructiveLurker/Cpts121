/* 
 * Programmer: Tyler Avery
 * Class: Cpts 121, Fall 2018
 * Programming Lab: 02
 * Date: August 31, 2018
 *
 * Description: Takes an integer, and makes it equal 1, while displaying an idex of iterations 
 */

#include <stdio.h>

int main (void)
{
	int maximum_int = 0, remainder, count, initial_int;
	
	count = 0;
	initial_int = 0;

	/* Check if integer is positive */
	do
	{
		printf ("Enter an integer: ");
		scanf ("%d", &maximum_int);
		
		if (maximum_int < 1)
		{
			printf ("Error: Your integer has to be positive.\n");
		}
	} while (maximum_int < 1);

	printf ("initial n	count\n");	

	/* Get the integer to 1 */
	for (int i = 1; i <=  maximum_int; i++) 
	{
		count = 0;
		initial_int = i;

		while (initial_int != 1)
		{
			count = count + 1;

			remainder = initial_int % 2;

			/* The int is even */
			if (remainder == 0)
			{
				initial_int = initial_int / 2;
			} else {
				/* The int is odd */
				initial_int = (initial_int * 3) + 1;
			}
		}
	
		/* Print your final result */
		printf ("%9d%12d\n", i, count);
	}
	
	return 0;
}
