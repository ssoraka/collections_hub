

#ifndef FT_COLLECTIONS_HEADER_H
# define FT_COLLECTIONS_HEADER_H
# define HASHMAP_REALLOC_COEF 2.0
# define HASHMAP_FIRST_COUNT 16
# define HASHMAP_LOAD 0.75

typedef void t_new_elem;
typedef void t_old_elem;
typedef void t_new_key;
typedef void t_old_key;
typedef int t_bool;

#include "libft.h"
#include "collections_struct.h"


t_lnode	*ft_create_lnode(void *value);
void	ft_insert_lnode(t_lnode *node, t_lnode *before);
void	*ft_cut_lnode(t_lnode *node);
void	ft_del_lnode(t_lnode **node, void (*func_del)(void *));
t_lnode *ft_lnode_get(int num, int count, t_lnode *start, t_lnode *end);


t_llist	*ft_create_llist(void (*func_del)(void *));
void	ft_init_llist(t_llist	*llist, void (*func_del)(void *));
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
int		ft_init_arr(t_arr *arr, int elem_size, int elems_count, void (*func_del)(void *));
t_arr	*ft_create_arr(int elem_size, int elems_count, void (*func_del)(void *));
t_arr	*ft_create_arr_of_ptr(int elems_count, void (*func_del)(void *));
int		ft_realloc_arr(t_arr *arr, int new_count);
void	*ft_arr_add(t_arr *arr, void *elem);
void	*ft_arr_get(t_arr *arr, int num);
void	*ft_arr_get_next(t_arr *arr);
void	ft_del_elem(t_arr *arr, int num);
void	ft_del_elems_if(t_arr *arr, int (*need_del)(void *, void *), void *param);
void	ft_for_each_elem(t_arr *arr, void (*func)(void *, void *), void *param);
int		ft_arr_init_by_value(t_arr *arr, int count, void *value);
void	ft_all_arr_init_by_value(t_arr *arr, void *value);

t_rbtr	*ft_create_rbtree(int (*func_cmp)(t_old_key *, t_new_key *), void (*func_del)(t_old_key *, t_old_elem *));
void	ft_init_rbtree(t_rbtr *tree, int (*func_cmp)(t_old_key *, t_new_key *), void (*func_del)(t_old_key *, t_old_elem *));
void	ft_del_rbtree(t_rbtr **tree);
void	ft_del_rbtree_nodes(t_rbtr *tree);
void	ft_rbtree_insert(t_rbtr *tree, t_tnode *node);
t_bool	ft_rbtree_add(t_rbtr *tree, void *key, void *value);
void	*ft_rbtree_get_next(t_rbtr *tree);
void	*ft_rbtree_get_elem(t_rbtr *tree, void *key);
void	ft_rbtree_prefix(t_rbtr *tree, void (*func)(t_old_elem *, void *), void *param);
void	ft_rbtree_postfix(t_rbtr *tree, void (*func)(t_old_elem *, void *), void *param);
void	ft_rbtree_suffix(t_rbtr *tree, void (*func)(t_old_elem *, void *), void *param);

t_tnode *ft_create_tnode(void *key, void *value);
t_tnode	*ft_find_left_value(t_tnode *node);
void	ft_tnode_rebalance(t_tnode *node);
void	ft_tnode_prefix(t_tnode *node, void (*func)(void *, void *), void *param);
void	ft_tnode_postfix(t_tnode *node, void (*func)(void *, void *), void *param);
void	ft_tnode_infix(t_tnode *node, void (*func)(void *, void *), void *param);
void	ft_tnode_del(t_tnode *node, void (*func)(void *, void *));
void	ft_tnode_del_all(t_tnode *node, void (*func)(void *, void *));

void	ft_ilist_set_add(t_ilist *ilist, int (*add)(void *, void *, void *));
void	ft_ilist_set_get(t_ilist *ilist, void *(*find)(void *, void *));
void	ft_ilist_set_del(t_ilist *ilist, void (*del)(void *));
void	ft_ilist_set_list(t_ilist *ilist, void *list, int elem_size);
void	ft_ilist_set_get_next(t_ilist *list, int (*get_next)(void *, void **, void **));
void	ft_ilist_set_func_for_resize_map(t_ilist *list, void (*del_list_without_key_value)(void *));

t_hmap	*ft_create_hashmap(int (*func_hash)(void *), t_ilist *list);
int		ft_hashmap_put(t_hmap *hmap, void *key, void *value);
void	*ft_hashmap_get(t_hmap *hmap, void *key);
void	ft_del_hmap(t_hmap **hmap);
#endif
