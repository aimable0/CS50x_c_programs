#include <stdio.h>
// #include "cs50.h"

int main(void)
{
    int number = 10;

    int guess_number  = 5;

    // if (number == guess_number)
    // {
    //     printf("Perfect guess");
    // }
    // else
    // {
    //     printf("Wrong_guess");
    // }

    while (guess_number != number)
    {
        printf("Wrong guess!");
    }

    printf("Perfect guess!");
}