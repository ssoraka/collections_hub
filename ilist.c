
#include "libft.h"
#include "collections_header.h"

void	ft_ilist_set_add(t_ilist *ilist, int (*add)(void *, void *, void *))
{
	ilist->add = add;
}

void	ft_ilist_set_get(t_ilist *ilist, void *(*find)(void *, void *))
{
	ilist->find = find;
}

void	ft_ilist_set_del(t_ilist *ilist, void (*del)(void *))
{
	ilist->del = del;
}

void	ft_ilist_set_list(t_ilist *ilist, void *list, int elem_size)
{
	ft_memcpy((void *)ilist->mem, list, elem_size);
	ilist->size = elem_size;
}
