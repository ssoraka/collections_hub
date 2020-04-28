
#include "libft.h"
#include "collections_header.h"


t_arr *ft_create_arr_of_elems(void *value, int elem_size, int elems_count, void (*func_del)(void *))
{
	t_arr *arr;

	arr = ft_create_arr(elem_size, elems_count, func_del);
	if (!arr)
		return (NULL);
	ft_all_arr_init_by_value(arr, value);
	return (arr);
}

int		ft_arr_hash_add(t_arr *arr, void *value, int hash)
{
	t_llist *list;
	int index;

	index = hash & (arr->elems_used ^ 1);
	list = ft_arr_get(arr, index);
	//add hash field in node if llist
	if (!ft_llist_hash_add(list, value, hash))
		return (FALSE);
	return (TRUE);
}

int		ft_increase_hmap(t_hmap *hmap)
{
	t_arr *arr;
	llist *list;
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
	hmap->max_load = arr->elems_used * HASHMAP_LOAD;
	return (TRUE);
}





int		ft_hashmap_put(t_hmap *hmap, void *value, void *key)
{
	t_llist *list;
	int index;
	int hash;

	if (hmap->elems_used > hmap->max_load)
		if (!ft_increase_hmap(hmap))
			return (FALSE);
	hash = hmap->func_hash(key);
	ft_arr_hash_add(hmap->arr, value, hash);
	if (list->elems_count == 1)
		hmap->elems_used++;
	return (TRUE);
}

void	ft_del_hmap(t_hmap **hmap)
{
	ft_del_arr(&((*hmap)->arr));
	ft_memdel((void **)hmap);
}

t_hmap	*ft_create_hashmap(int (*func_hash)(void *))
{
	t_hmap	*hmap;

	if (!func_hash)
		return (NULL);
	hmap = ft_memalloc(sizeof(t_hmap));
	if (!hmap)
		return (NULL);
	ft_llist_init(&(hmap->list));
	hmap->max_load = HASHMAP_FIRST_COUNT * HASHMAP_LOAD;
	hmap->arr = ft_create_arr_of_elems((void *)&hmap->list, sizeof(t_llist), HASHMAP_FIRST_COUNT, NULL);
	if (!hmap->arr)
		ft_memdel((void **)&hmap);
	return (hmap);
}



int		main(int argc, char **argv)
{
	printf("Hello World\n");
	return (0);
}
