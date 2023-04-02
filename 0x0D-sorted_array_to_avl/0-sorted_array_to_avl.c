#include <stdlib.h>
#include "binary_trees.h"

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 *
 * Return: Pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
    if (array == NULL || size == 0)
        return NULL;

    /* Create root node */
    avl_t *root = malloc(sizeof(avl_t));
    if (root == NULL)
        return NULL;
    root->n = array[size / 2];
    root->parent = NULL;

    /* Recursively build left and right subtrees */
    root->left = sorted_array_to_avl(array, size / 2);
    root->right = sorted_array_to_avl(array + size / 2 + 1, size - size / 2 - 1);
    if (root->left != NULL)
        root->left->parent = root;
    if (root->right != NULL)
        root->right->parent = root;

    return root;
}
