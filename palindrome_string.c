/*
 * Programmer: Tyler Avery
 * Class: Cpts121, Fall 2018
 * Programming Lab: 09
 * Date: October 19, 2018
 *
 * Description: See if a word is a palindrome.
*/

// scanf () and printf ()
#include <stdio.h>
// strlen ()
#include <string.h>
// tolower ()
#include <ctype.h>

// no lines longer than this
#define MAX 1024

int palindrome (char line[])
{
	int i, j;
	
	char buf[MAX];
	
	strcpy(buf, line);

   	i = 0;
	j = strlen(buf) - 1;

	while (i < j)
	{
		if (tolower(buf[i]) != tolower(buf[j]))
		{
			// not a palindrome
			return 0;
		}

		i++;
		j--;
	}

	// is a palindrome
	return 1;
}

int main (void)
{
	char word[MAX];

	printf ("Enter a word: ");
	fgets (word, MAX, stdin);
	
	word[strlen(word) - 1] = '\0';

	if (palindrome(word) == 1)
		printf ("%s is a palindrome.\n", word);
	else
		printf ("%s is not a palindrome.\n", word);

	return 0;

}
