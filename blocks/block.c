#include <stdio.h>

void print_hash(int h);

int main(void)
{
    print_hash(4);

    return 0;
}

void print_hash(int h)
{
    if (h <= 0)
        return;
    print_hash(h - 1);
    for (int i = h; i > 0; i--)
        printf("# ");
    printf("\n");
}
