/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 21:39:28 by aben-ham          #+#    #+#             */
/*   Updated: 2024/09/04 10:48:50 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <unistd.h>
# include <pwd.h>
# include <dirent.h>
# include <sys/types.h>
# include <grp.h>
# include <time.h>
# include <errno.h>
# include <sys/time.h>
# include <linked_list.h>
# include <utils.h>

# define LINKED_FILE_SIZE 1024

typedef struct s_config
{
	int	list;
	int	show_hidden;
	int	reverse;
	int	sort_time;
	int	recursive;
}	t_config;

typedef struct s_content
{
	time_t	m_time;
	char	*name;
	size_t	st_size;
	int		st_nlink;
	mode_t	st_mode;
	char	*pw_name;
	char	*gr_name;
	char	*linked_file;
}	t_content;

typedef struct s_info
{
	int				res;
	struct passwd	*pw;
	struct group	*gr;
	struct stat		file_stat;
}	t_info;

void	ft_ls(t_list *paths, t_config *config);
t_list	*list_directory(char *path, t_config *config);
void	set_config(t_list *paths, t_config *config, int ac, char **av);
void	recursive_listing(const char *path, t_config *config);
void	print_list(t_list *list, t_config *config);
void	list_sort_time(t_list *list);
void	list_sort_name(t_list *list);
void	list_reverse(t_list *list);
char	set_permission(int val, char c);
void	free_content(void *p);

#endif
