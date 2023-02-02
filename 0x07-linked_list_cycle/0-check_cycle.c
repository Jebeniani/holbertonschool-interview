#include "lists.h"

/**
 * struct listint_s - singly linked list
 * @n: integer
 * @next: points to the next node
 *
 * Return: 0 if there is no cycle
 * 1 if there is a cycle
 */

int check_cycle(listint_t *list)
{
    listint_t *slow, *fast;

    slow = list;
    fast = list;

    while (slow && fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            return 1;
        }
    }

    return 0;
}
