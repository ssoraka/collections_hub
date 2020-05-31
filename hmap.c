
#include "libft.h"
#include "collections_header.h"


t_arr *ft_create_arr_of_elems(void *value, int elem_size, int elems_count, void (*func_del)(void *))
{
	t_arr *arr;

	arr = ft_create_arr(elem_size, elems_count, func_del);
	if (!arr)
		return (NULL);
	ft_all_arr_init_by_value(arr, value);
	arr->elems_used = arr->elems_count;
	return (arr);
}


int		ft_increase_hmap(t_hmap *hmap)
{
	t_arr *arr;
/*	t_list *list;
	t_node	*elem;

	arr = ft_create_arr_of_elems((void *)&hmap->list, sizeof(t_llist), hmap->arr.elems_used << 1, hmap->arr.func_del);
	if (!arr)
		return (FALSE);
	while ((list = ft_arr_get_next(hmap->arr))
		while ((elem = ft_llist_get_next_node(llist)))
			if (!ft_arr_hash_add(hmap->arr, elem->value, elem->hash))
			{
				ft_del_arr(&arr);
				return (FALSE);
			}
	ft_del_arr(&(hmap->arr));
	hmap->arr = arr;
	hmap->max_load = arr->elems_used * HASHMAP_LOAD;*/
	return (TRUE);
}



int		ft_hashmap_put(t_hmap *hmap, void *key, void *value)
{
	int index;
	void *list;

//	if (hmap->elems_used > hmap->max_load)
//		if (!ft_increase_hmap(hmap))
//			return (FALSE);
	index = hmap->func_hash(key) & (hmap->arr->elem_size - 1);
	list = ft_arr_get(hmap->arr, index);
	if (!(hmap->list.add(list, key, value)))
		return (FALSE);
	hmap->elems_used++;
	return (TRUE);
}

void	*ft_hashmap_get(t_hmap *hmap, void *key)
{
	int index;
	void *list;

	index = hmap->func_hash(key) & (hmap->arr->elem_size - 1);
	list = ft_arr_get(hmap->arr, index);
	return (hmap->list.find(list, key));
}

void	ft_del_hmap(t_hmap **hmap)
{
	ft_del_arr(&((*hmap)->arr));
	ft_memdel((void **)hmap);
}

t_hmap	*ft_create_hashmap(int (*func_hash)(void *), t_ilist *list)
{
	t_hmap	*hmap;

	if (!func_hash || !list)
		return (NULL);
	if (!(hmap = ft_memalloc(sizeof(t_hmap))))
		return (NULL);
	hmap->func_hash = func_hash;
	ft_memcpy((void *)&hmap->list, (void *)list, sizeof(t_ilist));
	hmap->max_load = HASHMAP_FIRST_COUNT * HASHMAP_LOAD;
	hmap->arr = ft_create_arr_of_elems((void *)hmap->list.mem, hmap->list.size, HASHMAP_FIRST_COUNT, hmap->list.del);
	if (!hmap->arr)
		ft_memdel((void **)&hmap);
	return (hmap);
}
