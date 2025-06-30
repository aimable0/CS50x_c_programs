// documentation -section

// linking -section
#include <stdio.h>
#include <math.h>

// definition -section

// declararion -section
float calc_dstnce_btn(float x1, float x2, float y1, float y2);

// global variable declaration -section

// main function -section
int main(void)
{

    float x1, x2, y1, y2;
    // float d; // this will store the distance between two points
    // d = calc_dstance_btn(x1, x2, y1, y2);

    // get the coordinates from user.
    printf("Enter x and y coordinates below: (x1 y1 x2 y2)\n");

    // the scanf doesn't work pretty well with float format like %5.2f or %.2f in my experience.
    scanf("%f %f %f %f", &x1, &y1, &x2, &y2);
    printf("Point (%5.2f %5.2f) and (%5.2f %5.2f) \n", x1, y1, x2, y2);

    // calculate the distance between the coordinates and print them.
    printf("Distance between D: %5.2f", calc_dstnce_btn(x1, x2, y1, y2));
}

// user-defined function -section
float calc_dstnce_btn(float x1, float x2, float y1, float y2)
{
    float d;
    // one possible version
    // d = sqrt(((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1)));

    // improved version using math library function ex: pow(a, 2) a raised to the pow of 2--
    d = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
    return d;
}
