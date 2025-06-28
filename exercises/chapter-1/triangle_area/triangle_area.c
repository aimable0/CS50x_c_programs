// documentation

// linking
#include <stdio.h>
#include <math.h>

// definition

//  function declaration
float calc_area(int a, int b, int c);
int valid_tria(int a, int b, int c);
// global variable definition.


// main program
int main(void)
{

    // calculating the area of triangle and displaying it on screen.
    // get sides from user input
    int a, b, c;
    a = b = c = 0;
    printf("Enter sides below: (a b c)\n");
    scanf("%d %d %d", &a, &b, &c);      // getting three numbers from the user


    // check if triangle is valid and print area
    if (valid_tria(a, b, c))
    {
        printf("Sides: %i, %i, %i\n", a, b, c);
        printf("Area: %.2f\n", calc_area(a, b, c));
    }
    else
    {
        printf("Invalid triangle");
    }
}



// function calculates the area of a given triangle.
float calc_area(int a, int b, int c)
{
    // translating the area formular into c
    // Note: This function doesn't check for valid triangle sides
    float area;
    float S;
    S = (a + b + c) / 2;
    area = (float) sqrt(S * (S - a) * (S - b) * (S - c));
    return area;
}


// checks if the given sides makes up a valid triangle
int valid_tria(int a, int b, int c)
{

    if ( a > 0 && b > 0 && c > 0)
    {
        if ((a + b > c) && (a + c > b) && (b + c > a))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }
}
