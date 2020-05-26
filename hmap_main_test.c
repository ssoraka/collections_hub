
#include "libft.h"
#include "collections_header.h"


int func_cmp(void *old, void *new)
{
	return (TRUE);
}

void func_del(void *key, void *value)
{
}


int add(void *list, void *key, void *value)
{
	return (TRUE);
}

void *find(void *list, void *key)
{
	return (NULL);
}

void del(void *list)
{
}

int func_hash(void *key)
{
	return (1);
}

t_hmap	*ft_create_hmap()
{
	t_rbtr *tree;
	t_ilist list;
	t_hmap *hmap;

	tree = (t_rbtr *)((void *)list.mem);
	ft_bzero((void *)tree, sizeof(t_rbtr));
	ft_init_rbtree(tree, func_cmp, func_del);
	ft_ilist_set_add(&list, add);
	ft_ilist_set_get(&list, find);
	ft_ilist_set_del(&list, del);
	ft_ilist_set_list(&list, (void *)tree, sizeof(t_rbtr));
	hmap = ft_create_hashmap(func_hash, &list);
	return(hmap);
}


void	ft_print(int i, int status)
{
	ft_putstr("test ");
	ft_putnbr(i);
	if (status == SUCCESS)
		ft_putstr(" SUCCESS\n");
	else
		ft_putstr(" FAIL\n");
}


void	ft_use_func_with_tree(int (*func)(t_hmap *))
{
	static int num;
	t_hmap *hmap;

	hmap = ft_create_hmap();
	if (func)
		ft_print(num, func(hmap));
	else
		ft_print(num, SUCCESS);

	ft_del_hmap(&hmap);
	if (hmap)
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
