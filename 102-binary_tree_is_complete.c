#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 *
 * @tree: Pointer to the root node of the tree
 * to measure the height
 * Return: If tree is NULL, your function must return 0
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t height_left = 0, height_right = 0;

		height_left = tree->left ? 1 + binary_tree_height(tree->left) : 0;
		height_right = tree->right ? 1 + binary_tree_height(tree->right) : 0;
		return ((height_left > height_right) ? height_left : height_right);
	}
	return (0);
}

/**
 * binary_tree_size - Measures the size of a binary tree
 *
 * @tree: Pointer to the root node of the tree to measure the size
 * Return: If tree is NULL, the function must return 0
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * binary_tree_queue_push - Enqueues a binary tree node to the queue
 *
 * @queue: Pointer to the queue
 * @index: Current index in the queue
 * @node: Pointer to the binary tree node to enqueue
 * Return: Updated queue
 */
binary_tree_t **binary_tree_queue_push(binary_tree_t **queue, size_t index, binary_tree_t *node)
{
	queue[rear] = node;
	return (rear + 1);
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 *
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is complete, otherwise 0
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t idx, size;
	binary_tree_t **queue;

	if (tree == NULL)
		return (0);

	size = binary_tree_size(tree);
	queue = malloc(sizeof(binary_tree_t *) * size);
	if (queue == NULL)
		return (0);

	queue[0] = (binary_tree_t *)tree;
	idx = 0;
	while (idx < size)
	{
		if (queue[idx] == NULL)
			break;
		queue = binary_tree_queue_push(queue, idx, queue[idx]->left);
		queue = binary_tree_queue_push(queue, idx, queue[idx]->right);
		idx++;
	}
	while (idx < size && queue[idx] == NULL)
		idx++;
	free(queue);
	return (idx == size);
}
