#include <stdio.h>
#include <math.h>


double is_decimal(double num);
int convert_to_int(double num);

int main(void)
{
    // program that reads a decimal form input and output it into integer
    // ex: 15.95 => 1595

    double number = 19.991131; // doubles have a limit something like 1.19861 would give you a bad error

    if (is_decimal(number))
    {
        int paise;
        paise = convert_to_int(number);

        printf("Decimal form: %f\n", number);
        printf("Paise form: %d paise\n", paise);
    }
    else
    {
        printf("The number: %f has no decimal part", number);
    }
}


double is_decimal(double num)
{
    int true = 1;
    int false = 0;

    if ((int)num == num)
    {
        return false;       // the number has no decimal part
    }
    else
    {
        return true;        // the number has a decimal part
    }
}



int convert_to_int(double num)
{
    // this function may produce incorrect result
    // because of how double and floating-point numbers work in C
    // — they often cannot represent decimal values exactly.
    // use it with caution.
    // Numbers like 1231.1986 can't be stored precisely in binary.

    // So num might never become an exact integer, even after many multiplications
    // the condition (int)num != num might never be false, resulting in an infinite loop.
    // which we tried to force escape by limiting loops to 5
    // so this works well only up to 4 or 5 decimal points -- beyond that - the other decimals are ignored.

    int count = 0;

    while ((int)num != num)
    {
        if (count > 4)
        {
            break;
        }
        num *= pow(10, 1);
        count++;
    }
    return num;
}


// int convert_to_int(doublenum)
// {

//     printf("got here in the convert function\n");

//     doubled_num = num;

//     while (1)
//     {
//         if ((int) d_num == d_num)
//         {
//             break;
//         }
//         else
//         {
//             d_num *= pow(10, 1);
//         }
//     }

//     return (int) d_num;
// }