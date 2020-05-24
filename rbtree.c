
#include "collections_header.h"

void	ft_init_rbtree(t_rbtr *tree, int (*func_cmp)(void *, void *), void (*func_del)(void *))
{
	if (tree)
	{
		tree->func_cmp = func_cmp;
		tree->func_del = func_del;
	}
}

t_rbtr	*ft_create_rbtree(int (*func_cmp)(void *, void *), void (*func_del)(void *))
{
	t_rbtr	*tree;

	if (!func_cmp)
		return (NULL);
	tree = ft_memalloc(sizeof(t_rbtr));
	ft_init_rbtree(tree, func_cmp, func_del);
	return (tree);
}

void	ft_rbtree_insert(t_rbtr *tree, t_tnode *node)
{
	t_tnode *tmp;
	t_tnode **current;

	if (!tree || !value)
		return ;
	tmp = NULL;
	current = &tree.root->left;
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
}

void	ft_rbtree_add(t_rbtr *tree, void *value)
{
	t_tnode *node;

	if (!tree || !value)
		return ;
	if (!(node = ft_create_tnode(value)))
		return ;
	ft_rbtree_insert(tree, node);
	ft_tnode_rebalance(node);
}

void	ft_rbtree_prefix(t_rbtr *tree, void (*func)(void *, void *), void *param)
{
	if (tree.root->left)
		ft_tnode_prefix(tree.root->left, func, param);
}

void	ft_rbtree_postfix(t_rbtr *tree, void (*func)(void *, void *), void *param)
{
	if (tree.root->left)
		ft_tnode_postfix(tree.root->left, func, param);
}

void	ft_rbtree_infix(t_rbtr *tree, void (*func)(void *, void *), void *param)
{
	if (tree.root->left)
		ft_tnode_infix(tree.root->left, func, param);
}
