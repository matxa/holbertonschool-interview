#include "lists.h"

/**
 * is_palindrome - check if list is palindrome
 * @head: head of the list
 * Return: 1 if True else 0
 */
int is_palindrome(listint_t **head)
{
	int length = list_length(head);
	int *array = linked_list_to_array(head);
	int scan_left = 0;
	int scan_right = length - 1;

	if (head == NULL || length < 2)
		return (1);

	if (length % 2 == 0)
	{
		while ((scan_left <= length / 2) && (scan_right >= length / 2))
		{
			if (array[scan_left] != array[scan_right])
				return (0);
			scan_left += 1;
			scan_right -= 1;
		}
	}
	else
	{
		while ((scan_left < length / 2) && (scan_right > length / 2))
		{
			if (array[scan_left] != array[scan_right])
				return (0);
			scan_left += 1;
			scan_right -= 1;
		}
	}

	return (1);
}

/**
 * list_length - length of a list
 * @head: head of the list
 * Return: length of list
 */
int list_length(listint_t **head)
{
	int list_len = 0;
	listint_t *temp = *head;

	while (temp != NULL)
	{
		list_len += 1;
		temp = temp->next;
	}

	return (list_len);
}

/**
 * linked_list_to_array - make linked list into array
 * @head: head of the list
 * Return: 1 if True else 0
 */
int *linked_list_to_array(listint_t **head)
{
	int array_size = list_length(head);
	int *array = malloc(array_size * sizeof(int));
	listint_t *temp = *head;
	int i = 0;

	while (i != array_size && temp != NULL)
	{
		array[i] = temp->n;
		i += 1;
		temp = temp->next;
	}

	return (array);
}
