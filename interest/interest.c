#include <stdio.h>
#define PERIOD 10
#define PRINCIPAL 5000

int main()
{

    float interest_rate = 0.11;
    float interest_amount;
    float amount = PRINCIPAL;

    printf("0             %.2f\n", amount);
    
    for (int i = 1; i <= PERIOD; i++)
    {
        amount = amount * (1 + interest_rate);
        printf("%i             %.2f\n", i, amount);
    }
}
