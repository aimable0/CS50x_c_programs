#include <stdio.h>

// prototyping the function before using it so it can be recognized
int get_min_coins(int change_owed);


int main(void)
{
    int change_owed = 113;
    int min_coins = get_min_coins(change_owed);
    printf("%i", min_coins);

}


// calculate min change func
int get_min_coins(int change_owed)
{
    int min_coins = 0;

    while (change_owed > 0)
    {
        printf("I'm looping\n");

        if (change_owed >= 25)
        {
            printf("got on 25\n");
            change_owed -= 25;
            min_coins++;
        }
        else if (change_owed >= 10)
        {
            printf("got on 10\n");
            change_owed -= 10;
            min_coins++;
        }
        else if (change_owed >= 5)
        {
            printf("got on 5\n");
            change_owed -= 10;
            min_coins++;
        }
        else if (change_owed >= 1)
        {
            printf("got on 1\n");
            change_owed -= 1;
            min_coins++;
        }
        else
        {
            return min_coins;
        }
    }
    return min_coins;
}