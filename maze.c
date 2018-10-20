#include<stdio.h>

int visit(int m[8][8], int v[8][8], int x, int y)
{
    // Visit.
    v[y][x] = 1;

    // Return value of 1 means (x,y) was part of a solution path.
    // Return value of 0 means (x,y) was not part of a solution path.
    if (x == 7 && y == 7)
    {
        printf("(%d, %d)\n", x, y);
        m[y][x] = 2; // just for printing out route. not important
        return 1;
    }
    else
    {
        // Consider the four adjacent squares to (x, y). But only
        // visit a given one if we:
        // 1) know it's within the bounds of our maze
        // 2) haven't already visited it (i.e. in our visited array
        //    it's values is 0)
        // 3) isn't marked with a 1 in the maze (i.e. an 'X')

        // You'll notice there's a fair amount of repetition in
        // this function. I'm sure there's a cleaner way of doing
        // it, but I think the way below is relatively readable
        // to beginnger programmers.
       

        // The right adjacent square.
        if (x + 1 < 8 && v[y][x+1] != 1 && m[y][x+1] != 1)
        { 
            int res = visit(m, v, x+1, y);
            if (res == 1) // we can also say if (res) since 1 evaluates to true
            {
                // The solution is along this path, so pass
                // the returned 1 up the recursive chain.
                printf("(%d, %d)\n", x, y);
                m[y][x] = 2;
                return res;
            }
            // Otherwise, we'll check a different route.
        }
        // The bottom adjacent square.
        if (y + 1 < 8 && v[y+1][x] != 1 && m[y+1][x] != 1)
        {
            int res = visit(m, v, x, y+1);
            if (res)
            {
                printf("(%d, %d)\n", x, y);
                m[y][x] = 2;
                return res;
            }
        }
        // The top adjacent square.
        if (y - 1 >= 0 && v[y-1][x] != 1 && m[y-1][x] != 1)
        {
            int res = visit(m, v, x, y-1);
            if (res)
            {
                printf("(%d, %d)\n", x, y);
                m[y][x] = 2;
                return res;
            }
        }
        // The left adjacent square
        if (x - 1 >= 0 && v[y][x-1] != 1 && m[y][x-1] != 1)
        { 
            int res = visit(m, v, x-1, y);
            if (res)
            {
                printf("(%d, %d)\n", x, y);
                m[y][x] = 2;
                return res;
            }
        }

        // If none of the above calls to visit returned a 1, then
        // the current path was not a solution path, so return 0.
        return 0;
    }
}


int main(void)
{
    // Declaring maze in main because global variables are usually
    // not good programming practice. But this means I need to pass
    // it to my functions that use it. Using ints instead of characters
    // is easier imo.
    int maze[8][8] = {
        {0, 1, 0, 0, 0, 0, 1, 0},
        {0, 1, 0, 0, 1, 0, 1, 0},
        {0, 1, 0, 1, 1, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 1, 0},
        {1, 1, 0, 1, 0, 0, 1, 0},
        {0, 0, 0, 0, 1, 1, 1, 0},
        {0, 0, 1, 1, 1, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0}};

    // Keep track of visited spaces. 1 indicates visited, 0 indicates
    // unvisited. Everything starts as unvisited. Again, declaring it
    // here means I need to pass it to my functions that use it.
    int visited[8][8] = {0};

    int maze_solved = visit(maze, visited, 0, 0);
    if (!maze_solved)
        printf("No solution found.\n");

    // Print out the maze.
    printf("  x 0 1 2 3 4 5 6 7 \n");
    printf("y _ _ _ _ _ _ _ _ _ _\n");
    for (int i = 0; i < 8; i++)
    {
        printf("%d | ", i);
        for (int j = 0; j < 8; j++)
        {
            if (maze[i][j] == 1)
                printf("X ");
            else if(maze[i][j] == 2)
                printf("o ");
            else
                printf("  ");
        }
        printf("|\n");
    }
    printf("  - - - - - - - - - -\n");
 
   return 0;
}
