#include <stdio.h>

// This programm was discontinued because the card was larger than what a long long int can store

// prototypes
int card_len(long long int card);
int get_product_of_digits_at_odd_positons(int card_digits, long long int card);

int main(void)
{
    long long int card = 400360034;
    int card_digits = card_len(card);

    // test if the total digits is correct.
    printf("Total digits: %i\n", card_digits);
    printf("card: %li\n", card);

    // test
    get_product_of_digits_at_odd_positons(card_digits, card);
}


int card_len(long long int card)
{
    // This programm assumes card will not have only one "zero" as the only digit of the card.
    int count = 0;
    long long int remainder = card;

    while (remainder != 0)
    {
        // every division of 10 is a digit until we get to zero.
        remainder = remainder / 10;
        count++;
    }
    return count;
}


int get_product_of_digits_at_odd_positons(int card_digits, long long int card)
{

    int last_digit;                            // This will hold the current current digit
    long long int current_card_numbers = card; // This will help in holding a changing number of card digits

    for (int i = 0; i < card_digits; i++)
    {
        last_digit = current_card_numbers % 10;
        current_card_numbers = (current_card_numbers - last_digit) / 10;

        // show on screen every other digit
        if (i % 2 != 0)
        {
            printf("%i ", last_digit);
        }
    }
    printf("\n");
}
