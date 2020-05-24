
#include "collections_header.h"

void	ft_init_rbtree(t_rbtr *tree, t_bool (*is_place_right)(t_old_elem *, t_new_elem *), void (*func_del)(void *))
{
	if (tree)
	{
		tree->is_place_right = is_place_right;
		tree->func_del = func_del;
	}
}

t_rbtr	*ft_create_rbtree(t_bool (*is_place_right)(t_old_elem *, t_new_elem *), void (*func_del)(void *))
{
	t_rbtr	*tree;

	if (!is_place_right)
		return (NULL);
	tree = ft_memalloc(sizeof(t_rbtr));
	ft_init_rbtree(tree, is_place_right, func_del);
	return (tree);
}

void	ft_del_rbtree(t_rbtr **tree)
{
	if ((*tree)->func_del)
		ft_tnode_del_all((*tree)->root.left, (*tree)->func_del);
	ft_memdel((void **)tree);
}

void	ft_rbtree_insert(t_rbtr *tree, t_tnode *node)
{
	t_tnode *tmp;
	t_tnode **current;

	if (!tree || !node)
		return ;
	tmp = NULL;
	current = &tree->root.left;
	while (*current)
	{
		tmp = *current;
		if (tree->is_place_right(tmp->elem, node->elem) == TRUE)
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
	if (tree->root.left)
		ft_tnode_prefix(tree->root.left, func, param);
}

void	ft_rbtree_postfix(t_rbtr *tree, void (*func)(void *, void *), void *param)
{
	if (tree->root.left)
		ft_tnode_postfix(tree->root.left, func, param);
}

void	ft_rbtree_infix(t_rbtr *tree, void (*func)(void *, void *), void *param)
{
	if (tree->root.left)
		ft_tnode_infix(tree->root.left, func, param);
}
