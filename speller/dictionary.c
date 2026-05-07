// Implements a dictionary's functionality

#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

const unsigned int N = 17577;

// Hash table
node *table[N];
unsigned int tot_words = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int bk_nbr = hash(word);
    node *word_list = table[bk_nbr];

    while (word_list)
    {
        int comp_value = strcasecmp(word, word_list->word);
        if (comp_value == 0)
            return true;
        else if (comp_value < 0)
            return false;
        word_list = word_list->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    if (strlen(word) < 3)
    {
        return 17576; // special bucket for words less than 3 chars.
    }
    int char_dig1 = (tolower(word[0]) - 96);
    int char_dig2 = (tolower(word[1]) - 96);
    int char_dig3 = (tolower(word[2]) - 96);
    int pos = (676 * (char_dig1 - 1)) + (26 * (char_dig2 - 1)) + char_dig3;
    return pos - 1; // -1 for zero-based indexing.
}

// initialize table
void initialize()
{
    for (int i = 0; i < N; i++)
    {
        table[i] = malloc(sizeof(node));
        if (!table[i])
            exit(1);
        table[i]->next = NULL;
        strcpy(table[i]->word, "");
    }
}
bool add_word_to_bucket(char *word)
{
    int bucket_nbr = hash(word);
    int len = strlen(word);
    if (strcmp(table[bucket_nbr]->word, "") == 0)
    {
        strncpy(table[bucket_nbr]->word, word, len);
        table[bucket_nbr]->next = NULL;
    }
    else
    {
        node *temp1 = table[bucket_nbr];
        while (temp1->next)
            temp1 = temp1->next;

        node *temp2 = malloc(sizeof(node));
        if (!temp2)
            return false;

        strncpy(temp2->word, word, len);
        temp2->next = NULL;
        temp1->next = temp2;
    }

    tot_words++;
    return true;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // load words in buckets from text file.
    FILE *fp = fopen(dictionary, "r");
    if (!fp)
        return false;

    initialize();
    char word[LENGTH + 1];
    bool return_value;
    while (fscanf(fp, "%s", word) == 1)
    {
        word[strcspn(word, "\n")] = '\0';
        return_value = add_word_to_bucket(word);
        if (!return_value)
            return false;
    }

    fclose(fp);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return tot_words;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        while (table[i]->next)
        {
            node *temp = table[i]->next;
            free(table[i]);
            table[i] = temp;
        }
        free(table[i]);
    }
    return true;
}
