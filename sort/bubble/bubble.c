#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void bubble_sort(int *a, int len);

int main(void)
{
    int a[] = {1, 9, 10, 5, 3, 0, -1};
    int size = 7;

    printf("Unsorted: ");
    for (int i = 0; i < size; i++) printf("%d ", a[i]);
    printf("\n");

    bubble_sort(a, size);
    printf("Sorted:  ");
    for (int i = 0; i < size; i++) printf("%d ", a[i]);
    printf("\n");

    return 0;
}

void bubble_sort(int *a, int len)
{
    int sorted = 1;
    while(sorted < len) {
        for(int i = 0; i < len - sorted; i++)
        {
            if (a[i] > a[i+1])
            {
                int temp = a[i];
                a[i] = a[i + 1];
                a[i+1] = temp;
            }
        }
        ++sorted;
    }
    return;
}