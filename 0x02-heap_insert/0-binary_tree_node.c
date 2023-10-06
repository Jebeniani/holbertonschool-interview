#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_node - add a node to the tree
 *
 * @parent: parent node
 * @value: value  node
 *
 * Return: The height of the tree starting at @node
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
binary_tree_t *new_node;

new_node = malloc(sizeof(binary_tree_t));
if (new_node == NULL)
{
return (NULL);
}
new_node->n = value;
new_node->parent = parent ? parent : NULL;
new_node->left = NULL;
new_node->right = NULL;

return (new_node);
}
