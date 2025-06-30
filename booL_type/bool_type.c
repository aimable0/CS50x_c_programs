#include <stdio.h>




int main(void)
{
    enum bool {true = 1 , false = 0};
    // bool valid = true;
    // enum bool valid = true;
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

    valid = false;

    if (!valid)  // not true is true, because valid is false.
    {
        printf("This is false bool\n");
    }
    else
    {
        printf("THis is true bool\n");
    }
}
