#include <stdio.h>

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
    // Add the two grids element-wise
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            grid1[i][j] += grid2[i][j];
        }
    }

    // Check if grid1 is stable
    int unstable = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (grid1[i][j] > 3)
            {
                unstable = 1;
                break;
            }
        }
    }

    // Toppling round
    while (unstable)
    {
        printf("=\n");
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                printf("%d ", grid1[i][j]);
            }
            printf("\n");
        }

        // Copy grid1 to a temporary grid
        int temp[3][3];
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                temp[i][j] = grid1[i][j];
            }
        }

        // Topple unstable cells
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (temp[i][j] > 3)
                {
                    grid1[i][j] -= 4;
                    if (i + 1 < 3)
                    {
                        grid1[i + 1][j]++;
                    }
                    if (i - 1 >= 0)
                    {
                        grid1[i - 1][j]++;
                    }
                    if (j + 1 < 3)
                    {
                        grid1[i][j + 1]++;
                    }
                    if (j - 1 >= 0)
                    {
                        grid1[i][j - 1]++;
                    }
                }
            }
        }

        // Check if grid1 is stable
        unstable = 0;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (grid1[i][j] > 3)
                {
                    unstable = 1;
                    break;
                }
            }
        }
    }
}
