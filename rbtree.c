
#include "collections_header.h"


t_rbtr	*ft_create_rbtree(int (*func_cmp)(void *, void *), void (*func_del)(void *))
{
	t_rbtr	*tree;

	if (!func_cmp)
		return (NULL);
	tree = ft_memalloc(sizeof(t_rbtr));
	if (tree)
	{
		tree->func_cmp = func_cmp;
		tree->func_del = func_del;
	}
	return (tree);
}

void	ft_rbtree_add(t_rbtr *tree, void *value)
{
	t_tnode *node;
	t_tnode *tmp;
	t_tnode **current;

	node = ft_create_tnode(value);
	tmp = NULL;
	current = &tree->root;
	while (*current)
	{
		tmp = *current;
		if (tree->func_cmp(tmp->elem, node->elem) >= 0)
			current = &tmp->right;
		else
			current = &tmp->left;
	}
	*current = node;
	node->parent = tmp;
	ft_tnode_rebalance(node);
}

void	ft_rbtree_prefix(t_rbtr *tree, void (*func)(void *, void *), void *param)
{
	if (tree->root)
		ft_tnode_prefix(tree->root, func, param);
}

void	ft_rbtree_postfix(t_rbtr *tree, void (*func)(void *, void *), void *param)
{
	if (tree->root)
		ft_tnode_postfix(tree->root, func, param);
}

void	ft_rbtree_suffix(t_rbtr *tree, void (*func)(void *, void *), void *param)
{
	if (tree->root)
		ft_tnode_suffix(tree->root, func, param);
}
