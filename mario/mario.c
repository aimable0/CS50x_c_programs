#include <stdio.h>

int main(void)
{
    int total_row;
    do {
        total_row = get_int("Height: ");
    } while (total_row < 0);

    const int rows = total_row;

    int current_row = 1;
    while (total_row > 0)
    {
        // print space n - row times
        for (int n = 0; n < rows - current_row; n++)
        {
            printf(" ");
        }

        // print the '#' current row times
        for (int n = 0; n < current_row; n++)
        {
            printf("#");
        }

        printf ("  ");

        // print the '#' current row times
        for (int n = 0; n < current_row; n++)
        {
            printf("#");
        }

        // verify if a newline is expected on the last line
        printf("\n");

        current_row++;
        total_row--;
    }
}
