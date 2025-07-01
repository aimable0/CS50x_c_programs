#include <stdio.h>
#include <math.h>


double is_decimal(double num);
int convert_to_int(double num);

int main(void)
{
    // program that reads a decimal form and output it into integer
    // ex: 15.95 => 1595

    double number = 1234.89;

    if (is_decimal(number))
    {
        int number_int;
        number_int = convert_to_int(number);

        printf("Decimal form: %f\n", number);
        printf("Number Paise form: %d", number_int);
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

    while ((int)num != num)
    {
        num *= pow(10, 1);
    }
    return num;
}