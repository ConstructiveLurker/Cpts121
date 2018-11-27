/*
 * Programmer: Tyler Avery
 * Class: Cpts121, Fall 2018
 * Programming Lab: 09
 * Date: October 19, 2018
 *
 * Description: Prints only palindromes from user input.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 1024

// get rid of anything that isn't a letter
void remove_blank (char buf [])
{
	int i = 0, j = 0;

	while (buf[j] != '\0')
	{
		// if it's a letter
		if (isalpha(buf[j]))
		{
			buf[i] = buf[j];
			i++;
		}
		j++;
	}

	// if not a letter, remove it
	buf[i] = '\0';
}

// see if it's a palindrome
int palindrome (char line[])
{
        int i, j;

        char buf[MAX];

        strcpy(buf, line);

	remove_blank (buf);

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
	char line[MAX];
	
	printf ("Enter a palindrome phrase.\n");

	while (fgets(line, MAX, stdin) != NULL)
	{
		// remove the enter from line
		line[strlen(line) - 1] = '\0';

		if ((strlen(line) >= 4) && (palindrome(line) == 1))
		{
			printf ("%s is a palindrome.\n\n", line);
		} else {
			printf ("%s is not a palindrome.\n\n", line);
		}
	}

	return 0;
}
