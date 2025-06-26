#include <stdio.h>

// function declaration
int valid_tria(int a, int b, int c);


int main(void)
{
    int side_1 = 3;
    int side_2 = 4;
    int side_3 = 5;

    if (valid_tria(side_1, side_2, side_3))
    {
        printf("Valid\n");
    }
    else
    {
        printf("Triangle with sides: %i, %i %i Not valid\n", side_1, side_2, side_3);
    }
}


int valid_tria(int a, int b, int c)
{

    if ( a > 0 && b > 0 && c > 0)
    {
        if ((a + b > c) && (a + c > b) && (b + c > a))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }
}





