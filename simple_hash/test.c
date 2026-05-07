#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LENGTH 50


int my_strlen(char *word)
{
    int size = 0;
    char c = word[0];
    int i = 1;
    while(c != '\0')
    {
        c = word[i++];
        size++;
    }
    return size;
}

int main(void)
{
    // char string1[MAX_LENGTH] = "ab";
    // char string2[MAX_LENGTH] = "aba";

    // if (strcmp(string1, string2) < 0)
    //     printf("string1 is less than string2\n");

    // if (strcmp(string1, string2) > 0)
    //     printf("string1 is greater than string2\n");

    char *sample = "";
    printf("Size: %d\n", my_strlen(sample));

    return 0;
}
