#include <stdio.h>
#define MULTIPLICAND 5


int print_mul_table (int multiplicand);

int main(void)
{
    print_mul_table(MULTIPLICAND);
}




// prints multiplication table of multipicand up to 10.
int print_mul_table(int multiplicand)
{
    for (int i = 1; i <= 10; i++)
    {
        if (i <= 9)
        {
            printf(" %d x %d  =  %d\n", multiplicand, i, (multiplicand * i));
        }
        else
        {
            printf(" %d x %d =  %d\n", multiplicand, i, (multiplicand * i));
        }
    }
    return 0;
}