#include <stdio.h>



// This program attempts to create a user defined bool type

int main(void)
{
    enum bool {true = 1 , false = 0};


    enum bool valid;
    valid = true;


    if (valid)
    {
        printf("Yes this is a true bool\n");
    }
    else if (valid == false)
    {
        printf("Opps not sure if this is a bool\n");
    }

    // change valid to false and test.
    valid = false;

    if (valid)  // not true is true, because valid is false.
    {
        printf("This is true bool\n");
    }
    else
    {
        printf("THis is false bool\n");
    }

    if (true)
    {
        printf("Hello kigali! -- its true");
    }

}
