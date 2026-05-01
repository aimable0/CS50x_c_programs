#include <stdio.h>

int main(void)
{
    char name[7] = "000.jpg";

    for (char i = '0'; i < '5'; i++)
        for (char k = '0'; k < '9' + 1; k++)
        {
            name[1] = i;
            name[2] = k;
            printf("%s\n", name);
        }

    return 0;
}
