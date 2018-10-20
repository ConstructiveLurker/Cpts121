/* 
 * Programmer: Tyler Avery
 * Class: CptS 121, Fall 2018
 * Programming Assignment: #01
 * Date: August 30, 2018
 *
 * Description: This program loops 4 equations 10 times.
/* 

/* Needed for printf (), scanf () */
#include <stdio.h>

/* Constant macro */
#define PI 3.14159
#define G 6.67E-11

int main (void)
{
	/* Initialize variables */
	int count, iteration;

	double force = 0.0,
	       mass = 0.0,
	       acceleration = 0.0,
	       volume_cylinder = 0.0,
	       radius = 0.0,
	       height = 0.0,
	       mass2 = 0.0,
	       distance = 0.0;
	
	char encoded_character = 'a', plaintext_character = 'a';

	count = 10;
	iteration = 1;

	while (count > 0)
	{
		/* Increment counter */
		count = count - 1;

		/* Force equation */
		/* Ask for variables */
		printf ("Enter the mass and acceleration of an object to use in Newton's Second Law.\n");
		scanf ("%lf", &mass);
		scanf ("%lf", &acceleration);

		/* Calculate */
		force = mass * acceleration;

		/* Result */
		printf ("The force of the object is %f\n", force);

		/* Volume of a cylinder */
		/* Ask for variables */
		printf ("Enter the radius and height of a cylinder to use to calculate the volume of a cylinder.\n");
		scanf ("%lf", &radius);
		scanf ("%lf", &height);

		/* Calculate */
		volume_cylinder = PI * radius * radius * height;

		/* Result */
		printf ("The volume of the cylinder is %f.\n", volume_cylinder);

		/* Character encoding */
		/* Ask for variables */
		printf ("Enter a character for encoding.\n");
		scanf (" %c", &plaintext_character);

		/* Calculate */
		encoded_character = (plaintext_character - 'a') + 'A';

		/* Result */
		printf ("The encoding is %c.\n", encoded_character);

		/* Gravity equation */
		/* Ask for variables */
		printf ("Enter the mass of an object, the mass of a second object, and the distance between the two objects.\n");
		scanf ("%lf", &mass);
		scanf ("%lf", &mass2);
		scanf ("%lf", &distance);

		/* Calculate */
		force = (G * mass * mass2) / (distance * distance);

		/* Result */
		printf ("The gravitational force is %f.\n", force);

		/* Iterations */
		printf ("This is iteration %d.\n", iteration);
		iteration = iteration + 1;
	}
	return 0;
}

