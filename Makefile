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

LIB = libcol.a
NAME1 = test/list
NAME2 = test/arr
NAME3 = test/rbtree
NAME4 = test/hmap

C_FLAGS = -g

HEADER = .

LIBFT = libft.a
LIBFT_HEADER = -I ./
OBJ = arr.c llist.c lnode.c rbtree.c tnode.c hmap.c ilist.c


$(LIB): $(OBJ)
	@ar rc $(LIB) $(OBJ)
	ranlib $(LIB)

%.o: %.c
	@$(CC) $(CFLAGS) $< -o $@ -I $(HEADER)

test: thmap ttree tarr tlist

thmap:
	gcc -o $(NAME4) ./test/hmap_main_test.c $(OBJ) $(LIBFT) $(LIBFT_HEADER)
	./$(NAME4)

ttree:
	gcc -o $(NAME3) ./test/rbtree_main_test.c $(OBJ) $(LIBFT) $(LIBFT_HEADER)
	./$(NAME3)

tarr:
	gcc -o $(NAME2) ./test/arr_main_test.c $(OBJ) $(LIBFT) $(LIBFT_HEADER)
	./$(NAME2)

tlist:
	gcc -o $(NAME1) ./test/list_main_test.c $(OBJ) $(LIBFT) $(LIBFT_HEADER)
	./$(NAME1)

norm:
	norminette -R CheckForbiddenSourceHeader

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(LIB) $(NAME1) $(NAME2) $(NAME3) $(NAME4)

re: fclean all
