#include <stdio.h>

int main(void)
{
    int x = 3;

    switch(x)
    {
        case 1:
            printf("Today it's Monday");
            break;

        case 2:
            printf("Today it's Tuesday");
            break;

        case 3:
            printf("Today it's Wednesday\n");
            break;

        case 4:
            printf("Today it's Thursday");
            break;

        case 5:
            printf("Today it's Friday");
            break;

        case 6:
            printf("Today it's Saturday");
            break;

        case 7:
            printf("Today it's Sunday");
            break;

        default:
            printf("Today it's a normal day\n");
            // break not needed on default.
    }


    int y;
    if (10 < 11)
    {
        y = 10;
    }
    else
    {
        y = 15;
    }
    printf("The value of y is %d\n", y);


    int p = (15 < 20) ? 15 : 10;    // concise version of the above conditional assignment.

    printf("The value of p is %d\n", p);
}