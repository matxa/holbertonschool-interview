#include "lists.h"


/**
 * is_palindrome - check if list is palindrome
 * @head: head of the list
 * Return: 1 if True else 0
 */
int is_palindrome(listint_t **head)
{
	listint_t *temp = *head;
	listint_t *stack = malloc(sizeof(listint_t));

	stack->n = temp->n;
	stack->next = NULL;

	if (head == NULL)
		return (1);

	temp = temp->next;
	while (temp != NULL)
	{
		push(&stack, temp->n);
		temp = temp->next;
	}

	while ((*head) != NULL && stack != NULL)
	{
		if ((*head)->n != stack->n)
			return (0);
		(*head) = (*head)->next;
		stack = stack->next;
	}

	return (1);
}


/**
 * push - add node to head of list
 * @head: head of the list
 * @n: node value
 */
void push(listint_t **head, int n)
{
	listint_t *new_node = malloc(sizeof(listint_t));

	new_node->n = n;
	new_node->next = (*head);

	(*head) = new_node;
}
