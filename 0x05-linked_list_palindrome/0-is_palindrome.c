#include "lists.h"


/**
 * is_palindrome - check if list is palindrome
 * @head: head of the list
 * Return: 1 if True else 0
 */
int is_palindrome(listint_t **head)
{
	if (head == NULL && *head == NULL)
		return (1);
	else
		return (check(head, *head));
}


/**
 * check - check
 * @left: - **head
 * @right: - *head
 * Return: 1 if good else 0
 */
int check(listint_t **left, listint_t *right)
{
	if (right == NULL)
		return (1);

	if (check(left, right->next) && (*left)->n == right->n)
	{
		*left = (*left)->next;
		return (1);
	}
	else
	{
		return (0);
	}

}
