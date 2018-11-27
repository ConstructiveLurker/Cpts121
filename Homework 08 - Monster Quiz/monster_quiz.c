/* 
 * Programmer: Tyler Avery
 * Class: Cpts121, Fall 2018
 * Programming Asignment: 08
 * Date: November 10, 2018
 *
 * Description: Make a program that creates a monster quiz.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h> // for time()

#include "monster.h"

//  This is storage for the database.
 
#define MAX_MONSTERS 1024 /* should be big enough */
struct Monster monsters[MAX_MONSTERS];
int nMonsters; /* set in loadDatabase() */


// This is the number of possible answers (including the correct one)
#define N_CHOICES 4


// We number and name the columns of the CSV file (which are monster attributes) in order.

#define NAME_COLUMN         0
#define FILM_COLUMN         1
#define YEAR_COLUMN         2
#define WEAKNESS_COLUMN     3
#define DEFEATED_BY_COLUMN  4
#define RATING_COLUMN       5


/*
 * We use this struct to hold questions for the quiz. Each question
 * has a `promptFormat` (suitable for printf()) that will include a
 * string ("%s") that, when presented to the quizee, contains the
 * contents of column `promptColumn` of the correct, randomly-chosen
 * monster database record.  The column of the attribute the question
 * is asking about is the `answerColumn`.
 */
typedef struct Question {
    char *promptFormat;
    int promptColumn;
    int answerColumn;
} Question;

Question questions[] = {
    {
        "What was the name of the monster in the film \"%s\"?",
        FILM_COLUMN,
        NAME_COLUMN,
    },
    {
        "Who defeated the monster in the film \"%s\"?",
        FILM_COLUMN,
        DEFEATED_BY_COLUMN,
    },
    {
        "What was \"%s\"'s weakness?",
        NAME_COLUMN,
        WEAKNESS_COLUMN,
    },
    {
        "What year was the film \"%s\" released?",
        FILM_COLUMN,
        YEAR_COLUMN,
    },
    {
        "What IMDB rating did the film \"%s\" receive?",
        FILM_COLUMN,
        RATING_COLUMN,
    },
    {
        "In what film was %s victorious?",
        DEFEATED_BY_COLUMN,
        FILM_COLUMN,
    },
    {
        /* Alhough "year" is an int, we'll turn it into a string for this. */
        "Which of the following monsters first appeared on the screen in %s?",
        YEAR_COLUMN,
        NAME_COLUMN,
    },
    /* add more questions here, if you like */
    {
        /*
         * A question with a zero-length `promptFormat` ends the array
         * of `Questions`.
         */
        ""
    }
};


int foundColumnName(char columnName[], char followedBy, FILE *f1)
/* helper function used to read an expected column name */
{
	char buffer[2048]; /* longer than the longest possible column name */

    	// 1. Didn't read one item
    	// 2. Doesn't match columnName
    	// 3. Not followed by expected char
    	if (fscanf(f1, "%[^,\n]s",  buffer) != 1 || strcmp(buffer, columnName) != 0 || getc(f1) != followedBy) 
    	{ 
        	return 0;
    	}

    	return 1;
}


int scanCsvHeader (FILE *f1)
/* scans a CSV-compatible "monster" header for compatibility */
{
    	if (!foundColumnName("Name", ',', f1))
        	return 0;

    	if (!foundColumnName("Film", ',', f1))
        	return 0;

    	if (!foundColumnName("Year", ',', f1))
        	return 0;

    	if (!foundColumnName("Weakness", ',', f1))
        	return 0;

    	if (!foundColumnName("Defeated by", ',', f1))
        	return 0;

    	if (!foundColumnName("Rating", '\n', f1))
        	return 0;

    	return 1;
}


int scanCsvRow(struct Monster *monster, FILE *f1)
/* reads a Monster row from a CSV file */
{
    	if (fscanf(f1, "%[^,\n]s",  monster->name) != 1)
        	return 0;

    	getc(f1); /* skip the following comma or newline (we could check this) */
    
    	if (fscanf(f1, "%[^,\n]s",  monster->film) != 1)
        	return 0;

    	getc(f1);

    	if (fscanf(f1, "%d",  &monster->year) != 1)
        	return 0;

    	getc(f1);

    	if (fscanf(f1, "%[^,\n]s",  monster->weakness) != 1)
        	return 0;

    	getc(f1);

    	if (fscanf(f1, "%[^,\n]s",  monster->defeated_by) != 1)
        	return 0;

    	getc(f1);

    	if (fscanf(f1, "%lf",  &monster->rating) != 1)
        	return 0;

    	getc(f1);

    	return 1;
}


int loadDatabase(char fileName[])
/* reads a CSV monster database from a file, returns the number of members */
{
	int count = 0, valid;

	FILE *f1;

	f1 = fopen("monsters.csv", "r");

	if (f1 == NULL)
		return 0;

	valid = scanCsvHeader (f1);
	
	if (valid == 0)
		return 0;

	for (;;)
     	{
		valid = scanCsvRow(&monsters[count], f1);

		if (valid == 0)
			break;

		count++;
     	}

     	monsters[count].name[0] = '\0';

	return count;
}

void monster_stringAttribute(struct Monster monster, int column, char result[128])
/* converts the attribute in `column` to a string `result` */
{
    /*
     * This function takes the attribute specified by `column` and, if
     * it's a string attribute, copies it to `result[]`.  If it's not
     * a string attribute, it converts it to one and copies it to
     * `result[]` (using sprintf()).
     */
    switch (column) {

    case NAME_COLUMN:
        strcpy(result, monster.name);
        break;

    case FILM_COLUMN:
        strcpy(result, monster.film);
        break;

    case YEAR_COLUMN:
        sprintf(result, "%d", monster.year);
        break;

    case WEAKNESS_COLUMN:
        strcpy(result, monster.weakness);
        break;

    case DEFEATED_BY_COLUMN:
        strcpy(result, monster.defeated_by);
        break;

    case RATING_COLUMN:
        sprintf(result, "%4.1f", monster.rating);
        break;

    default:
        assert(0); /* shouldn't be reached */
    }
}


int chooseOneOf(int n)
/* returns uniformly-chosen random value r such that 0 <= r < `n` */
{
    return rand() % n; /* MinGW doesn't have random(), so we must use rand() */
}


void scramble(int a[], int n)
/* randomly swap the `n` elements of `a[]` */
{
    int i, j, k, swap;

    for (i = 0; i < 20*n; i++) { /* ought to be enough */
        j = chooseOneOf(n);
        k = chooseOneOf(n);
        swap = a[j]; a[j] = a[k]; a[k] = swap;
    }
}


void selectAnswers(int choices[], int iCorrect, int nPossible)
/* fill in an array of unique `choices`, one of which is `iCorrect` */
{
    int iFound, nFound, iPossible;

    nFound = 0;
    choices[nFound++] = iCorrect;
    while (nFound < N_CHOICES) {
        iPossible = chooseOneOf(nPossible);
        for (iFound = 0; iFound < nFound; iFound++) {
            if (choices[iFound] == iPossible)
                break;
        }
        if (iFound == nFound)
            choices[nFound++] = iPossible;
    }
    /*
     * Mix up the choices
     */
    scramble(choices, N_CHOICES);
}


char chr(int i)
/* return the `i`th lower case letter in the alphabet, with 0 -> 'a' */
{
    return 'a' + i;
}


int ord(char c)
/* return the order of the lower case letter `c` in the alphabet, with 'a' -> 0 */
{
    return c - 'a';
}

// answer with psudocode
void printPrompt(int iQuestion, int iMonster, int choices[N_CHOICES])
/* print the prompt based on question `iQuestion` about monster `iMonster` with `choices[]` */
{
  char buffer[128];
  
  int choice, i;
  
  Question question = questions[iQuestion];
  
  Monster monster = monsters[iMonster];
  
	monster_stringAttribute(monster, question.promptColumn, buffer);

	printf ("%d) ", iQuestion+1);
  printf (question.promptFormat, buffer);
  printf ("\n\n");

	for (i = 0; i < N_CHOICES; i++)
  { 
    choice = choices[i];
    
    monster = monsters[choice];
    
    monster_stringAttribute (monster, question.answerColumn, buffer);
    
		printf ("%c) %s\n", chr(i), buffer);
  }
  
  printf ("\n");

    /*
     * ASSIGNMENT
     *
     * Implement the following pseudocode:
     *
     * let `question` be the `iQuestion`th question.
     * let `monster` be the `iMonster`th monster.
     * call monster_stringAttribute() (see the function for details)
     *  to fill in a buffer with the attribute of `monster`
     *  specified by `question.promptColumn`
     * call `printf()` to output the question number `iQuestion+1`
     *  (The quizee will expect the questions to start at 1).
     * call `printf()` to output `question.promptFormat` with the buffer
     *  you filled in earlier
     * call `putchar()` twice to output a couple of newlines
     * for each choice `i`,
     *     let `choice` be the ith element of `choices[]`
     *     let `monster` be the `choice`th monster in `monsters[]`
     *     call `monster_stringAttribute()` to fill in a buffer with
     *      `monster`'s `question.answerColumn`'th attribute
     *     call printf() to output `chr(i)` and the attribute value buffer
     *      on one line
     */

}

// answer with pseudocode
int askQuestion(int iQuestion)
// ask question `iQuestion`, return true/false if answer is correct/incorrect
{
  int iMonster, answer, choices[N_CHOICES];
 
  char buffer[128]; 
 
  iMonster = chooseOneOf(nMonsters);

	selectAnswers(choices, iMonster, N_CHOICES);
	
	printPrompt(iQuestion, iMonster, choices);
	
  for (;;)
 	{
    printf ("Input your answer: ");
		
    fgets (buffer, 128, stdin);
    answer = ord(buffer[0]);

    //printPrompt(iQuestion, iMonster, choices[N_CHOICES]);)
		
    if ((answer >= 0) && (answer < N_CHOICES)) 
      break;
      
    printf ("You need to input an answer within the correct range.\n\n");
  }

	if (choices[answer] == iMonster)
		return 1;
	else
		return 0;
   
    /*
     * ASSIGNMENT
     *
     * Implement the following pseudocode:
     *
     * call chooseOneOf() to set `iMonster` to a value between 0 and
     *  `nMonsters - 1`, inclusive. This will be the correct answer.
     * let `monster` be the `iMonster`th monster
     * call `selectAnswers()` to fill in an array of `N_CHOICES`
     *  `choices[]`, including `iMonster`
     * call printPrompt() to print the prompt for `iQuestion` and
     *  `iMonster` [* comment omitted here *]
     * loop forever:
     *     call printf() to prompt for an answer
     *     call fgets() to read a line into a buffer on standard input
     *     let `answer` be ord() of the first character in the buffer
     *     if `answer` is between 0 and N_CHOICES - 1, inclusive,
     *         break out of the loop
     *     call printf() to remind the user to enter a value in the
     *      correct range
     * return true if `choices[answer]` is `iMonster`, false otherwise
     */
     
}


void quiz(void)
/* run the quiz based on the `monsters` array */
{
    int i;
    int score, count;

    count = 0;
    score = 0;
    for (i = 0; questions[i].promptFormat[0] != '\0'; i++) {
        if (askQuestion(i)) {
            printf("That is correct.\n");
            score++;
        } else {
            printf("That is incorrect.\n");
        }
        count++;
        printf("\n");
    }
    printf("You scored %d out of %d possible.\n", score, count);
}


int main(void)
{
    /* MinGW doesn't have srandom(), so we must use srand() */
    srand(time(NULL));

    nMonsters = loadDatabase("monsters.csv");
    if (nMonsters > 0)
        quiz();
    return 0;
}
