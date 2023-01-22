#include <stdio.h>
#include <stdlib.h>

typedef struct listint_s
{
    int n;
    struct listint_s *next;
} listint_t;

int is_palindrome(listint_t **head)
{
    if (*head == NULL)
        return 1;

    listint_t *slow = *head, *fast = *head;
    listint_t *prev = NULL, *next;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        next = slow->next;
        slow->next = prev;
        prev = slow;
        slow = next;
    }

    if (fast != NULL)
        slow = slow->next;

    while (slow != NULL)
    {
        if (prev->n != slow->n)
            return 0;
        prev = prev->next;
        slow = slow->next;
    }

    return 1;
}