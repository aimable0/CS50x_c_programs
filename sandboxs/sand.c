#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

bool has_duplicates(char string[]);

int main(void)
{
    // create a simple function that checks if a string
    // has duplicate characters or not.

    char sample1[28] = "NJQSUYBRXMOPFTNZVAWCGILKED";
    if (has_duplicates(sample1))
    {
        printf("%s has duplicates\n", sample1);
    }
    else
    {
        printf("%s has no duplicates\n", sample1);
    }
}

bool has_duplicates(char string[])
{
    char *letter = string;
    int len = (int) strlen(string);

    while(letter < string + len)
    {
        int i = 0;
        while(string[i] != '\0')
        {
            if (letter != &string[i]
                && tolower(*letter) == tolower(string[i])) return true;
            i++;
        }
        letter++;
    }
    return false;
}
