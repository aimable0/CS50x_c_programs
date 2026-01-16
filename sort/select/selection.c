#include <stdio.h>
#include <stdlib.h>

#define SIZE 5000

void selection_sort(int *a, int len);

int main(int argc, char *argv[])
{
    // Read from file
    FILE *fp = fopen(argv[1], "r");

    if (fp == NULL)
    {
        printf("Failed to open the file\n");
        return 1;
    }

    int array[SIZE];
    char strnum[6];
    int i = 0;
    char *end;
    while (fgets(strnum, sizeof(strnum), fp) != NULL)
    {
        long value = strtol(strnum, &end, 10);
        array[i++] = (int)value;
        if (i >= 5000)
            break;
    }

    fclose(fp);

    // Write to a newfile sorted data.
    selection_sort(array, 5000); // sort array.

    FILE *fp2 = fopen("sorted5000.txt", "w");
    i = 0;
    if (fp2 != NULL)
    {
        while (i < 5000)
            fprintf(fp2, "%d\n", array[i++]);
    }

    fclose(fp2);

    return 0;
}

void selection_sort(int *a, int len)
{
    int temp;
    int smallest;
    int index;

    for (int j = 0; j < len; j++)
    {
        smallest = a[j];
        index = j;
        for (int i = j; i < len; i++)
        {
            if (smallest > a[i])
            {
                smallest = a[i];
                index = i;
            }
        }
        temp = a[j];
        a[j] = smallest;
        a[index] = temp;
    }
}
