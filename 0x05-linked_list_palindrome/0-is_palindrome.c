#include "lists.h"
/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: double pointer to the head of the singly linked list
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */
int is_palindrome(listint_t **head)
{
    listint_t *slow = *head, *fast = *head;
    listint_t *second_half, *slow_prev = *head;
    listint_t *middle_node = NULL;
    int result = 0;

    if (*head != NULL && (*head)->next != NULL)
    {
        while (fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
        }

        if (fast != NULL)
        {
            middle_node = slow;
            slow = slow->next;
        }

        second_half = slow;
        slow_prev->next = NULL;
        reverse(&second_half);
        result = compare(head, second_half);

        reverse(&second_half);

        if (middle_node != NULL)
        {
            slow_prev->next = middle_node;
            middle_node->next = second_half;
        }
        else
        {
            slow_prev->next = second_half;
        }
    }
    return (result);
}


/**
 * reverse - reverses a linked list
 * @head: pointer to the head of the linked list
 * Return: is void
 */
void reverse(listint_t **head)
{
    listint_t *prev = NULL;
    listint_t *current = *head;
    listint_t *next;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

/**
 * compare - compares 2 linked lists
 * @head1: double pointer to head of linked list
 * @head2: pointer to head of the second linked list
 * Return: 0 if true, 1 if flase
 */
int compare(listint_t **head1, listint_t *head2)
{
    listint_t *temp1 = *head1;
    listint_t *temp2 = head2;

    while (temp1 && temp2)
    {
        if (temp1->n == temp2->n)
        {
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        else
        {
            return (0);
        }
    }
    if (temp1 == NULL && temp2 == NULL)
    {
        return (1);
    }
    return (0);
}