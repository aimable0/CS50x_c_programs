#include <stdio.h>
#include <stdbool.h>

#define HEIGHT 4
#define WIDTH 4

// protos
double avg(int grid[HEIGHT][WIDTH], int num);

// Program's entry point
int main(void)
{
    int grid[HEIGHT][WIDTH] = {{1, 2, 3, 4},
                               {5, 6, 7, 8},
                               {9, 10, 11, 12},
                               {13, 14, 15, 16}};

    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
            printf("%2d ", grid[i][j]);
        printf("\b\n");
    }

    while (true)
    {
        int num;
        printf("Enter a number (quit: 100): ");
        scanf("%d", &num);

        if (num == 100)
            return 0;

        printf("Avg of value of neighbr: %.2f\n", avg(grid, num));
    }
    return 0;
}

// helper function
double avg(int grid[HEIGHT][WIDTH], int num)
{
    double sum = 0;
    double nbr = 0;
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            if (grid[i][j] == num)
            {
                for (int n = i - 1; n < i + 2; n++)
                {
                    for (int m = j - 1; m < j + 2; m++)
                    {
                        if (n > -1 && n < HEIGHT && m > -1 && m < WIDTH) // check bounds
                        {
                            sum += grid[n][m];
                            nbr++;
                            // printf("%d ", grid[n][m]);
                        }
                    }
                }
                printf("\b\n");
            }
        }
    }
    if (nbr == 0)
        return 0;
    return sum / nbr;
}