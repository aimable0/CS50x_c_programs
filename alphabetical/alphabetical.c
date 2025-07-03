#include <stdio.h>
#include "cs50.h"
#include <string.h>
#include <ctype.h>


// function declarations
bool is_in_alpha_order(string string_input);


int main(void)
{
    string my_name = "abeal";

    if (is_in_alpha_order(my_name))
    {
        printf("The string %s is in Alphabetical order\n", my_name);
    }
    else
    {
        printf("The string %s is not in Alphabetical order\n", my_name);
    }
}




bool is_in_alpha_order(string string_input)
{
    // function to check if the strings are in alphabetical order.
    // returns true if in order and false otherwise
    // note: we will convert all the letters in lowercase or uppercase (for smooth comparison)


    for (int i = 0, n = strlen(string_input) - 1; i < n; i++)
    {

        if (tolower(string_input[i]) < tolower(string_input[i + 1]))
        {
            continue; // letters in comparison are in alphabe order
        }
        else
        {
            return true; // the string is not in alphabetical order
        }

    }

    // if no alphabetical disorder detected then the string is in order.
    return true;
}

































// ---------- PSEUDOCODE SPACE ----------
// create a function to check if the strings are in alphabetical order.

// string my_name = "Aimable";

// test the string type
// printf("Hello, Mr %s\n", my_name);

// pseudo code:
// loop through all the letters
// and compare the integer of each letter with the integer of the letter next to it
// if any letter (integer) happens to be less than the letter preceeding it
// then the string is not in alphabetical order
// otherwise the string is in alphabetical order.

// ex according to ASCII a=97 , b=98 therefore,
// if a < b then the string ab is in order
// otherwise the string is not in alphabetical order.

// Let's start small
// suppose I had to a string with only two letters like 'lb'

// The following code would check that for me
// if ('l' < 'b')
// {
//     printf("the string ab is in alphabetical order\n");
// }
// else
// {
//     printf("The string lb is not in alphabetical order\n");
// }

// Let's improve our code to accomadate long strings

// we will assume that the letters are all in lowercase for this time
// string test_string = "abebl";

// to eliminate the issue of comparing that last letter with the \0 (string terminating character):
// we will reduce the number of loops by 1
// for (int i = 0, n = strlen(test_string) - 1; i < n; i++)
// {
//     // let's start by printing all the letter
//     printf("%c\n", test_string[i]);

//     // let's check the order of letters
//     if (test_string[i] < test_string[i + 1])
//     {
//         printf("%c comes before %c Alphabetically\n", test_string[i], test_string[i + 1]);
//     }
//     else
//     {
//         printf("%c comes after %c Alphabetically\n", test_string[i], test_string[i + 1]);
//     }
// }