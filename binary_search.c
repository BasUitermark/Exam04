#include "btree.h"

int	binary_search(t_btree *root, int value)
{
	int ret = 0;

	if (!root)
		return (0);
        if (root->value == value)
                return (1);
	if (root->right)
		ret = binary_search(root->right, value);
	if (root->left)
		ret = binary_search(root->left, value);
	return (ret);
}
