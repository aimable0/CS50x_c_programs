#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>



void use_error(void);
bool is_valid_key(char key[]);


int main(int argc, string argv[])
{
    if (argc != 2)
    {
        use_error();
        return 1;
    }

    if (is_valid_key(argv[1]))
    {

        // string key = "NQXPOMAFTRHLZGECYJIUWSKDVB";
        string default_alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        string key = argv[1];

        string text = get_string("plaintext:  ");

        char cypher_text[strlen(text) + 1];

        // let's encrypt!
        // steps:
        // 1. we are looping through all the letters in the provided plaintext.
        // 2. For each letter we are looking for the index it would have in alphabets
        // i.e: the index number it has in alphabitical order
        // 3. we are substituting that letter with another letter
        // from the user's provided alpha order given they have exact same index

        for (int i = 0, len = strlen(text); i < len; i++)
        {
            for (int m = 0, n = strlen(default_alpha); m < n; m++)
            {
                if (default_alpha[m] == toupper(text[i]))
                {
                    if (isupper(text[i]))
                    {
                        cypher_text[i] = key[m];
                    }
                    else
                    {
                        cypher_text[i] = tolower(key[m]);
                    }
                    break;
                }
            }
        }


        // displaying the cyphertext.
        printf("cyphertext: ");
        for (int i = 0, len = strlen(text); i < len; i++)
        {
            printf("%c", cypher_text[i]);
        }
        printf("\n");

        return 0;
    }
    else
    {
        return 1;
    }

}






bool is_valid_key(char key[])
{
    // check if key is exactly 26 chars
    if (strlen(key) != 26)
    {
        printf("KeyError: Key must be exactly 26 alpha chars with no repetition\n");
        return false;
    }

    for (int i =0, len = strlen(key); i < len; i++)
    {
        //info: numbers range 48-57 in ascii
        if (key[i] >= 48 && key[i] <= 57)
        {
            printf("KeyError: Key must be exactly 26 alpha chars with no repetition\n");
            return false;
        }
    }

    return true;    // if all checks has been passed then key is valid
}


void use_error(void)
{
    printf("Usage: ./substitution key\n");
}
