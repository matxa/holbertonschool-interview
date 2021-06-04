#include "lists.h"

/**
 * find_listint_loop - find the loop in the list
 * @head: head of linked list
 * Return: pointer listint_t
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *p1 = head;
	listint_t *p2 = head;

	while (p2 && p2->next)
	{
		p1 = p1->next;
		p2 = p2->next->next;
		if (p1 == p2)
		{
			p1 = head;
			while (p1 != p2)
			{
				p1 = p1->next;
				p2 = p2->next;
			}
			return (p1);
		}
	}
	return (NULL);
}
