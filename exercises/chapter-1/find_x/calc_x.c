#include <stdio.h>

// calculate a math expression

int main(void)
{
    int a, b, c, x;
    // int x = (a / (b - c));

    printf("Enter a: ");
    scanf("%d", &a);
    printf("Enter b: ");
    scanf("%d", &b);
    printf("Enter c: ");
    scanf("%d", &c);
    printf("Got all values\n");
    printf("Wait...\n");
    // manual test values
    // a = 250;
    // b = 85;
    // c = 25;

    // handling edge cases like division of zero
    if (b != c)
    {
        x = (a / (b - c));
        printf("a = %d, b = %d, c = %d, x = %d", a, b, c, x);
    }
    else
    {
        printf("Division of Zero (b - c = 0) not legal!");
    }

}