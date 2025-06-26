#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "cs50.h"

// prototypes 00 here
int check_score(char letter);
int in_string(char c, string char_string);



int main(void)
{
    // remmber to turn all input in Uppercase

    string word = get_string("Enter letter: ");
    int score = 0;

    for (int i = 0, n = strlen(word); i < n; i++)
    {
        score += check_score(toupper(word[i]));
    }
    printf("score for %s: %i\n", word, score);
}





// check for the score/points a particular letter deserves.
int check_score(char letter)
{
    string score_1 = "AEILNORSTU";
    string score_2 = "BCMP";
    string score_3 = "DG";
    string score_4 = "FHVWY";
    string score_5 = "K";
    string score_8 = "JX";
    string score_10 = "QZ";

    int score = 0;

    if (in_string(letter, score_1))
    {
        score = 1;
    }
    else if (in_string(letter, score_2))
    {
        score = 2;
    }
    else if (in_string(letter, score_3))
    {
        score = 3;
    }
    else if (in_string(letter, score_4))
    {
        score = 4;
    }
    else if (in_string(letter, score_5))
    {
        score = 5;
    }
    else if (in_string(letter, score_8))
    {
        score = 8;
    }
    else if (in_string(letter, score_10))
    {
        score = 10;
    }
    else {
        score = 0;
    }
    return score;

}


// check if a particular letter is in the provided string.
int in_string(char c, string char_string)
{
    for (int i = 0, n = strlen(char_string); i < n; i++)
    {
        if (c == char_string[i])
        {
            return true;
        }
    }
    return false;
}
