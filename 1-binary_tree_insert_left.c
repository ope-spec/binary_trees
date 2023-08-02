#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts a node as the left-child of another node
 * @parent: Pointer to the node to insert the left-child in
 * @value: The value to store in the new node
 *
 * Return: Return a pointer to the created node,
 * or NULL on failure or if parent is NULL
 *
 * If parent already has a left-child, the new node must take its place,
 * and the old left-child must be set as the left-child of the new node.
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *newTreeNode;

	if (parent == NULL)
		return (NULL);

	newTreeNode = binary_tree_node(parent, value);
	if (newTreeNode == NULL)
		return (NULL);

	if (parent->left != NULL)
	{
		newTreeNode->left = parent->left;
		parent->left->parent = newTreeNode;
	}

	parent->left = newTreeNode;
	return (newTreeNode);
}
