/*
 * Programmer: Tyler Avery
 * Class: Cpts121, Fall 2018
 * Programming Lab: 03
 * Date: September 7, 2018
 *
 * Description: Allow the user to submit values, then get the next minimum score to get the desired grade.
 */

#include <stdio.h>

int main (void)
{
	double score1, score2, score3, score4, final_score;
        char final_grade;
	int valid_grade;

	/* Numerical values */
        do {
                /* Get user input */
		printf ("Enter three double values:\n");
		scanf ("%lf", &score1);
		scanf ("%lf", &score2);
		scanf ("%lf", &score3);

                /* See if values are valid */
                if ((score1 < 0) && (score2 < 0) && (score3 < 0))
                {
                        printf ("You have to enter a positive value.\n");
                }
	} while ((score1 < 0) && (score2 < 0) && (score3 < 0));
	
	/* Letter grade */
	do {
		/* Get user input */
		printf ("Enter the letter grade you want to achieve:\n");
                scanf (" %c", &final_grade);


		/* See if letter is valid */
		switch (final_grade)
		{
			case 'A':
			case 'a':
			case 'B':
			case 'b':
			case 'C':
			case 'c':
			case 'D':
			case 'd':
			case 'F':
			case 'f':
				valid_grade = 1;
				break;
			default:
				printf ("You have to enter a valid letter grade (A, B, C, D, or F).\n");
				valid_grade = 0;
				break;
		}

        } while (valid_grade != 1);

	/* Set final score */
	switch (final_grade)
	{
		case 'A':
                case 'a':
			final_score = 90;
			break;
                case 'B':
                case 'b':
			final_score = 80;
			break;
                case 'C':
                case 'c':
			final_score = 70;
			break;
                case 'D':
                case 'd':
			final_score = 60;
			break;
		default:
			final_score = 0;
			break;
	}


	/* Calculate last score needed */
	score4 = 4 * final_score - score1 - score2 - score3;

	printf ("The minimum score to get a(n) %c grade is %.2f.\n", final_grade, score4);
	
	return 0;
}
