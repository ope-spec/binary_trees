#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * binary_tree_enqueue - Enqueue a binary tree node into a queue
 *
 * @queue: Pointer to the queue
 * @node: Pointer to the node to enqueue
 */
void binary_tree_enqueue(binary_tree_t **queue, const binary_tree_t *node)
{
	binary_tree_t *new_node = binary_tree_node(NULL, 0);

	if (!new_node)
		return;

	new_node->left = (binary_tree_t *)node;
	new_node->right = *queue;

	*queue = new_node;
}

/**
 * binary_tree_dequeue - Dequeue a binary tree node from a queue
 *
 * @queue: Pointer to the queue
 *
 * Return: Pointer to the dequeued node
 */
binary_tree_t *binary_tree_dequeue(binary_tree_t **queue)
{
	binary_tree_t *current = *queue;
	binary_tree_t *prev = NULL;

	if (!queue || !*queue)
		return (NULL);

	while (current->right)
	{
		prev = current;
		current = current->right;
	}

	if (prev)
		prev->right = NULL;
	else
		*queue = NULL;

	return (current->left);
}

/**
 * binary_tree_levelorder - Traverse a binary tree using level-order traversal
 *
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	binary_tree_t *queue = NULL;
	const binary_tree_t *current = tree;

	if (!tree || !func)
		return;

	binary_tree_enqueue(&queue, current);

	while (queue)
	{
		current = binary_tree_dequeue(&queue);
		func(current->n);

		if (current->left)
			binary_tree_enqueue(&queue, current->left);

		if (current->right)
			binary_tree_enqueue(&queue, current->right);
	}
}
