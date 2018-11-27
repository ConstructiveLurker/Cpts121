#include <stdio.h>

int main (void)
{
	int time = 0;
	double distance = 0.0;

	printf ("Enter a time as an integer.\n");
	scanf ("%d", &time);

	distance = ((double) 1 / 2) * 9.8 * time * time;

	printf ("The ball falls %.1f meters.\n", distance);

	return 0;
}
