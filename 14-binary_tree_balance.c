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

		height_left = tree->left ? 1 + binary_tree_height(tree->left) : 1;
		height_right = tree->right ? 1 + binary_tree_height(tree->right) : 1;
		return ((height_left > height_right) ? height_left : height_right);
	}
	return (0);
}

/**
 * binary_tree_balance - Measures the balance factor of a binary tree
 *
 * @tree: Pointer to the root node of the tree
 * to measure the balance factor
 * Return: Return 0 if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree)
		return (binary_tree_height(tree->left) - binary_tree_height(tree->right));
	return (0);
}
