#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>


void use_error(void);
bool is_valid_key(char key[]);
bool is_text_alpha(char text[]);
bool has_duplicates(string text);



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
    // steps:
    // let's have a second dynamic set. to check letters against.
    // this will store already checked and letters
    // and it will help use check if the current letter is already in the set or not.

    string text_set;
    bool duplicates = false;


    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (duplicates == true)
        {
            break;
        }
        else
        {
            text_set[i] = text[i];

            for (int m = 0, n = strlen(text_set) - 1; m < n; m++)
            {
                if (text[i] == text_set[m])
                {
                    duplicates = true;
                    // return true; --EXPLORE WHY THIS LEAD TO SEGMENTATION FAULT (CORE DUMPUED ERROR) !!
                }
            }
        }
    }
    return duplicates;
}


void use_error(void)
{
    printf("Usage: ./substitution key\n");
}