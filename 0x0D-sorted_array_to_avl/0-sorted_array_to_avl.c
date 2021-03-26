#include "binary_trees.h"


/**
 * sorted_array_to_avl - from array to AVL
 * @array: array to convert
 * @size: size of array
 * Return: avl tree
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root;

	if (!array || !size)
		return (NULL);

	root = avl_tree(array, 0, size - 1, NULL);

	return (root);
}

/**
 * avl_tree - from array to avl
 * @array: array
 * @start: start index
 * @end: end index
 * @parent: parent node
 * Return: avl tree
 */

avl_t *avl_tree(int *array, int start, int end, avl_t *parent)
{
	avl_t *new_node;
	int mid;

	if (start > end)
		return (NULL);

	mid = (start + end) / 2;

	new_node = malloc(sizeof(avl_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = array[mid];
	new_node->parent = parent;

	new_node->left = avl_tree(array, start, mid - 1, new_node);
	new_node->right = avl_tree(array, mid + 1, end, new_node);
	return (new_node);
}
