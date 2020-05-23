
#include "collections_header.h"

t_tnode *ft_create_tnode(void *value)
{
	t_tnode *node;

	node = ft_memalloc(sizeof(t_tnode));
	if (node)
	{
		node->elem = value;
		node->color = RED;
	}
	return (node);
}

void	ft_tnode_rebalance(t_tnode *node)
{
	if (!node)
		return ;
	else if (!node->parent)
		node->color = BLACK;
	else if (node->color == RED && node->parent->color = RED)
	{
		;
	}
}

void	ft_tnode_left_rotate(t_tnode *node)
{

}

void	ft_tnode_right_rotate(t_tnode *node)
{

}

void	ft_tnode_prefix(t_tnode *node, void (*func)(void *, void *), void *param)
{
	if (node->left)
		ft_tnode_suffix(node->left, func, param);
	func(node->elem, param);
	if (node->right)
		ft_tnode_suffix(node->right, func, param);
}

void	ft_tnode_postfix(t_tnode *node, void (*func)(void *, void *), void *param)
{
	if (node->right)
		ft_tnode_postfix(node->right, func, param);
	func(node->elem, param);
	if (node->left)
		ft_tnode_postfix(node->left, func, param);
}

void	ft_tnode_suffix(t_tnode *node, void (*func)(void *, void *), void *param)
{
	func(node->elem, param);
	if (node->left)
		ft_tnode_suffix(node->left, func, param);
	if (node->right)
		ft_tnode_suffix(node->right, func, param);
}
