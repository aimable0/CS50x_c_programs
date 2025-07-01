#include <stdio.h>


int main(void)
{
    // prints the sum of harmonic series for a given value of n
    int N = 3;
    float sum = 0.00;

    int i = 1;
    while(i < N + 1)
    {
        printf("1 / %d ..\n", i);
        sum += (float) 1/i;
        printf("sum: %f\n", sum);
        i++;
    }

    printf("Sum: %f\n", sum);
}