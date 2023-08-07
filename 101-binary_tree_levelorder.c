#include "binary_trees.h"
#include "queue.h"

/**
 * binary_tree_levelorder - Performs a level-order traversal on a binary tree
 *
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	queue_t *queue = queue_create();

	if (queue == NULL)
		return;

	enqueue(queue, (void *)tree);

	while (!queue_is_empty(queue))
	{
		binary_tree_t *current = (binary_tree_t *)dequeue(queue);

		func(current->n);


		if (current->left != NULL)
			enqueue(queue, (void *)current->left);

		if (current->right != NULL)
			enqueue(queue, (void *)current->right);
	}

	queue_delete(queue);
}
