#include "cs50.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void use_error(void);
bool is_valid_key(char key[]);
bool is_text_alpha(char text[]);
bool has_duplicates(string text);

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        use_error();
        return 1;
    }

    // extract key
    printf("key: %s\n", argv[1]);

    if (is_valid_key(argv[1]))
    {
        // string key = "NQXPOMAFTRHLZGECYJIUWSKDVB";
        string default_alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        string key = argv[1];

        string text = get_string("plaintext:  ");

        char cipher_text[strlen(text) + 1];

        // let's encrypt!
        // steps:
        // 1. we are looping through all the letters in the provided plaintext.
        // 2. For each letter we are looking for the index it would have in alphabets
        // i.e: the index number it has in alphabitical order
        // 3. we are substituting that letter with another letter
        // from the user's provided alpha order given they have exact same index

        for (int i = 0, len = strlen(text); i < len; i++)
        {
            if (isalpha(text[i]))
            {
                for (int m = 0, n = strlen(default_alpha); m < n; m++)
                {
                    if (default_alpha[m] == toupper(text[i]))
                    {
                        if (isupper(text[i]))
                        {
                            cipher_text[i] = toupper(key[m]);
                        }
                        else
                        {
                            cipher_text[i] = tolower(key[m]);
                        }
                        break;
                    }
                }
            }
            else
            {
                cipher_text[i] = text[i];
            }

        }

        // displaying the ciphertext.
        printf("ciphertext: ");
        for (int i = 0, len = strlen(text); i < len; i++)
        {
            printf("%c", cipher_text[i]);
        }
        printf("\n");

        return 0;
    }
    else
    {
        printf("Invalid Key\n");
        return 1;
    }

}

bool is_valid_key(char key[])
{
    // check if key has no duplicates
    if (has_duplicates(key))
    {
        return false;
    }

    printf("got here\n");
    // check if key is exactly 26 chars
    if (strlen(key) == 26 && is_text_alpha(key))
    {
        return true;
    }
    printf("KeyError: Key must be exactly 26 alpha chars with no repetition\n");
    return false;    // if all checks has been passed then key is valid
}

// check if string is alpha
bool is_text_alpha(char text[])
{
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (!(isalpha(text[i])))
        {
            return false;
        }
    }
    return true;
}

bool has_duplicates(string text)
{
    char *letter = text;
    int len = (int) strlen(text);
    *letter = tolower(*letter);
    while(letter < text + len)
    {
        int i = 0;
        while(text[i] != '\0')
        {
            if (letter != &text[i]
                && *letter == tolower(text[i])) return true;
            i++;
        }
        letter++;
    }
    return false;
}

void use_error(void)
{
    printf("Usage: ./substitution key\n");
}
