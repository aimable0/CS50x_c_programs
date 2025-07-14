#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

string encrypt(string text, int key);

int main(int argc, string argv[])
{
    // check if the usage of the program is correct.
    if (argc < 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }


    // look for a function that can modify a string (CLA) into an int
    int key;

    if (atoi(argv[1]) >= 0)
    {
        key = atoi(argv[1]);
    }
    else
    {
        printf("Key has to be a non-negative integer\n");
    }

    // get plain text from user.
    string text = get_string("plain text:  ");

    // encrypt text.
    // string cipher_text = encrypt(text, key);

    printf("ciphertext: %s\n",encrypt(text, key));

    return 0;
}

string encrypt(string text, int key)
{
    // string encrypted_text;
    string text_cpy = text;
    int cypher_key = key % 26;

    for (int i = 0, len = strlen(text_cpy); i < len; i++)
    {
        // the isalpha sets a condition to ensure only alphabets are rotated.
        if (isalpha(text_cpy[i]))
        {

            // limit handle uppercase and lowercase letters
            int limit = (isupper(text_cpy[i])) ? 90 : 122;

            // rotation.
            text_cpy[i] = ((text_cpy[i] + cypher_key) > limit) ? text_cpy[i] + cypher_key - 26 : text_cpy[i] + cypher_key;

        }
    }

    return text_cpy;
}