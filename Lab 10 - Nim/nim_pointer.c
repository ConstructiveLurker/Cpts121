/*
 * Programmer: Tyler Avery
 * Class: Cpts121, Fall 2018
 * Programming Lab: 10
 * Date: October 26, 2018
 *
 * Description: Base code changed to utilize pointers.
*/

#include <stdio.h>

int system(const char *string);

//functions of broken down code
int play_nim (void);
void print_status (int player, int heapCount1, int heapCount2, int heapCount3);
int get_heap (void);
int *get_heap_count_pointer (int heap, int *heapCount1, int *heapCount2, int *heapCount3);
int get_take (int heap, int *heapCount_p);

int main(void)
{
	int winner;

	printf ("\n");

	winner = play_nim();

	printf ("Player %d wins!\n", winner);

	printf ("\n");

	return 0;
}

int play_nim (void)
{

	int heapCount1, heapCount2, heapCount3;
	int heap, player, take;
	int *heapCount_p;

	/* initialize heap counts */
	heapCount1 = 3;
	heapCount2 = 4;
	heapCount3 = 5;

	player = 2; // first player will be player 1 (see below)

	/* while any stones remain, */
	while (heapCount1 + heapCount2 + heapCount3 > 0)
	{
		/* select the next player */
		player = 3 - player; // player 1 -> 2 and 2 -> 1

		print_status (player, heapCount1, heapCount2, heapCount3);

		/* let the player select a heap that contains at least one stone */
		for (;;)
		{
			/* let the player select a heap */
			heap = get_heap ();

			/* At this point, we know that `heap` is valid, so we check to make sure it's not empty. */
			heapCount_p = get_heap_count_pointer (heap, &heapCount1, &heapCount2, &heapCount3);

			/* If there are stones in it, the move is legal, so break out of the loop. */
			if ((*heapCount_p) > 0)
			{
				break;
			}
			
			printf("Error: Heap %d contains no stones -- Try again.\n", heap);
		}

		take = get_take (heap, heapCount_p);

        	/* deduct those stones */
        	(*heapCount_p) -= take;

        	printf("\n"); // blank line for cosmetic purposes
	}

    	/* declare the last player the winner */
	return player;
}

void print_status (int player, int heapCount1, int heapCount2, int heapCount3)
{
        int i;

	printf("Player %d's turn.\n", player);

        /* print out the counts */
        printf("(1) ");for (i=0;i<heapCount1;i++){ printf("O ");}
        printf(" \n");

        printf("(2) ");for (i=0;i<heapCount2;i++){ printf("O ");}
        printf(" \n");

        printf("(3) ");for (i=0;i<heapCount3;i++){ printf("O ");}
        printf(" \n");
}

int get_heap (void)
{
	int heap;

        for (;;)
        {
                printf("Select a heap to take stones from (1 - 3): ");
                scanf("%d", &heap);
                
		if (1 <= heap && heap <= 3)
                {
                    break;
                }

                printf("Error: Illegal heap value -- Try again.\n");
        }

	return heap;
}

int *get_heap_count_pointer (int heap, int *heapCount1, int *heapCount2, int *heapCount3)
{
        int *heapCount_p;

	/* make `heapCount_p` point at the relevant heap */
        switch (heap)
        {
                case 1:
                        heapCount_p = heapCount1;
                        break;

                case 2:
                        heapCount_p = heapCount2;
                        break;

                case 3:
                        heapCount_p = heapCount3;
                        break;
        }

	return heapCount_p;
}

int get_take (int heap, int *heapCount_p)
{
	int take;

        /* Let the player select a "take" -- a count of stones to remove */
        for (;;)
        {
                printf("Select a count of stones to take from heap %d (1 - %d): ", heap, (*heapCount_p));
                scanf("%d", &take);

                /* If the take is in the proper range, the move is legal, so break out of the loop. */
                if (1 <= take && take <= (*heapCount_p))
                {
                        break;
                }

                printf("Error: Illegal heap count -- Try again.\n");
        }

	return take;
}
