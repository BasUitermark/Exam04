#include "btree.h"
#include <stdlib.h>
#include <stdio.h>

// https://prepinsta.com/c-program/insertion-in-a-binary-tree-level-order/

t_btree	*binary_tree_insertion(t_btree *root, int value)
{
	if (!root) {
		t_btree	*new = malloc(sizeof(t_btree));
		new->value = value;
		new->left = NULL;
		new->right = NULL;
		return (new);
	} else if (value > root->value)
		root->right = binary_tree_insertion(root->right, value);
	else if (value < root->value)
		root->left = binary_tree_insertion(root->left, value);
	return (root);
}

void print_tree(t_btree const *tree) {
    if(tree->left) {
        print_tree(tree->left);
	}
    printf("element: %d\n", tree->value);
    if(tree->right) {
        print_tree(tree->right);
    }
}

int	main(void)
{
	t_btree *btree = NULL;

	btree = binary_tree_insertion(btree, 20);
	btree = binary_tree_insertion(btree, 5);
	btree = binary_tree_insertion(btree, 40);

	// btree = btree->right;
	print_tree(btree);
}
