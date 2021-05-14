#include "binary_trees.h"
/**
 * swap_nodes - swap data of two nodes
 * @a: pointer to first node
 * @b: pointer to second node
 * Return: pointer to node containing data of node a
 */
heap_t *swap_nodes(heap_t *a, heap_t *b)
{
	a->n ^= b->n;
	b->n ^= a->n;
	a->n ^= b->n;

	return (b);
}

/**
 * max_heapify - restore max-heap property for binary tree
 * @node: pointer to root node
 * Return: pointer to tree node containing data of original node
 * or NULL on error
 */
heap_t *max_heapify(heap_t *node)
{
	heap_t *max;

	if (!node)
		return (NULL);
	do {
		max = NULL;
		if (node->left && node->n <= node->left->n)
			max = node->left;
		if (node->right && node->n <= node->right->n &&
				(!max || max->n < node->right->n))
			max = node->right;
		if (max)
			node = swap_nodes(node, max);
	} while (max);
	return (node);
}

/**
 * n_node - find n-th node (BFS order) of tree
 * @node: pointer to root node
 * @n: one-indexed n-th node to find
 * Return: pointer to specified node or NULL on error
 */
heap_t *n_node(heap_t *node, int n)
{
	int bit_idx, m;

	if (!node || n < 0)
		return (NULL);
	for (bit_idx = 0; 1 << (bit_idx + 1) <=  n; ++bit_idx)
		;
	for (--bit_idx; bit_idx >= 0; --bit_idx)
	{
		m = 1 << bit_idx;
		if (n & m)
		{
			if (node->right)
				node = node->right;
			else
				break;
		}
		else
		{
			if (node->left)
				node = node->left;
			else
				break;
		}
	}
	if (bit_idx > -1)
		return (NULL);
	return (node);
}

/**
 * get_size - find size of binary tree
 * @node: pointer to root node of binary tree
 * Return: size of binary tree
 */
int get_size(heap_t *node)
{
	if (!node)
		return (0);
	return (1 + get_size(node->left) + get_size(node->right));
}

/**
 * heap_extract - extract root node from max binary heap
 * @root: double pointer to root node of heap
 * Return: value stored in root node or 0 or failure
 */
int heap_extract(heap_t **root)
{
	static heap_t *prev_root;
	heap_t *node;
	static int size;
	int data;

	if (!root || !*root)
		return (0);
	if (prev_root != *root || (n_node(*root, size + 1)))
	{
		prev_root = *root;
		size = get_size(*root);
	}
	node = n_node(*root, size);
	if (node->parent)
	{
		data = swap_nodes(*root, node)->n;
		if (node->parent->left == node)
			node->parent->left = NULL;
		else
			node->parent->right = NULL;
	}
	else
	{
		data = (*root)->n;
		*root = NULL;
	}
	free(node);
	--size;
	max_heapify(*root);
	return (data);
}
