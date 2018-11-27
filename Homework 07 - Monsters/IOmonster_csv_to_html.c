/*
 * Programmer: Tyler Avery
 * Class: Cpts121, Fall 2018
 * Programming Assingment: 07
 * Date: October 29, 2018
 *
 * Description: Convert CSV to HTML using I/O
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

// Modify
void monster_printHtmlTableHeader(FILE *f2)
/* print the header for an HTML table of monster */
{
	fprintf(f2, "<div class='rTableRow'>\n"); /* HTML table rows begin with this tag */
 
	fprintf(f2, "<div class='rTableHead'><strong>Name</strong></div>\n");
	
	fprintf(f2, "<div class='rTableHead'><strong>Film</strong></div>\n");

	fprintf(f2, "<div class='rTableHead'><strong>Year</strong></div>\n");

	fprintf(f2, "<div class='rTableHead'><strong>Weakness</strong></div>\n");

	fprintf(f2, "<div class='rTableHead'><strong>Defeated By</strong></div>\n");

	fprintf(f2, "<div class='rTableHead'><strong>Rating</strong></div>\n");

	fprintf(f2, "</div>\n"); /* HTML table rows end with this tag */
}


// Modify
void monster_printHtmlTableRow(Monster monster, FILE *f2)
/* print the data in "monster" as an HTML row */
{
	fprintf(f2, "<div class='rTableRow'>\n"); /* HTML table rows begin with this tag */

	fprintf(f2, "<div class='rTableCell'>%s</div>\n",  monster.name);

  	fprintf(f2, "<div class='rTableCell'>%s</div>\n",  monster.film);

  	fprintf(f2, "<div class='rTableCell'>%d</div>\n",  monster.year);

  	fprintf(f2, "<div class='rTableCell'>%s</div>\n",  monster.weakness);

  	fprintf(f2, "<div class='rTableCell'>%s</div>\n",  monster.defeated_by);

  	fprintf(f2, "<div class='rTableCell'>%.1f</div>\n",  monster.rating);

  	fprintf(f2, "</div>\n"); /* HTML table rows end with this tag */
}

void monster_printHtmlHeader(FILE *f2)
/* print the header for HTML*/
{
	fprintf (f2, "<!DOCTYPE html>\n");
	fprintf (f2, "<html>\n");
	fprintf (f2, "<head>\n");
	fprintf (f2, "<style>\n");
	fprintf (f2, ".rTable {\n");
	fprintf (f2, "display: table;\n");
	fprintf (f2, "width: 100%%;\n");
	fprintf (f2, "}\n");
	fprintf (f2, ".rTableRow {\n");
	fprintf (f2, "display: table-row;\n");
	fprintf (f2, "}\n");
	fprintf (f2, ".rTableHeading {\n");
	fprintf (f2, "display: table-header-group;\n");
	fprintf (f2, "background-color: #ddd;\n");
	fprintf (f2, "}\n");
	fprintf (f2, ".rTableCell,\n");
	fprintf (f2, ".rTableHead {\n");
	fprintf (f2, "display: table-cell;\n");
	fprintf (f2, "padding: 3px 10px;\n");
	fprintf (f2, "border: 1px solid #999999;\n");
	fprintf (f2, "}\n");
	fprintf (f2, ".rTableHeading {\n");
	fprintf (f2, "display: table-header-group;\n");
	fprintf (f2, "background-color: #ddd;\n");
	fprintf (f2, "font-weight: bold;\n");
	fprintf (f2, "}\n");
	fprintf (f2, ".rTableFoot {\n");
	fprintf (f2, "display: table-footer-group;\n");
	fprintf (f2, "font-weight: bold;\n");
	fprintf (f2, "background-color: #ddd;\n");
	fprintf (f2, "}\n");
	fprintf (f2, ".rTableBody {\n");
 	fprintf (f2, "display: table-row-group;\n");
	fprintf (f2, "}\n");
	fprintf (f2, "</style>\n");
	fprintf (f2, "</head>\n");

	fprintf (f2, "<body>\n");
}
void monster_printHtmlBottom(FILE *f2)
/* print the Bottom for HTML*/
{
	fprintf(f2, "< / body>\n");
	fprintf(f2, "< / html>\n");
}

int foundColumnName (char columnName[], char followedBy, FILE *f1)
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

// Modify
int scanCsvHeader(FILE *f1)
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

// Modify
int scanCsvRow(Monster *monster, FILE *f1)
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


int loadDatabase(FILE *f1)
/* reads a CSV monster database on standard input, returns the number of members */
{
    	int count = 0, valid;

     	valid = scanCsvHeader(f1);

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

int main(void)
{
	int i, monsterCount;
 
  	FILE *f1, *f2;
 
 
  	f1 = fopen ("monsters.csv", "r");

 	f2 = fopen ("monsters.html", "wr");
  
  	if (f1 != NULL)
  	{
    		monsterCount = loadDatabase(f1);
  	}
  
    
  	if (monsterCount > 0) 
	{
    		monster_printHtmlHeader(f2);

    		fprintf (f1, "<div vlass='rTable'>");

   		monster_printHtmlTableHeader(f2);
     
    		for (i = 0; monsters[i].name[0] != 0; i++)
		{
			monster_printHtmlTableRow(monsters[i], f2);
  		}

		fprintf (f2, "</div>");

   	}
   
	fclose (f1);
   	fclose (f2);
	
	return 0;
}
