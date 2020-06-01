#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssoraka <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/11 12:49:25 by ssoraka           #+#    #+#              #
#    Updated: 2019/03/11 20:57:23 by ssoraka          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME1 = list
NAME2 = arr
NAME3 = rbtree
NAME4 = hmap

C_FLAGS = -g

LIBFT = libft.a
LIBFT_HEADER = -I ./
OBJ = arr.c llist.c lnode.c rbtree.c tnode.c hmap.c ilist.c


all: thmap ttree tarr tlist


thmap:
	gcc -o $(NAME4) hmap_main_test.c $(OBJ) $(LIBFT) $(LIBFT_HEADER)
	./$(NAME4)

ttree:
	gcc -o $(NAME3) rbtree_main_test.c $(OBJ) $(LIBFT) $(LIBFT_HEADER)
	./$(NAME3)

tarr:
	gcc -o $(NAME2) arr_main_test.c $(OBJ) $(LIBFT) $(LIBFT_HEADER)
	./$(NAME2)

tlist:
	gcc -o $(NAME1) list_main_test.c $(OBJ) $(LIBFT) $(LIBFT_HEADER)
	./$(NAME1)

norm:
	norminette -R CheckForbiddenSourceHeader

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME1) $(NAME2) $(NAME3) $(NAME4)

re: fclean all
