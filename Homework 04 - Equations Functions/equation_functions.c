/*
 * Programmer: Tyler Avery
 * Class: Cpts 121, Fall 2018
 * Homework Assignment: 04
 * Date: September 21, 2018
 *
 * Description: Prompt user to select an equation, input a variable, and continue until told to stop. Functions version.
 */

#include <stdio.h>
#include <math.h>

#define PI 3.14159
#define G 6.67E-11

double newtons_2nd_law (double mass, double acceleration);
double volume_cylinder (double radius, double height);
char character_encoding (char plaintext_character);
double gravity_force (double mass1, double mass2, double distance);
double resistive_divider (double resistance1, double resistance2, double vin);
double distance_between_points (double x1, double x2, double y1, double y2);
double general_equation (int a, double x, double z);

int main (void)
{
	int a;

        double mass,
               acceleration,
               radius,
               height,
               mass1,
			   mass2,
               distance,
               resistance2,
               resistance1,
               vin,
               x1,
               x2,
               y1,
               y2,
               z,
               x;

        char equation_letter,
             plaintext_character,
             repeat = 'C';

	while ((repeat == 'C') || (repeat == 'c'))
        {
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
                                printf ("The force of the object is %.2f\n", newtons_2nd_law (mass, acceleration));
                                break;
                        /* Volume of a Cylinder */
                        case 'V':
                        case 'v':
                                printf ("Enter the radius and height of a cylinder.\n");
                                scanf ("%lf", &radius);
                                scanf ("%lf", &height);
                                printf ("The volume of the cylinder is %.2f.\n", volume_cylinder (radius, height));
                                break;
                        /* Character Encoding */
                        case 'C':
                        case 'c':
								printf ("Enter a character for encoding.\n");
                                scanf (" %c", &plaintext_character);
                                printf ("The encoding is %c.\n", character_encoding(plaintext_character));
                                break;
                        /* Gravity Equation */
                        case 'G':
                        case 'g':
                                printf ("Enter the mass of two objects, and the distance between them.\n");
                                scanf ("%lf", &mass1);
                                scanf ("%lf", &mass2);
                                scanf ("%lf", &distance);
                                printf ("The gravitational force is %.2f.\n", gravity_force(mass1, mass2, distance));
                                break;
                        /* Resistive Divider */
                        case 'R':
                        case 'r':
                                printf ("Enter two resistor values, and an input voltage.\n");
                                scanf ("%lf", &resistance1);
                                scanf ("%lf", &resistance2);
                                scanf ("%lf", &vin);
                                printf ("The resistive divider is %.2f.\n", resistive_divider(resistance1, resistance2, vin));
                                break;
                        /* Distance Between Two Points */
                        case 'D':
                        case 'd':
                                printf ("Enter two x, then two y values in a plane.\n");
                                scanf ("%lf", &x1);
                                scanf ("%lf", &x2);
                                scanf ("%lf", &y1);
                                scanf ("%lf", &y2);
                                printf ("The distance between the two points is %.2f.\n", distance_between_points(x1, x2, y1, y2));
                                break;
                        /* General Equation */
                        case 'E':
                        case 'e':
                                printf ("Enter a Z, X, and A value.");
                                scanf ("%lf", &z);
                                scanf ("%lf", &x);
                                scanf ("%d", &a);
                                printf ("The general equation result is %.2f.\n", general_equation(z, x, a));
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

// Calculate Force
double newtons_2nd_law (double mass, double acceleration)
{
	double force = mass * acceleration;

	return force;
}

// Calculate Volume Of A Cylinder
double volume_cylinder (double radius, double height)
{
	double volume = PI * radius * radius * height;

	return volume;
}

// Calculate Character Encoding
char character_encoding (char plaintext_character)
{
	char encoded_character = (plaintext_character - 'a') + 'A';

	return encoded_character;
}

// Calculate Gravitational Force
double gravity_force (double mass1, double mass2, double distance)
{
	double force = (G * mass1 * mass2) / (distance * distance);

	return force;
}

// Calculate Resistive Divider
double resistive_divider (double resistance1, double resistance2, double vin)
{
	double vout = resistance2 / (resistance1 + resistance2) * vin;

	return vout;
}

// Calculate Distance Between Two Points
double distance_between_points (double x1, double x2, double y1, double y2)
{
	double distance = sqrt ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));

	return distance;
}

// Calculate General Equation
double general_equation (int a, double x, double z)
{
	double y = ((double)89 / 27) - z * x + a / (a % 2);

	return y;
}
