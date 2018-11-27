/* 
 * Programmer: Tyler Avery
 * Class: Cpts121, Fall 2018
 * Programming Asignment: 07
 * Date: October 28, 2018
 *
 * Description: Make a program that creates a database of monsters.
*/

#include <stdio.h>
#include <string.h>

#define NAME_SIZE 15
#define FILM_SIZE 50
#define WEAKNESS_SIZE 25
#define DEFEATED_SIZE 30

typedef struct {
		char name[NAME_SIZE];
		char film[FILM_SIZE];
		int year;
		char weakness[WEAKNESS_SIZE];
		char defeated_by[DEFEATED_SIZE];
		double rating;
} Monster;

Monster monsters[] = {
	{
		// Dracula
		.name = "Count Dracula",
		.film = "Dracula",
		.year = 1931,
		.weakness = "Wooden stake",
		.defeated_by = "Van Helsing",
		.rating = 7.6,
	},
	{
		// Fraknenstine
		.name = "The Monster",
		.film = "Frakenstein",
		.year = 1931,
		.weakness = "Fire",
		.defeated_by = "Villagers",
		.rating = 8.0,
	},
	{
		// End the list
		"",
	},
};

void print_monster (Monster monster)
{
	int indent = 15;

	printf ("%*s: %s\n", indent, "Name", monster.name);
	printf ("%*s: %s\n", indent, "Film", monster.film);
	printf ("%*s: %d\n", indent, "Year", monster.year);
	printf ("%*s: %s\n", indent, "Weakness", monster.weakness);
	printf ("%*s: %s\n", indent, "Defeated By", monster.defeated_by);
	printf ("%*s: %.1f\n", indent, "Rating", monster.rating);
}

int main (void)
{
	int i = 0;

	printf ("\n");

	for (i = 0; monsters[i].name[0] != 0; i++)
	{
		print_monster(monsters[i]);
		printf ("\n");
	}

	return 0;
}


