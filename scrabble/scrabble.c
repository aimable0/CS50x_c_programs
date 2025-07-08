

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "cs50.h"

// function declarations.
int check_score(char letter);
int in_string(char c, string char_string);

int main(void)
{
    // get player's word.
    string player_1 = "drawing";
    string player_2 = "illustration";
    // string player_1 = get_string("Player 1: ");
    // string player_2 = get_string("Player 2: ");
    int score_1 = 0;
    int score_2 = 0;

    for (int i = 0, len = strlen(player_1); i < len; i++)
    {
        score_1 += check_score(toupper(player_1[i]));
    }

    for (int i = 0, len = strlen(player_2); i < len; i++)
    {
        score_2 += check_score(toupper(player_2[i]));
    }

    if (score_1 > score_2)
    {
        printf("Player 1 Wins!\n");
    }
    else if (score_1 < score_2)
    {
        printf("Player 2 Wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int check_score(char letter)
{
    // check for the score/points a particular letter deserves.

    string score_1 = "AEILNORSTU";
    string score_2 = "DG";
    string score_3 = "BCMP";
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
    else
    {
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
