/*
 * Programmer: Tyler Avery
 * Class: Cpts121, Fall 2018
 * Programming Lab: 11
 * Date: November 2, 2018
 *
 * Description: Open a file and print out the words inside.
*/

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main (void)
{
	char word[BUFFER_SIZE];

	FILE *f_p;

	f_p = fopen ("words.txt", "r");

	if (f_p)
	{
		while (fscanf(f_p, "%s", word) != EOF)
		{
			printf ("%s\n", word);
		}
	}

	fclose (f_p);

	return 0;
}
