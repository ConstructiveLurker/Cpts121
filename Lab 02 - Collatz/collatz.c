/* Programmer: Tyler Avery
 * Class: Cpts 121, Fall 2018
 * Programming Lab: 02
 * Date: August 31, 2018
 *
 * Description: Takes an integer, and makes it equal 1 */

#include <stdio.h>

int main (void)
{
	int positive_int = 0, remainder;
	
	/* Check if integer is positive */
	do
	{
		printf ("Enter an integer: ");
		scanf ("%d", &positive_int);
		
		if (positive_int < 1)
		{
			printf ("Error: Your integer has to be positive.\n");
		}
	} while (positive_int < 1);
		

	/* Get the integer to 1 */
	while (positive_int != 1) 
	{
		printf ("%d\n", positive_int);

		remainder = positive_int % 2;

		/* The int is even */
		if (remainder == 0)
		{
			positive_int = positive_int / 2;
		} else {
			/* The int is odd */
			positive_int = (positive_int * 3) + 1;
		}
	}
	/* Print your final result */
	printf ("%d\n", positive_int);

	return 0;
}
