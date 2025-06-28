#include <stdio.h>
#define PI 3.14159265359


int main(void)
{
    // The program calculates area of a circle given radius
    // formula area = Pir^2

    float r = 2;
    float area = PI * (r * r);
    printf("A circle of radius: %5.2f has an area of %5.5f\n", r, area);
}