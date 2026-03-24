#include <stdio.h>
#include <stdbool.h>

typedef struct node
{
    int value;
    struct node *left;
    struct node *right;
} node;

bool search(node *tree, int number);

int main(void)
{

}

bool search(node *tree, int number)
{
    if (tree == NULL)
    {
        return false;
    }

    // search for a number
    if (tree->value == number)
    {
        return true;
    }
    else if (tree->value < number)
    {
        search(tree->right, number);
    }
    else if (tree->value > number)
    {
        search(tree->left, number);
    }
}
