#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LENGTH 45
typedef struct word_node
{
    char *word;
    struct word_node *next;
} word_node;

// improvemnt: how to use the node in the dictionary...
typedef struct
{
    /* data */
    struct word_node *head;
    struct word_node *tail;
} bucket;

/**
 * hash_function - function that gives me a bucket where to place the name
 *
 * returns: bucket number.
 */
unsigned int hash_function(char *word)
{
    if (strlen(word) == 1)
        //
    if (strlen(word) == 2)

    if (strlen(word) == 3)

    if (strlen(word) > 3)

    return word[0] - 97;
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
    int len = strlen(word) - 1;
    strncpy(temp->word, word, len);

    // will use a hash_function to get where the word should be placed.
    int bucket_nbr = hash_function(word);

    // add node to the bucket..
    if (buckets[bucket_nbr].head != NULL)
    {
        // keep data sorted.
        buckets[bucket_nbr].tail->next = temp;
        buckets[bucket_nbr].tail = temp;
    }
    else
    {
        // add word
        buckets[bucket_nbr].head = temp;
        buckets[bucket_nbr].tail = temp;
    }
}

/**
 * search_in_bucket: searches for a word in the dictionary.
 *
 * return true if word in any of the buckets and false otherwise.
 */
bool search_in_bucket(bucket *buckets, char *search_word)
{
    int bk_nbr = hash_function(search_word);
    word_node *word_list = buckets[bk_nbr].head;
    // traverse the linked list (if any)

    //! test checks
    int checks = 0;
    while (word_list)
    {
        printf("current word: %s\n", word_list->word);

        printf("checks: %d\n", checks++);
        if (strcmp(search_word, word_list->word) == 0)
            return true;
        else if (strcmp(search_word, word_list->word) < 0)
            return false;
        else
            word_list = word_list->next;
    }
    return false;
}

int main(void)
{
    // create an array of buckets
    int tot_buckets = 25; // stored by alphabets
    bucket *buckets = malloc(tot_buckets * sizeof(bucket));
    if (!buckets)
        return 1;

    // initialize buckets
    initialize_buckets(buckets, tot_buckets);

    // load words in buckets from text file.
    // step 1: open file.
    FILE *fp = fopen("names.txt", "r");
    if (!fp)
    {
        free(buckets);
        return 1;
    }

    char *word = malloc(MAX_LENGTH);
    while (fgets(word, MAX_LENGTH, fp))
    {
        int bucket_number = hash_function(word);
        add_word_to_bucket(word, buckets);
    }

    // successfully loaded words to the bucket.
    printf("Successfully loaded words in buffer\n");

    // search for a word
    char search_word[MAX_LENGTH];
    printf("Enter word to search: ");
    scanf("%s", search_word);
    bool word_found = search_in_bucket(buckets, search_word);
    if (word_found)
        printf("Word found!\n");
    else
        printf("Ops! not found.\n");

    // check
    int bk_nbr = hash_function(search_word);
    printf("Bucket number: %d\n", bk_nbr);
    printf("first word in bucket: %s\n", buckets[bk_nbr].head->word);
    printf("last word in bucket: %s\n", buckets[bk_nbr].tail->word);


    // //! how can we free .word
    // finally free.
    fclose(fp);
    free(buckets);
}
