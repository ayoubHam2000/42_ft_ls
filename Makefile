Main = \
	utils_ft_ls/free_content.c \
	utils_ft_ls/ft_ls.c \
	utils_ft_ls/list_directories.c \
	utils_ft_ls/list_reverse.c \
	utils_ft_ls/list_sort_name.c \
	utils_ft_ls/list_sort_time.c \
	utils_ft_ls/print_list.c \
	utils_ft_ls/recursive_listing.c \
	utils_ft_ls/set_config.c \
	linked_list_c/l_append_end.c \
	linked_list_c/l_clear.c \
	linked_list_c/l_create_node.c \
	linked_list_c/l_init.c \
	utils/ft_malloc.c \
	utils/ft_put_nbr.c \
	utils/ft_put_str.c \
	utils/ft_strdup.c \
	utils/ft_strlen.c \
	utils/ft_strncmp.c \
	utils/str_join.c \
	utils/ft_path_join.c \
	utils/set_permission.c \
	main.c

FILES = \
	$(Main)

#-Wall -Wextra -Werror -g
# -fsanitize=address

CFLAGS = -Wall -Wextra -Werror
INCLUDE = -I ./includes

DEPFLAGS = -MMD -MF $(@:.o=.d)

NAME = ft_ls.out

OBJ_DIR = _OUT/

OBJ = $(addprefix $(OBJ_DIR), $(FILES:.c=.o))

deps = $(OBJ:.o=.d)

all : $(NAME)

$(NAME) : $(OBJ)
	gcc $(OBJ) -o $(NAME) 
#-fsanitize=address

$(OBJ) : $(OBJ_DIR)%.o : %.c
	mkdir -p $(dir $@)
	gcc $(CFLAGS) $(INCLUDE) -c $< $(DEPFLAGS) -o $@

-include $(deps)

clean :
	rm -rf $(OBJ_DIR)

fclean : clean
	rm -f $(NAME)

re : fclean all
