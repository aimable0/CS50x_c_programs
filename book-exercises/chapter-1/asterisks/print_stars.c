#include <stdio.h>

int main(void)
{
    // printing a right triangle with asterisks

    int max_level = 4;

    for (int i = 0; i < max_level; i++)
    {
        for (int t = 0; t < i; t++)
        {
            printf("*  ");
        }
        printf("\n");
    }
}