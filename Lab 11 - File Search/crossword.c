/*
 * Programmer: Tyler Avery
 * Class: Cpts121, Fall 2018
 * Programming Lab: 11
 * Date: November 2, 2018
 *
 * Description: Prompt a user to input letters, and search a list of words that can be made.
*/

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 1024

int wordIsLegal(char word[BUFFER_SIZE], char letters[BUFFER_SIZE])
{
	char vowels[] = "aeiouwy", buffer[BUFFER_SIZE], *character, ch;

	int foundVowel = 0, i;

	strcpy (buffer, letters);

	for (i = 0; word[i] != '\0'; i++)
	{
    ch = word[i];
    
		if (!strchr (buffer, ch))
   {
     break;
   }
    
    if (strchr (vowels, ch))
		{
      foundVowel = 1;
		}
   
    character = strchr (buffer, ch);
    *character = ' ';
	}

  if (strlen(word) && foundVowel == 1 && strlen(word) >= 2)
  {
    return 1;
  } else {
    return 0;
  }


/*
 * declare any needed variables
 * initialize a string `vowels` to "aeiouwy"
 * copy `letters` to a temporary `buffer` (hint: strcpy()) (see why?)
 * set a `foundVowel` flag to 0
 * for each character `ch` in "word",
 *   if `ch` is not in `buffer`, (hint: strchr())
 *     break out of the "for" loop
 *   if `ch` is in `vowels`, (hint: strchr())
 *     set the `foundVowel` flag to 1
 *     set the character at `ch`'s position in `buffer` to ' ' (so
 *     it won't be found again)
 * if all characters of "word" have been tested
 * *and* `foundVowel` is 1
 * *and* the length of the string is at least 2 (hint: strlen()),
 *   return 1 (true)
 * otherwise
 *   return 0 (false)
 */
}

int main(void)
{
	char word[BUFFER_SIZE], letters[BUFFER_SIZE];

	int countWords = 0;

	FILE *words;

  // get user input for our search
	printf ("Input letters you'd like to use in a word.\n");
	scanf ("%s", letters);

  // the "words.txt" is the name of our file
  // "r" indicates we're opening the file for reading
	words = fopen ("words.txt", "r");

  // while we still have words to read
	while (fscanf(words, "%s", word) != EOF)
	{
    // if the word has all your characters
		if (wordIsLegal(word, letters))
		{
			printf ("%s\n", word);
      
			countWords++;
		}
	}
  
  // print number of compatable words
  printf ("You can make %d words with your characters.\n", countWords);

  // close our file
 fclose (words);
 
 return 0;
 
 /*
 * declare any needed variables
 * prompt for the letters on the user's tray (hint: printf())
 * input the `letters` string (hint: scanf())
 * open the file "words.txt" for reading (hint: fopen())
 * set `countWords` to 0
 * for each `word` (line) in that file (hint: fscanf())
 * if `word` is a legal word (hint: wordIsLegal()),
 * print out `word` (hint: printf())
 * increment `countWords`
 * report `countWords` words found (hint: printf())
 * close the file (hint: fclose())
 */
}


