#include "binary_trees.h"

/**
 * binary_tree_depth - Measures the depth of a node in a binary tree
 *
 * @tree: Pointer to the node to measure the depth
 * Return: The depth of the node, or 0 if tree is NULL
 * or the node is the root
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	if (tree == NULL)
		return (0);

	while (tree->parent != NULL)
	{
		tree = tree->parent;
		depth++;
	}

	return (depth);
}

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes.
 *
 * @a: Pointer to the first node.
 * first - a
 * @b: Pointer to the second node.
 * second - b
 * Return: Return a pointer to the lowest common ancestor
 * node of the two given nodes
 * If no common ancestor was found, your function must return NULL
 */
binary_tree_t *binary_trees_ancestor(
	const binary_tree_t *a,
	const binary_tree_t *b
)
{
	size_t a_depth, b_depth;

	if (!a || !b)
		return NULL;

	if (a == b)
		return (binary_tree_t *)a;

	a_depth = binary_tree_depth(a);
	b_depth = binary_tree_depth(b);

	while (a_depth > b_depth)
	{
		a = a->parent;
		a_depth--;
	}

	while (b_depth > a_depth)
	{
		b = b->parent;
		b_depth--;
	}

	while (a && b && a != b)
	{
		a = a->parent;
		b = b->parent;
	}

	return (binary_tree_t *)a;
}
