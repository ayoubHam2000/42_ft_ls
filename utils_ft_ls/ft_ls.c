/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 21:45:52 by aben-ham          #+#    #+#             */
/*   Updated: 2024/09/05 18:49:44 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>
#include <linked_list.h>

void	ft_ls(t_list *paths, t_config *config)
{
	char	*path;
	t_node	*node;
	t_list	*list_dir;
	int			is_file;

	node = paths->head;
	while (node != NULL)
	{
		path = (char *)(node->p);
		DIR *dir = opendir(path);
		is_file = 0;
		if (dir == NULL)
			is_file = 1;
		closedir(dir);
		if ((config->recursive == 1 || paths->len > 1) && is_file == 0)
		{
			ft_put_str(1, path);
			ft_put_str(1, ":\n");
		}
		list_dir = list_directory(path, config);
		if (list_dir != NULL)
			print_list(list_dir, config, is_file);
		l_clear(list_dir, free_content);
		free(list_dir);
		if (config->recursive == 1 && is_file == 0)
			recursive_listing(path, config);
		if (node->next != NULL)
			ft_put_str(1, "\n");
		node = node->next;
	}
}
