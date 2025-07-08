#include <stdio.h>
#include <math.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>


// prototypes - function declarations.
int word_count(string word);
int letter_count(string text);
float average_letters(int tot_letters, int tot_words);
int sentences_count(string text);
float average_sentences(int sntncs_count, int tot_words);

int main(void)
{
    // Documentation
    // This program help predict the reading level for a certain text.
    // Formular: index = 0.0588 * L - 0.296 * S - 15.8.
    // where L is the average number of letters per 100 words in the text,
    // and S is the average number of sentences per 100 words in the text.


    // get a paragraph from a user - using a somwhat sophisticated approach.
    // string sample_text = get_string("Text: ");
    // do {
    //     sample_text = get_string("Text: ");
    //     printf("The last character: %c\n", sample_text[strlen(sample_text) - 1]);
    // } while (sample_text[strlen(sample_text) - 1] != '.' && sample_text[strlen(sample_text) - 1] != '!' && sample_text[strlen(sample_text) - 1] != '?');
    // for a text like hello!
    // the first part true false => false
    // hello. false true => false



    string sample_text = get_string("Text: ");

    int tot_words = word_count(sample_text);
    // printf("Total words: %i\n", tot_words);

    int tot_letters = letter_count(sample_text);
    // printf("Total letters: %i\n", tot_letters);

    // test if the function returns correct number of sentences.
    int sntncs_count = sentences_count(sample_text);
    // printf("Total sentences: %d\n", sntncs_count);

    // test average_letters.
    float avg_letters = average_letters(tot_letters, tot_words);
    // printf("L: %.2f\n", avg_letters);

    // average sentences per 100 words
    float avg_sntncs = average_sentences(sntncs_count, tot_words);
    // printf("S: %.2f\n", avg_sntncs);


    // calculate index
    // Formula: index = 0.0588 * L - 0.296 * S - 15.8.

    int index = round(0.0588 * avg_letters - 0.296 * avg_sntncs - 15.8);
    if (index < 0)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else{
        printf("Grade %i\n", index);
    }
    return 0;
}




float average_letters(int tot_letters, int tot_words)
{
    // calculate the average number of words per 100
    float average = (float) tot_letters / (float) tot_words;
    return average * 100;      // average letters per 100 words
}


int word_count(string text)
{
    // This function counts words in the text
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
    int tot_letters = 0;        // this will hold the total letters in the text

    for (int i = 0, len = strlen(text); i < len; i++)
    {
        // check if the current character in the text is a letter
        if isalpha(text[i])
        {
            tot_letters++;      //increment the number of letters
        }
    }

    return tot_letters;
}


int sentences_count(string text)
{
    int sentence_count = 0;


    // no handling edge case like ".hello".
    // assuming no one is going to provide such texts.

    for (int i = 0, len = strlen(text); i < len; i++)
    {
        // check if the current character marks the end of a sentence.
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentence_count++;      //increment the number of sentences.
        }
    }

    return sentence_count;
}


float average_sentences(int sntncs_count, int tot_words)
{
    // simple logic
    // if 10 words ---> 1 sentence
    // then 100 words ---> 1 / 10 * 100 sentences

    float average = (float) sntncs_count / (float) tot_words;
    return average * 100;
}