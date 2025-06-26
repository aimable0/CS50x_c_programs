#include <stdio.h>
#include <string.h>
#include "cs50.h"

// prototypes
int word_count(string word);

int main(void)
{
    string sample_text = get_string("Text: ");
    int tot_words = word_count(sample_text);
    printf("Text provided: %s\n", sample_text);
    printf("Total words: %i\n", tot_words);

    int letter_count = strlen(sample_text);
    printf("Total letters: %d", letter_count);
}


// count words in the text
int word_count(string word)
{

    // check for the number of spaces in the word (word separator)

    int count = 0;

    for (int i = 0, n = strlen(word); i < n; i++)
    {
        if (word[i] == ' ')
        {
            count++;
        }

        // for a more sophisticated programm we could track double spaces (later).
    }

    // return number of spaces + 1 = total words.
    return count + 1;
}