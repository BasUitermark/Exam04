#include "btree.h"
#include <stdlib.h>
#include <stdio.h>

// https://prepinsta.com/c-program/insertion-in-a-binary-tree-level-order/

t_btree	*binary_tree_insertion(t_btree *root, int value)
{
	t_btree	*new = malloc(sizeof(t_btree));

	new->value = value;
	new->left = NULL;
	new->right = NULL;
	if (!root)
		return (new);

	if (value > root->value)
		root = binary_tree_insertion(root->right, value);
	else if (value < root->value)
		root = binary_tree_insertion(root->left, value);
	return (root);
}

int	main(void)
{
	t_btree *btree = NULL;

	btree = binary_tree_insertion(btree, 20);
	btree = binary_tree_insertion(btree, 5);
	btree = binary_tree_insertion(btree, 40);

	// btree = btree->right;
	printf("%d\n", btree->value);
}
