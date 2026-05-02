#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 50

int main(void)
{
    char string1[MAX_LENGTH] = "pal";
    char string2[MAX_LENGTH] = "pale";

    if (strcmp(string1, string2) < 0)
        printf("string1 is less than string2\n");

    if (strcmp(string1, string2) > 0)
        printf("string1 is greater than string2\n");

    return 0;
}
