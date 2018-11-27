 /*
 * Programmer: Tyler Avery
 * Class: Cpts121, Fall 2018
 * Programming Lab: 03
 * Date: September 7, 2018
 *
 * Description: Allow the user to submit values, then get the numerical grade and the letter grade.
 */

#include <stdio.h>

int main (void)
{
	double first, second, third, fourth, numerical_grade;
	char letter_grade;

	do {
		/* Get user input double values */
		printf ("Enter four double values for a grade:\n");
		scanf ("%lf", &first);
		scanf ("%lf", &second);
		scanf ("%lf", &third);
		scanf ("%lf", &fourth);

		/* See if values are valid */
		if ((first < 0) && (second < 0) && (third < 0) && (fourth < 0))
		{
			printf ("You have to enter a positive value.\n");
		}

	} while ((first < 0) && (second < 0) && (third < 0) && (fourth < 0));

	numerical_grade = (first + second + third + fourth) / 4;

	if ((numerical_grade >= 0) && (numerical_grade < 60)) {
		letter_grade = 'F';
	} else if ((numerical_grade >= 60) && (numerical_grade < 70)) {
		letter_grade = 'D';
	} else if ((numerical_grade >= 70) && (numerical_grade < 80)) {
		letter_grade = 'C';
	} else if ((numerical_grade >= 80) && (numerical_grade < 90)) {
		letter_grade = 'B';
	} else {
		letter_grade = 'A';
	}
	
	printf ("Your numerical grade is %.2f, and your letter grade is %c.\n", numerical_grade, letter_grade);

	return 0;
}
