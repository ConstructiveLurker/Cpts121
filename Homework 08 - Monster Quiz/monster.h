/* 
 * Programmer: Tyler Avery
 * Class: Cpts121, Fall 2018
 * Programming Asignment: 07
 * Date: October 28, 2018
 *
 * Description: Make a program that creates a database of monsters.
*/

#ifndef TEMPLATE
// Defines Monster struct
#endif

#define NAME_SIZE 15

#ifdef TEMPLATE
#else

#define FILM_SIZE 50
#define WEAKNESS_SIZE 25
#define DEFEATED_SIZE 30

#endif

typedef struct Monster {
		char name[NAME_SIZE];
#ifdef TEMPLATE
#else
		char film[FILM_SIZE];
		int year;
		char weakness[WEAKNESS_SIZE];
		char defeated_by[DEFEATED_SIZE];
		double rating;

#endif
} Monster;
