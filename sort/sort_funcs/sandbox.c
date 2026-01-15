#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int x = atoi("123");
    int y = atoi("123\n");
    printf("x: %d and Y: %d\n", x, y);;

    char *strnum = "123";
    char *end;
    long value = strtol(strnum, &end, 10);
    printf("num %d\n", (int) value);

    char *string = "\b";
    int val = atoi(string);
    printf("value; %d\n", val);
    return 0;
}
