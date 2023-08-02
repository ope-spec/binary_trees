#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 *
 * @tree: Pointer to the node to measure the height
 * Return: If tree is NULL, your function must return 0
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	size_t height_left = 0, height_right = 0;

		height_left = tree->left ? 1 + binary_tree_height(tree->left) : 0;
		height_right = tree->right ? 1 + binary_tree_height(tree->right) : 0;

	return ((height_left > height_right) ? height_left : height_right);

}
