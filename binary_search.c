#include "btree.h"
#include <stdlib.h>
#include <stdio.h>

int	binary_search(t_btree *root, int value)
{
	int	ret = 0;

	if (!root)
		return (0);
	if (root->value == value)
		return (1);
	if (root->right && ret == 0)
		ret = binary_search(root->right, value);
	if (root->left && ret == 0)
		ret = binary_search(root->left, value);
	return (ret);
}

int main(int argc, char const *argv[])
{
	t_btree	*test = NULL;

	test = binary_tree_insertion(test, 20);
	test = binary_tree_insertion(test, 5);
	test = binary_tree_insertion(test, 40);
	test = binary_tree_insertion(test, 80);
	test = binary_tree_insertion(test, 75);

	if (binary_search(test, 75))
		printf("Found\n");
	else
		printf("Not found\n");
	return 0;
}
