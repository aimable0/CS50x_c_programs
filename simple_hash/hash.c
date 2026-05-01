#include <stdio.h>

/**
 * hash_function - function that gives me a bucket where to place the name
 * I will have 25 buckets that each giving me a letter
*/

unsigned int hash_function(char *name)
{
    // returns a value of where to place the word
    return name[0] - 97;
}

int main(void)
{

}
