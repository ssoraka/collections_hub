
#ifndef FT_COLLECTIONS_STRUCT_H
# define FT_COLLECTIONS_STRUCT_H
#include "collections_header.h"

typedef struct		s_arr
{
	void			*elems;
	void			*current;
	size_t			next;
	size_t			elems_count;
	size_t			elems_used;
	int				elem_size;
	void			(*func_del)(void *);
	void			*(*value)(void *);
}					t_arr;


typedef struct		s_lnode
{
	void			*elem;
	struct s_lnode	*next;
	struct s_lnode	*prev;
}					t_lnode;

typedef struct		s_llist
{
	struct s_lnode	start;
	struct s_lnode	end;
	struct s_lnode	*current;
	size_t			elems_count;
	void			(*func_del)(void *);
}					t_llist;

typedef struct		s_hmap
{
	struct s_llist	list;
	struct s_arr	*arr;
	int				(*func_hash)(void *);
	int				elems_count;
	int				elems_used;
	int				max_load;
}					t_hmap;

#endif
