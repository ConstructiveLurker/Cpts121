/* 
 * Programmer: Tyler Avery
 * Class: Cpts121, Fall 2018
 * Programming Assignment: 07
 * Date: October 28, 2018
 *
 * Description: Print a sorted table of monsters.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NAME_SIZE 15
#define FILM_SIZE 50
#define WEAKNESS_SIZE 25
#define DEFEATED_SIZE 30

typedef struct Monster {
	char name[NAME_SIZE];
	char film[FILM_SIZE];
	int year;
	char weakness[WEAKNESS_SIZE];
	char defeated_by[DEFEATED_SIZE];
	double rating;
} Monster;

#define MAX_MONSTERS 1024 

Monster monsters[MAX_MONSTERS];

void printCsvHeader (void)
/* print a CSV-compatible "monster" header to standard output */
{
	printf ("%s,", "Name");
	printf ("%s,", "Film");
	printf ("%s,", "Year");
	printf ("%s,", "Weakness");
	printf ("%s,", "Defeated by");
	printf ("%s\n", "Rating");
}

void printCsvRow (Monster monster)
/* print a CSV-compatible "monster" row to standard output */
{
	printf ("%s,", monster.name);
	printf ("%s,", monster.film);
	printf ("%d,", monster.year);
	printf ("%s,", monster.weakness);
	printf ("%s,", monster.defeated_by);
	printf ("%.1f\n", monster.rating);
}

void saveDatabase (Monster monsters[])
{
	int i;

	printCsvHeader();

  	for (i = 0; monsters[i].name[0] != 0; i++)
	{
		printCsvRow(monsters[i]);
	}
}

int foundColumnName (char columnName[], char followedBy)
/* helper function used to read an expected column name */
{
  	char buffer[2048]; /* longer than the longest possible column name */

  	// 1. Didn't read one item
  	// 2. Doesn't match columnName
  	// 3. Not followed by expected char
  	if (scanf("%[^,\n]s",  buffer) != 1 || strcmp(buffer, columnName) != 0 || getchar() != followedBy) 
  	{ 
    		return 0;
  	}

  	return 1;
}


int scanCsvHeader(void)
/* scans a CSV-compatible "monster" header for compatibility */
{
  	if (!foundColumnName("Name", ','))
    		return 0;

  	if (!foundColumnName("Film", ','))
    		return 0;

  	if (!foundColumnName("Year", ','))
    		return 0;

 	if (!foundColumnName("Weakness", ','))
    		return 0;

  	if (!foundColumnName("Defeated by", ','))
    		return 0;

  	if (!foundColumnName("Rating", '\n'))
    		return 0;

    	return 1;
}


int scanCsvRow(Monster *monster)
/* reads a Monster row from a CSV file */
{
  	if (scanf("%[^,\n]s",  monster->name) != 1)
  		return 0;

  	getchar(); /* skip the following comma or newline (we could check this) */
    
  	if (scanf("%[^,\n]s",  monster->film) != 1)
    		return 0;

  	getchar();

  	if (scanf("%d",  &monster->year) != 1)
    		return 0;

  	getchar();

  	if (scanf("%[^,\n]s",  monster->weakness) != 1)
    		return 0;

  	getchar();

  	if (scanf("%[^,\n]s",  monster->defeated_by) != 1)
    		return 0;

  	getchar();

  	if (scanf("%lf",  &monster->rating) != 1)
    		return 0;

  	getchar();

  	return 1;
}


int loadDatabase(void)
/* reads a CSV monster database on standard input, returns the number of members */
{
  	int count = 0, valid;

  	valid = scanCsvHeader();

  	if (valid == 0)
    		return 0;


  	for (;;)
  	{
    		valid = scanCsvRow(&monsters[count]);

	  	if (valid == 0)
		  	break;

	  	count++;
  	}

  	monsters[count].name[0] = '\0';

  	return count;
}


int compareMonstersByYear(const void *monster0_vp, const void *monster1_vp)
{
  	const struct Monster *monster0_p = monster0_vp;
  	const struct Monster *monster1_p = monster1_vp;

  	/* sort monsters by year of film release */
  	return monster0_p->year - monster1_p->year;
}


int main(void)
{
  	int monsterCount;

  	monsterCount = loadDatabase();
  	if (monsterCount > 0) 
  	{
    		qsort(monsters, monsterCount, sizeof(Monster), compareMonstersByYear);
    		saveDatabase(monsters);
 	}
  
  	return 0;
}
