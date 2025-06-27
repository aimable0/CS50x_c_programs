#include <stdio.h>
#define PERIOD 10
#define PRINCIPAL 5000

int main()
{
    float interest_rate = 0.11;
    float interest_amount;
    float amount = PRINCIPAL;


    for (int i = 1; i <= PERIOD; i++)
    {
        amount = amount * (1 + interest_rate);

        if ((i >= 3) && (i <= 9))
        {
            printf("-             --------\n");
        }
        else
        {
            printf("%i             %.2f\n", i, amount);
        }
    }
}


// c- program structure
// documentaion section.
// include header files
// define symbolic constants
// global variable definiton
// main program
// under main program - variables & functions.
// sub-programs (user defined functions)

// Describe the process of creating and executing a C program and UNIX system.

