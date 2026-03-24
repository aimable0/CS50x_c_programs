#include <stdio.h>

int main(void)
{
    FILE *fp = fopen("names.txt", "r");
    if (!fp)
        return 1;

    char name[256];
    while (fgets(name, sizeof(name), fp))
        printf("Name: %s", name);
    return 0;
}
