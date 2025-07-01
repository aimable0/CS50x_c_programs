#include <stdio.h>


#define END 100


int main(void)
{
    // prints even numbers from 1 to 100
    for (int i = 1; i < END + 1; i++)
    {
        if (i % 2 == 0)
        {
            printf("%d\n", i);
        }
    }
}