#ifndef BTREE_H
# define BTREE_H

typedef struct s_btree
{
	int				value;
	struct s_btree	*left;
	struct s_btree	*right;
}	t_btree;

t_btree	*binary_tree_insertion(t_btree *root, int value);
void	print_tree(t_btree const *tree);

#endif