# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/14 13:18:13 by aben-ham          #+#    #+#              #
#    Updated: 2022/02/15 14:09:41 by aben-ham         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES = \
		l_append_after.c \
		l_append_end.c \
		l_append_front.c \
		l_append_index.c \
		l_clone.c \
		l_create_node.c \
		l_clear.c \
		l_del_by_index.c \
		l_del_by_prev.c \
		l_del_cond.c \
		l_get.c \
		l_init.c \
		main.c


CFLAGS =  -g -Wall -Wextra -Werror -I .
DEPFLAGS = -MMD -MF $(@:.o=.d)

NAME = linked_list

OBJ_DIR = OUT/

OBJ = $(addprefix $(OBJ_DIR), $(FILES:.c=.o))

deps = $(OBJ:.o=.d)

all : $(NAME)

$(NAME) : $(OBJ)
	gcc $(OBJ) -o $(NAME)

$(OBJ) : $(OBJ_DIR)%.o : %.c
	mkdir -p $(dir $@)
	gcc $(CFLAGS) -c $(@:OUT/%.o=%.c) $(DEPFLAGS) -o $@

-include $(deps)

##################

clean :
	rm -rf $(OBJ_DIR)

fclean : clean
	rm -f $(NAME)

re : fclean all
