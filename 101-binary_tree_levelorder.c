#include "binary_trees.h"

/**
 * binary_tree_levelorder - Traverse a binary tree using level-order traversal
 *
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	queue_t *queue = NULL;
	const binary_tree_t *current;

	queue = queue_push(queue, tree);
	while (queue)
	{
		current = queue->node;
		queue = queue_pop(queue);
		func(current->n);

		if (current->left)
			queue = queue_push(queue, current->left);
		if (current->right)
			queue = queue_push(queue, current->right);
	}

	/* Free the queue */
	while (queue)
	{
		queue_t *temp = queue;
		queue = queue->next;
		free(temp);
	}
}

/**
 * queue_push - Push a node to the queue
 *
 * @queue: Pointer to the front of the queue
 * @node: Pointer to the node to be pushed
 *
 * Return: Pointer to the front of the updated queue
 */
queue_t *queue_push(queue_t *queue, const binary_tree_t *node)
{
	queue_t *new_node, *last;

	new_node = malloc(sizeof(queue_t));
	if (new_node == NULL)
		return (NULL);

	new_node->node = node;
	new_node->next = NULL;

	if (queue == NULL)
		return (new_node);

	last = queue;
	while (last->next)
		last = last->next;

	last->next = new_node;
	return (queue);
}

/**
 * queue_pop - Pop a node from the queue
 *
 * @queue: Pointer to the front of the queue
 *
 * Return: Pointer to the front of the updated queue
 */
queue_t *queue_pop(queue_t *queue)
{
	queue_t *temp;

	if (queue == NULL)
		return (NULL);

	temp = queue->next;
	free(queue);
	return (temp);
}
