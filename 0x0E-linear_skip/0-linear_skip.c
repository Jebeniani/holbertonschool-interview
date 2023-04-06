#include "search.h"

/**
 * linear_skip - searches for a value in a sorted skip list of integers
 * @list: pointer to the head of the skip list to search in
 * @value: the value to search for
 *
 * Return: pointer to the first node where value is located,
 *         or NULL if value is not present in list or if head is NULL
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
    skiplist_t *express, *prev;

    if (list == NULL)
        return (NULL);

    /* Traverse the express lane until the value is found or passed */
    for (express = list->express; express && express->n < value; express = express->express)
    {
        printf("Value checked at index [%lu] = [%d]\n", express->index, express->n);
        prev = express;
    }

    /* Traverse the normal lane between the last express node and the value */
    if (!express)
    {
        /* If the end of the list is reached on the express lane, traverse the last nodes */
        list = prev;
        while (list->next)
            list = list->next;
    }
    else
    {
        list = express;
    }

    while (list && list->n < value)
    {
        printf("Value checked at index [%lu] = [%d]\n", list->index, list->n);
        list = list->next;
    }

    /* If the value is found, return the node, otherwise return NULL */
    if (list && list->n == value)
    {
        printf("Value checked at index [%lu] = [%d]\n", list->index, list->n);
        return (list);
    }

    return (NULL);
}
