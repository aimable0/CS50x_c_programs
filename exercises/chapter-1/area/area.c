// Documentation
// in this program I will try to calculate the area of a circle
// given the points that makes up the diameter

#include <stdio.h>
#include <math.h>

#define PI 3.14159265359

// function declarations
float calc_area(float radius);
float calc_dstnce_btn(float x1, float x2, float y1, float y2);
float calc_radius(float d);

int main(void)
{
    // points that makes up the diameter
    // Format: (x1, y1) (x2, y2)
    // sample: (2,2) (5,6)

    float x1 = 2, y1 = 2, x2 = 5, y2 = 6;
    float distance = calc_dstnce_btn(x1, x2, y1, y2);
    float radius = calc_radius(distance);
    float area = calc_area(radius);
    printf("Area: %5.2f", area);
}

// calculates the distance between points
float calc_dstnce_btn(float x1, float x2, float y1, float y2)
{
    float d;
    // possible approach
    // d = sqrt(((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1)));

    // improved version using math library function ex: pow(a, 2) a raised to the pow of 2--
    d = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
    return d; // return distance between the given points
}

// calculates the radius given dimeter
float calc_radius(float d)
{
    // formular d = 2r   d: diameter r: radius
    return d / 2; // return radius.
}

// calculates area using radius
float calc_area(float radius)
{
    float area;
    area = PI * pow(radius, 2);
    return area;
}
