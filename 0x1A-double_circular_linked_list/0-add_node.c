#include "list.h"

/**
 * add_node_end - Add to end of a double circular linked list
 * @list: list to modify
 * @str: data for new node
 * Return: List | NULL
 */
List *add_node_end(List **list, char *str)
{
	List *new_node;

	if (!str || !list)
		return (NULL);
	new_node = malloc(sizeof(List));
	if (!new_node)
		return (NULL);

	new_node->str = strdup(str);
	if (new_node->str == NULL)
	{
		free(new_node);
		return (NULL);
	}
	new_node->next = new_node;
	new_node->prev = new_node;

	if (*list == NULL)
		*list = new_node;
	else
	{
		new_node->next = *list;
		new_node->prev = (*list)->prev;
		new_node->next->prev = new_node;
		new_node->prev->next = new_node;
	}
	return (new_node);
}

/**
 * add_node_begin - Add to beginning of a double circular linked list
 * @list: list to modify
 * @str: data for new node
 * Return: List | NULL
 */
List *add_node_begin(List **list, char *str)
{
	List *new_node;

	if (!str || !list)
		return (NULL);
	new_node = malloc(sizeof(List));
	if (!new_node)
		return (NULL);

	new_node->str = strdup(str);
	if (new_node->str == NULL)
	{
		free(new_node);
		return (NULL);
	}
	new_node->next = new_node;
	new_node->prev = new_node;

	if (*list)
	{
		new_node->next = *list;
		new_node->prev = (*list)->prev;
		(*list)->prev = new_node;
		new_node->prev->next = new_node;
	}
	*list = new_node;
	return (new_node);
}
