#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

string encrypt(string text, int key);
bool is_valid_key(string key);
void use_error(void);

int main(int argc, string argv[])
{
    // check for the correct usage of the program.
    if (argc != 2)
    {
        use_error();
        return 1;
    }

    if (is_valid_key(argv[1]))
    {
        // get plain text from user.
        string text = get_string("plaintext:  ");

        // encrypt and print the text.
        int key = atoi(argv[1]);
        printf("ciphertext: %s\n",encrypt(text, key));
        return 0;
    }
    else
    {
        use_error();
        return 1;
    }
}











string encrypt(string text, int key)
{
    for (int i = 0, cypher_key = key % 26, len = strlen(text); i < len; i++)
    {
        // the isalpha sets a condition to ensure only alphabets are rotated.
        if (isalpha(text[i]))
        {
            // limit handle uppercase and lowercase letters
            int limit = (isupper(text[i])) ? 90 : 122;

            // rotation.
            text[i] = ((text[i] + cypher_key) > limit) ? text[i] + cypher_key - 26 : text[i] + cypher_key;

        }
    }
    return text;
}


bool is_valid_key(string key)
{
    // This program checks if the key valid.

    // check for non-alpha keys.
    for (int i = 0, len = strlen(key); i < len; i++)
    {
        if (isalpha(key[i]))
        {
            return false;
        }
    }

    // test for non-negative int keys.
    if (atoi(key) < 0)
    {
        return false;
    }

    return true;
}


void use_error(void)
{
    printf("Usage: ./caesar key\n");
}
