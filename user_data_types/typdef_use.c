#include <stdio.h>

int main(void)
{
    typedef int age;

    // this is a little better since it can heplp n readbality
    // the following can be interpreted as person1 variable stores age data for person1.
    age person1 = 20;
    age person2 = 30;

    printf("%d\n", person1);
    printf("%d\n", person2);

    // check the size of the 'age' data type
    // we can use sizeof(datatype) and %zu to print the size in bytes.
    printf("our short int renamed to age has: %zu bytes size.\n", sizeof(age));

}