#include "binary_trees.h"

/**
 * binary_tree_node - Creates a binary tree node
 * @parent: Pointer to the parent node of the node to create
 * @value: The value to put in the new node
 *
 * Return: return a pointer to the new node, or NULL on failure
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *newTreeNode = malloc(sizeof(binary_tree_t));

	if (newTreeNode == NULL)
		return (NULL);

	newTreeNode->n = value;
	newTreeNode->parent = parent;
	newTreeNode->left = NULL;
	newTreeNode->right = NULL;

	return (newTreeNode);
}
