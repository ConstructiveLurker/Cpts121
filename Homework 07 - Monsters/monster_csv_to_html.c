/*
 * Programmer: Tyler Avery
 * Class: Cpts121, Fall 2018
 * Programming Assingment: 07
 * Date: October 29, 2018
 *
 * Description: Convert CSV to HTML
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

void monster_printHtmlTableHeader(void)
/* print the header for an HTML table of monster */
{
	printf("<div class='rTableRow'>\n"); /* HTML table rows begin with this tag */
 
	printf("<div class='rTableHead'><strong>Name</strong></div>\n");
	
	printf("<div class='rTableHead'><strong>Film</strong></div>\n");

	printf("<div class='rTableHead'><strong>Year</strong></div>\n");

	printf("<div class='rTableHead'><strong>Weakness</strong></div>\n");

	printf("<div class='rTableHead'><strong>Defeated By</strong></div>\n");

	printf("<div class='rTableHead'><strong>Rating</strong></div>\n");

	printf("</div>\n"); /* HTML table rows end with this tag */
}

void monster_printHtmlTableRow(Monster monster)
/* print the data in "monster" as an HTML row */
{
	printf("<div class='rTableRow'>\n"); /* HTML table rows begin with this tag */

	printf("<div class='rTableCell'>%s</div>\n",  monster.name);

   	printf("<div class='rTableCell'>%s</div>\n",  monster.film);

   	printf("<div class='rTableCell'>%d</div>\n",  monster.year);

   	printf("<div class='rTableCell'>%s</div>\n",  monster.weakness);

    	printf("<div class='rTableCell'>%s</div>\n",  monster.defeated_by);

    	printf("<div class='rTableCell'>%.1f</div>\n",  monster.rating);

    	printf("</div>\n"); /* HTML table rows end with this tag */
}

void monster_printHtmlHeader()
/* print the header for HTML*/
{

	printf ("<!DOCTYPE html>\n");
	printf ("<html>\n");
	printf ("<head>\n");
	printf ("<style>\n");
	printf (".rTable {\n");
	printf ("display: table;\n");
	printf ("width: 100%%;\n");
	printf ("}\n");
	printf (".rTableRow {\n");
	printf ("display: table-row;\n");
	printf ("}\n");
	printf (".rTableHeading {\n");
	printf ("display: table-header-group;\n");
	printf ("background-color: #ddd;\n");
	printf ("}\n");
	printf (".rTableCell,\n");
	printf (".rTableHead {\n");
	printf ("display: table-cell;\n");
	printf ("padding: 3px 10px;\n");
	printf ("border: 1px solid #999999;\n");
	printf ("}\n");
	printf (".rTableHeading {\n");
	printf ("display: table-header-group;\n");
	printf ("background-color: #ddd;\n");
	printf ("font-weight: bold;\n");
	printf ("}\n");
	printf (".rTableFoot {\n");
	printf ("display: table-footer-group;\n");
	printf ("font-weight: bold;\n");
	printf ("background-color: #ddd;\n");
	printf ("}\n");
	printf (".rTableBody {\n");
 	printf ("display: table-row-group;\n");
	printf ("}\n");
	printf ("</style>\n");
	printf ("</head>\n");

	printf ("<body>\n");
 
}
void monster_printHtmlBottom()
/* print the Bottom for HTML*/
{
	printf("< / body>\n");
	printf("< / html>\n");
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

int main(void)
{
	int i, monsterCount;

    	monsterCount = loadDatabase();
  
	if (monsterCount > 0) 
  	{
    		monster_printHtmlHeader();

	  	printf ("<div vlass='rTable'>");

	  	monster_printHtmlTableHeader();
     
    		for (i = 0; monsters[i].name[0] != 0; i++)
		{
			monster_printHtmlTableRow(monsters[i]);
		}

		printf ("</div>");

   	}
	
	return 0;
}






/*
thids is a html example


<!DOCTYPE html>
<html>
<head>
<style>
.rTable {
display: table;
width: 100%;
}
.rTableRow {
display: table-row;
}
.rTableHeading {
display: table-header-group;
background-color: #ddd;
}
.rTableCell,
.rTableHead {
display: table-cell;
padding: 3px 10px;
border: 1px solid #999999;
}
.rTableHeading {
display: table-header-group;
background-color: #ddd;
font-weight: bold;
}
.rTableFoot {
display: table-footer-group;
font-weight: bold;
background-color: #ddd;
}
.rTableBody {
display: table-row-group;
}
</style>
</head>

<body>

<h2>Monster</h2>
<div class="rTable">
	<div class="rTableRow">
		<div class="rTableHead"><strong>Name1</strong></div>
		<div class="rTableHead"><strong>Name2</strong></div>
		<div class="rTableHead"><strong>Name3</strong></div>
	</div>
	<div class="rTableRow">
		<div class="rTableCell">value1</div>
		<div class="rTableCell">value2</div>
		<div class="rTableCell">value3</div>
	</div>
	.
	.
	.
</div>
</body>
</html>
*/
