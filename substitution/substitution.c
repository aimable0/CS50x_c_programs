#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, string argv[])
{
    string default_alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string user_alph = "NQXPOMAFTRHLZGECYJIUWSKDVB";

    string text = get_string("plaintext:  ");


    char cypher_text[strlen(text) + 1];

    for (int i = 0, len = strlen(text); i < len; i++)
    {
        // 1. we are checking a letter in the provided text
        // 2. we are checking the index number it has in normal alphabitical order
        // 3. we are substituting that letter with another letter
        // that has the same index in the users provide alphabets (key).

        for (int m = 0, n = strlen(default_alpha); m < n; m++)
        {
            if (text[i] == default_alpha[m])
            {
                cypher_text[i] = user_alph[m];
                break;
            }
        }
    }

    printf("cyphertext: %s\n", cypher_text);
}

// draft

// we need to map the user's alph order to the default order.
// hard coded would look something like this...
// char sub_text[5];
// sub_text[0] = user_alph[7];
// sub_text[1] = user_alph[4];
// sub_text[2] = user_alph[11];
// sub_text[3] = user_alph[11];
// sub_text[4] = user_alph[14];