#include <stdio.h>
#include <string.h>
#include "cs50.h"

// prototypes
int word_count(string word);
int letter_count(string text);

int main(void)
{
    // formular
    // index = 0.0588 * L - 0.296 * S - 15.8


    string sample_text = get_string("Text: ");
    int tot_words = word_count(sample_text);
    printf("Text provided: %s\n", sample_text);
    printf("Total words: %i\n", tot_words);

    int tot_letters = strlen(sample_text);
    printf("Total letters: %d", tot_letters);
    letter_count(sample_text);

    //more sample
}


// count words in the text
int word_count(string text)
{

    // check for the number of spaces in the word (word separator)
    int count = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == ' ')
        {
            count++;
        }
        // for a more sophisticated programm we could track double spaces (later).
    }

    // return number of spaces + 1 = total words.
    return count + 1;
}

int letter_count(string text)
{
    // how am i going to count letters in a text ?
    // I want to loop through the letters and check if the letter is found we increment it

    for (int i = 0, len = strlen(text); i < len; i++)
    {
        // print every character in the text
        printf("%c", text[i]);
    }
}