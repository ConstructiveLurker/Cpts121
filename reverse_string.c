/*
 * Programmer: Tyler Avery
 * Class: Cpts121, Fall 2018
 * Programming Lab: 09
 * Date: October 19, 2018
 *
 * Description: Reverse a string.
*/

#include <stdio.h>
#include <string.h>

#define SIZE 17

void string_reverse(char* string);

int main (void)
{
	char string[] = "Cpts 121 is cool!";
	
	// print initial
	printf ("Your string is: %s\n", string);

	// reverse
	string_reverse (string);

	// print result
	printf ("The reverse of the string is: %s\n", string);

	return 0;
}

void string_reverse(char* string)
{
	int i;
	char temp;

	for (i = 0; i < (SIZE / 2); i++)
	{
		temp = string[SIZE - 1 - i];
		string[SIZE - 1 - i] = string[i];
		string[i] = temp;
	}

}
