#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LENGTH 45
#define TOT_BUCKETS 17577

/* Protos and defs */
typedef struct word_node
{
    char *word;
    struct word_node *next;
} word_node;

typedef struct
{
    /* data */
    struct word_node *head;
    struct word_node *tail;
} bucket;

unsigned int my_strlen(char *word)
{
    int size = 0;
    char c = word[0];
    int i = 1;
    // note: the '\n' is being in this case
    // since fgets is adding newline at the end of words.
    while (c != '\0' && c != '\n')
    {
        c = word[i++];
        size++;
    }
    return size;
}

// String to lower
char *string_to_lower(char *word)
{
    char *s = malloc(MAX_LENGTH);
    int len = my_strlen(word);
    int i = 0;
    for (i = 0; i < len; i++)
        s[i] = tolower(word[i]);
    s[i] = '\0';

    return s;
}

/**
 * hash_function - function that gives me a bucket where to place the name
 *
 * returns: bucket number.
 */
unsigned int hash_function(char *word)
{

    if (my_strlen(word) < 3)
    {
        return 17576; // special bucket for words less than 3 chars.
    }
    int char_dig1 = (tolower(word[0]) - 96);
    int char_dig2 = (tolower(word[1]) - 96);
    int char_dig3 = (tolower(word[2]) - 96);
    int pos = (676 * (char_dig1 - 1)) + (26 * (char_dig2 - 1)) + char_dig3;
    return pos - 1; // -1 for zero-based indexing.
}

void initialize_buckets(bucket *buckets, int tot_buckets)
{
    for (int i = 0; i < tot_buckets; i++)
        buckets[i].head = NULL;
}

void add_word_to_bucket(char *word, bucket *buckets)
{
    // create a word node
    word_node *temp = malloc(sizeof(word_node));
    if (!temp)
    {
        perror("Malloc failed\n");
        exit(1);
    }

    temp->next = NULL;
    temp->word = malloc(MAX_LENGTH);

    if (!temp->word)
    {
        free(temp);
        perror("Malloc failed\n");
        exit(1);
    }
    int len = my_strlen(word);
    strncpy(temp->word, word, len);

    // will use a hash_function to get where the word should be placed.
    int bucket_nbr = hash_function(word);

    // add node to the bucket..
    if (buckets[bucket_nbr].head != NULL)
    {
        buckets[bucket_nbr].tail->next = temp;
        buckets[bucket_nbr].tail = temp;
    }
    else
    {
        // add word for the first time.
        buckets[bucket_nbr].head = temp;
        buckets[bucket_nbr].tail = temp;
    }
}

/**
 * search_in_bucket - searches for a word in the dictionary.
 *
 * return: true if word in any of the buckets and false otherwise.
 */
bool search_in_bucket(bucket *buckets, char *search_word)
{
    int bk_nbr = hash_function(search_word);
    word_node *word_list = buckets[bk_nbr].head;

    //! Test
    int i = 0;
    //! Test
    while (word_list)
    {
        //! Test
        printf("checking %d\n", i++);
        //! Test
        if (strcmp(string_to_lower(search_word), (word_list->word)) == 0)
            return true;
        else if (strcmp(string_to_lower(search_word), word_list->word) < 0)
            return false;
        else
            word_list = word_list->next;
    }
    return false;
}

int main(void)
{
    // create an array of buckets
    int tot_buckets = TOT_BUCKETS; // stored by alphabets
    bucket *buckets = malloc(tot_buckets * sizeof(bucket));
    if (!buckets)
    {
        perror("Malloc failed while creating buckets");
        return 1;
    }

    initialize_buckets(buckets, tot_buckets);

    // load words in buckets from text file.
    FILE *fp = fopen("large.txt", "r");
    if (!fp)
    {
        perror("File failed to open");
        free(buckets);
        return 1;
    }

    char *word = malloc(MAX_LENGTH);

    while (fscanf(fp, "%s", word) == 1)
    {
        word[my_strlen(word)] = '\0'; // remove trailing '\n'.
        add_word_to_bucket(word, buckets);
    }
    printf("Dictionary successfully loaded!\n");

    // search for a word
    // char search_word[MAX_LENGTH];
    // printf("Enter word to search: ");
    // scanf("%s", search_word);
    // bool word_found = search_in_bucket(buckets, search_word);
    // int buck_nbr = hash_function(search_word);
    // if (word_found)
    //     printf("Word found in bucket %d!\n", buck_nbr);
    // else
    //     printf("Ops! not found.\n");

    //! Test
    int g = 17576;
    // words in last bucket.
    word_node *temp = buckets[g].head;
    printf("Words in 17576 bucket:\n");
    while (temp)
    {
        printf("\t %s\n", temp->word);
        temp = temp->next;
    }
    //! Test

    //! how can we free The space we have manually allocated.
    fclose(fp);
    free(buckets);
}
