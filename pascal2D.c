/*
 * Programmer: Tyler Avery
 * Class: Cpts121, Fall 2018
 * Programming Lab: 04
 * Date: September 14, 2018
 *
 * Description: Multi-Dimensional array for Pascal's triangle sum.
*/

#include <stdio.h>

int main (void)
{
	int max_Rows = 0, sum = 0;

	do {
		 printf ("Input a number of rows.\n");
                scanf ("%d", &max_Rows);

                if (max_Rows <= 0)
                        printf ("Please input a positive integer.");
        } while (max_Rows <= 0);


	int pascal[max_Rows + 1][max_Rows + 1];

	// Set Array to 0
	for (int i = 0; i <= max_Rows; i++)
	{
		for (int j = 0; j <= max_Rows; j++)
		{
			pascal[i][j] = 0;
		}
	}


        for (int n = 0; n <= max_Rows - 1; n++)
        {
                // Alter Index
                for (int m = 0; m <= n; m++)
                {
                        if (m == 0)
                        {
                                pascal[n][m] = 1;
                        } else if (m == n)
                        {
                                pascal[n][m] = 1;
                        } else {
                                pascal[n][m] = pascal[n - 1][m - 1] + pascal[n - 1][m];
                        }

                }
	}

                // Accumulate Sum
                for (int n = 0; n <= max_Rows; n++)
		{
			for (int m = 0; m <= max_Rows; m++)
			{
				sum += pascal[n][m];
			}
        	}
		
		printf ("%d\n", sum);

        return 0;

}
