// documentation

// linking.
#include <stdio.h>


// definition.


// function declaration
int convert_cel_to_fahr(int cel);
int convert_fahr_to_cel(int fahr);

// global declaration.

int main(void)
{
    // program for converting temperature.
    // formula-1 F = (9C / 5) + 32.
    // formula-2 C = (5F - 160) / 9.

    int temp;
    char type;

    printf("-----------------------\n ------- Welcome to temperature conversion (Cel and Fahr) -----\n");

    printf("What's the Type: (C for cel or F for fahrenheit): ");
    scanf("%c", &type);


    printf("What's the temparature you want use to convert from ? \n");
    printf("Temp: ");
    scanf("%d", &temp);
    printf("temp: .. %d ..\n", temp);
    printf("What's the Type: (C for cel or F for fahrenheit): ");
    // scanf("%c", &type);
    printf("tpyped key is: ..%c .. \n", type);
    printf("got here");

    // if (type == 'c')
    // {
    //     // convert_cel_to_fahr(temp);
    //     printf("%d Celsius equals %d Fahrenheit \n", temp, convert_cel_to_fahr(temp));
    // }
    // else if (type == 'f')
    // {
    //     // convert_fahr_to_cel(temp);
    //     printf("%d Fahrenheit equals %d Celsius \n", temp, convert_fahr_to_cel(temp));
    // }
    // else
    // {
    //     printf("Wrong type.\n");
    // }



    // printf("-------- Bye! -------------");
}



// function to convert C to F
int convert_cel_to_fahr(int cel)
{
    // formula-1 F = (9C / 5) + 32.
    return ((9 * cel) / 5) + 32;
}


// function to convert F to C
int convert_fahr_to_cel(int fahr)
{
    // formula-2 C = (5F - 160) / 9.
    return ((5 * fahr) - 160) / 9;
}