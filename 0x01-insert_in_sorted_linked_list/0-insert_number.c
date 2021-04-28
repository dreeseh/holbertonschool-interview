#include "lists.h"
/**
 * insert_node - inserts a node into the linked list
 * @head: pointer to pointer of first node of listint_t list
 * @number: number to be inserted into node
 * Return: address of the new element or NULL if it fails
 */
listint_t *insert_node(listint_t **head, int number)
{
    listint_t *current, *new;

    current = *head;

    new = malloc(sizeof(listint_t));
    if (new == NULL)
        return (NULL);

    new->n = number;
    new->next = NULL;

    if (*head == NULL || (*head)->n >= new->n)
    {
        new->next = *head;
        *head = new;
    }
    else {
        current = *head;
        while (current->next != NULL && current->next->n < new->n)
        {
            current = current->next;
        }
        new->next = current->next;
        current->next = new;
    }

    return (new);
}