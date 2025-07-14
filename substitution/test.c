#include <stdio.h>
#include <string.h>
#include <cs50.h>


int has_duplicates(string text);

int main(void)
{
    char text_1[4] = "ABC";
    printf("has duplicates: %i\n", has_duplicates(text_1));
    // printf("has duplicates: %i\n", has_duplicates(text_1));
}



int has_duplicates(char text[])
{
    // steps:
    // let's have a second dynamic set. to check letters against.
    // this will store already checked and letters
    // and it will help use check if the current letter is already in the set or not.

    char text_set[strlen(text)];


    for (int i = 0, len = strlen(text); i < len; i++)
    {
        text_set[i] = text[i];

        printf("i = %i\n", i);
        // test
        printf("text_set: {");
        for (int k = 0, q = strlen(text_set); k < q; k++)
        {
            printf("%c, ", text_set[k]);
        }
        printf("}\n");


        for (int m = 0, n = strlen(text_set) - 1; m < n; m++)
        {
            // if (text[i] == text_set[m])
            // {
            //     return 1;
            // }
            printf("  m = %i\n", m);
            printf("text_set letter: %c", text_set[m]);
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}