#include "lists.h"


/**
 * is_palindrome - check if list is palindrome
 * @head: head of the list
 * Return: 1 if True else 0
 */
int is_palindrome(listint_t **head)
{
	listint_t *reversed_list = *head;

	reverse_listint(&reversed_list);

	while ((*head) != NULL && reversed_list != NULL)
	{
		if ((*head)->n != reversed_list->n)
		{
			printf("ORIG - %d <-> REV - %d\n", (*head)->n, reversed_list->n);
			return (0);
		}
		(*head) = (*head)->next;
		reversed_list = reversed_list->next;
	}

	return (1);
}


/**
 * reverse_listint - reverse list
 * @head: - head
 * Return: list
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *fir;
	listint_t *res;

	if (*head == NULL)
		return (NULL);

	fir = *head;
	res = fir->next;

	if (res == NULL)
	{
		return (NULL);
	}

	reverse_listint(&res);
	fir->next->next = fir;

	fir->next = NULL;

	*head = res;

	return (res);
}
