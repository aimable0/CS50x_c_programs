#include <stdio.h>
#include <cs50.h>


int get_product_of_digits_at_odd_positons(int tot_digits, long card_number);
int card_len(long card);

int main(void)
{
    long card_number = get_long("Enter Card: ");
    int tot_digits = card_len(card_number);
    printf("Card number: %li\n", card_number);
    printf("card-digits: %i\n", tot_digits);

    // test
    int sum = get_product_of_digits_at_odd_positons(tot_digits, card_number);
    printf("The first half product is: %i\n", sum);
}




int card_len(long card)
{
    // calculates length of the card
    // This programm assumes card will not have only one "zero" as the only digit of the card.
    int count = 0;
    long remainder = card;

    while (remainder != 0)
    {
        // every division of 10 is a digit until we get to zero.
        remainder = remainder / 10;
        count++;
    }
    return count;
}




int get_product_of_digits_at_odd_positons(int tot_digits, long card_number)
{

    // This function calculates the sum of a card's digits using Hans Peter's Algorithm.

    int last_digit;                                     // This will hold the current digit
    long current_card_numbers = card_number;          // This will help in holding a changing number of card number.
    int sum = 0;

    for (int i = 0; i < tot_digits; i++)
    {
        last_digit = current_card_numbers % 10;
        current_card_numbers = (current_card_numbers - last_digit) / 10;

        // every other digit
        if (i % 2 != 0)
        {
            if ((last_digit * 2) > 9)
            {
                // handle digits that get's over 9 when mutliplied

                int first_digit = (last_digit * 2) % 10;
                int second_digit = ((last_digit * 2) - first_digit) / 10;
                sum += first_digit;
                sum += second_digit;

            }
            else {
                // add the curerent digit (multiplied by 2) to the overall sum
                sum += last_digit * 2;
            }
        }

        // next digit
        if (i % 2 == 0 )
        {
            // add the other digit to the overall sum
            sum += last_digit;
        }
    }


    return sum;
}

