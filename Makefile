Main = \
	linked_list_c/l_append_after.c \
	linked_list_c/l_append_end.c \
	linked_list_c/l_append_front.c \
	linked_list_c/l_append_index.c \
	linked_list_c/l_clone.c \
	linked_list_c/l_create_node.c \
	linked_list_c/l_clear.c \
	linked_list_c/l_del_by_index.c \
	linked_list_c/l_del_by_prev.c \
	linked_list_c/l_del_cond.c \
	linked_list_c/l_get.c \
	linked_list_c/l_init.c \
	utils/ft_strdup.c \
	main.c


FILES = \
	$(Main)



#-Wall -Wextra -Werror -g
# -fsanitize=address

CFLAGS = -Wall -Wextra # -Werror
INCLUDE = -I ./includes

DEPFLAGS = -MMD -MF $(@:.o=.d)

NAME = ft_ls.out

OBJ_DIR = _OUT/

OBJ = $(addprefix $(OBJ_DIR), $(FILES:.c=.o))

deps = $(OBJ:.o=.d)

all : $(NAME)

$(NAME) : $(OBJ)
	gcc $(OBJ) -o $(NAME)

$(OBJ) : $(OBJ_DIR)%.o : %.c
	mkdir -p $(dir $@)
	gcc $(CFLAGS) $(INCLUDE) -c $< $(DEPFLAGS) -o $@

-include $(deps)

clean :
	rm -rf $(OBJ_DIR)

fclean : clean
	rm -f $(NAME)

re : fclean all