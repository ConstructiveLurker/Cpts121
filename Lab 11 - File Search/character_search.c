/*
 * Programmer: Tyler Avery
 * Class: Cpts121, Fall 2018
 * Programming Lab: 11
 * Date: November 2, 2018
 *
 * Description: Check a word's characters.
*/

#include <stdio.h>
#include <string.h>

char *strchr(const char *s, int c);

int main (void)
{
	char word_1[] = "coffee";
	char *ch_p1;
	
	ch_p1 = strchr (word_1, 't');

	if (!ch_p1)
	{
		printf ("There is no 't' in %s!\n", word_1);
	}

	char word_2[] = "foo";
	char *ch_p2;

	ch_p2 = strchr (word_2, 'o');
	if (ch_p2)
	{
		(*ch_p2) = 'r';
	}

	printf ("%s\n", word_2);


	return 0;
}
