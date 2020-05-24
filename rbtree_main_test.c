
#include "libft.h"
#include "collections_header.h"

void	ft_print(int i, int status)
{
	ft_putstr("test ");
	ft_putnbr(i);
	if (status == SUCCESS)
		ft_putstr(" SUCCESS\n");
	else
		ft_putstr(" FAIL\n");
}

t_bool	func_cmp(void *old, void *new)
{
	int *o;
	int *n;

	o = (int *)old;
	n = (int *)new;
	if (*n >= *o)
		return (TRUE);
	else
		return (FALSE);
}

void	ft_use_func_with_tree(int (*func)(t_rbtr *))
{
	static int num;
	t_rbtr *tree;

	tree = ft_create_rbtree(func_cmp, NULL);
	if (func)
		ft_print(num, func(tree));
	else
		ft_print(num, SUCCESS);

	ft_del_rbtree(&tree);
	if (tree)
		ft_putstr("error\n");
	num++;
}


int		main(int argc, char **argv)
{
	ft_putstr("start\n");

	ft_use_func_with_tree(NULL);


	ft_putstr("end\n");
	return (0);
}
