#include "binary_trees.h"

/**
 * binary_tree_insert_right - Inserts a node as the right-child of another node
 * @parent: Pointer to the node to insert the right-child in
 * @value: The value to store in the new node
 *
 * Return: A pointer to the created node,
 * or NULL on failure or if parent is NULL
 *
 * If parent already has a right-child, the new node must take its place,
 * and the old right-child must be set as the right-child of the new node.
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *newTreeNode;

	if (parent == NULL)
		return (NULL);

	newTreeNode = binary_tree_node(parent, value);
	if (newTreeNode == NULL)
		return (NULL);

	if (parent->right != NULL)
	{
		newTreeNode->right = parent->right;
		parent->right->parent = newTreeNode;
	}

	parent->right = newTreeNode;
	return (newTreeNode);
}
