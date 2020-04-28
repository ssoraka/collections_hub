

#ifndef FT_COLLECTIONS_HEADER_H
# define FT_COLLECTIONS_HEADER_H
# define HASHMAP_REALLOC_COEF 2.0
# define HASHMAP_FIRST_COUNT 16
# define HASHMAP_LOAD 0.75
#include "libft.h"
#include "collections_struct.h"


t_lnode	*ft_create_lnode(void *value);
void	ft_insert_lnode(t_lnode *node, t_lnode *before);
void	*ft_cut_lnode(t_lnode *node);
void	ft_del_lnode(t_lnode **node, void (*func_del)(void *));
t_lnode *ft_lnode_get(int num, int count, t_lnode *start, t_lnode *end);


t_llist	*ft_create_llist(void (*func_del)(void *));
void	*ft_llist_get_next(t_llist *list);
int		ft_llist_dpush(t_llist *list, void *elem);
int		ft_llist_push(t_llist *list, void *elem);
void	*ft_llist_pop(t_llist *list);
void	*ft_llist_dpop(t_llist *list);
int		ft_llist_add(t_llist *list, void *elem);
void	ft_for_each_llist(t_llist *list, void (*func)(void *, void *), void *param);
void	*ft_llist_get(t_llist *list, int num);
void	ft_del_llist_elem(t_llist *list, int num);
int		ft_insert_llist(t_llist *list, void *elem, int num);
void	ft_del_llist(t_llist **list);


void	*ft_return_elem(void *elem);
void	*ft_return_ptr(void *elem);
void	ft_del_arr(t_arr **arr);
t_arr	*ft_create_arr(int elem_size, int elems_count, void (*func_del)(void *));
t_arr	*ft_create_arr_of_ptr(int elems_count, void (*func_del)(void *));
int		ft_realloc_arr(t_arr *arr, int new_count);
void	*ft_arr_add(t_arr *arr, void *elem);
void	*ft_arr_get(t_arr *arr, int num);
void	*ft_arr_get_next(t_arr *arr);
void	ft_del_elem(t_arr *arr, int num);
void	ft_del_elems_if(t_arr *arr, int (*need_del)(void *, void *), void *param);
void	ft_for_each_elem(t_arr *arr, void (*func)(void *, void *), void *param);
void	ft_arr_init_by_value(t_arr *arr, int count, void *value);
void	ft_all_arr_init_by_value(t_arr *arr, void *value);


#endif
