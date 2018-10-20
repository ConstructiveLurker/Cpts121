 /*
 * Programmer: Tyler Avery
 * Class: Cpts121, Fall 2018
 * Homework Assignment: 02
 * Date: September 7, 2018
 *
 * Description: Prompt user to select an equation, input a variable, and continue until told to stop.
 */

#include <stdio.h>
#include <math.h>

/* Constant macro */
#define PI 3.14159
#define G 6.67E-11

int main (void)
{
        /* Initialize variables */
        int a;

        double force,
               mass,
               acceleration,
               volume_cylinder,
               radius,
               height,
               mass2,
               distance,
	       vout,
	       r2,
	       r1,
	       vin,
	       x1,
	       x2,
	       y1,
	       y2,
	       y,
	       z,
	       x;

        char equation_letter, 
	     encoded_character, 
	     plaintext_character,
	     repeat = 'C';

	// Run through until user wants to stop
	while ((repeat == 'C') || (repeat == 'c'))
	{
		// Print menu
		printf ("Enter (N, V, C, G, R, D, E) to select an equation.\n");
		printf ("Equations:\n");
		printf ("N = Force Equation.\n");
		printf ("V = Volume of a Cylinder.\n");
		printf ("C = Character Encoding.\n");
		printf ("G = Gravitational Force.\n");
		printf ("R = Resistive Divider.\n");
		printf ("D = Distance Between Two Points.\n");
		printf ("E = General Equation.\n");
		
		// User input
		scanf (" %c", &equation_letter);

		switch (equation_letter)
		{
			/* Force Equation */
			case 'N':
			case 'n':
		                printf ("Enter the mass and acceleration of an object.\n");
		                scanf ("%lf", &mass);
		                scanf ("%lf", &acceleration);
				force = mass * acceleration;
				printf ("The force of the object is %f\n", force);
				break;
			/* Volume of a Cylinder */
			case 'V':
			case 'v':
		                printf ("Enter the radius and height of a cylinder.\n");
				scanf ("%lf", &radius);
				scanf ("%lf", &height);
				volume_cylinder = PI * radius * radius * height;
				printf ("The volume of the cylinder is %f.\n", volume_cylinder);
				break;
			/* Character Encoding */
			case 'C':
			case 'c':
		                printf ("Enter a character for encoding.\n");
		                scanf (" %c", &plaintext_character);
				encoded_character = (plaintext_character - 'a') + 'A';
				printf ("The encoding is %c.\n", encoded_character);
				break;
			/* Gravity Equation */
			case 'G':
			case 'g':
				printf ("Enter the mass of two objects, and the distance between them.\n");
				scanf ("%lf", &mass);
				scanf ("%lf", &mass2);
				scanf ("%lf", &distance);
				force = (G * mass * mass2) / (distance * distance);
				printf ("The gravitational force is %f.\n", force);
				break;
			/* Resistive Divider */
			case 'R':
			case 'r':
				printf ("Enter two resistor values, and an input voltage.\n");
				scanf ("%lf", &r1);
				scanf ("%lf", &r2);
				scanf ("%lf", &vin);
				vout = r2 / (r1 + r2) * vin;
				printf ("The resistive divider is %f.\n", vout);
				break;
			/* Distance Between Two Points */
			case 'D':
			case 'd':
				printf ("Enter two x, then two y values in a plane.\n");
				scanf ("%lf", &x1);
				scanf ("%lf", &x2);
				scanf ("%lf", &y1);
				scanf ("%lf", &y2);
				distance = sqrt ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
				printf ("The distance between the two points is %f.\n", distance);
				break;
			/* General Equation */
			case 'E':
			case 'e':
				printf ("Enter a Z, X, and A value.");
				scanf ("%lf", &z);
				scanf ("%lf", &x);
				scanf ("%d", &a);
				y = ((double)89 / 27) - z * x + a / (a % 2);
				printf ("The general equation result is %f.\n", y);
				break;
			default:
				printf ("You must enter a valid letter.\n");
				break;
		}
		
		/* Continue or Quit? */
		do {
			printf ("Do you want to (C)ontinue or (S)top?\n");
			scanf (" %c", &repeat);
			
			switch (repeat)
			{
				case 'C':
				case 'c':
				case 'S':
				case 's':
					break;
				default:
					printf ("Error: Invalid character.\n");
					break;
			}
		} while (!((repeat == 'C') || (repeat == 'c') || (repeat == 'S') || (repeat == 's')));
	}
        return 0;
}
