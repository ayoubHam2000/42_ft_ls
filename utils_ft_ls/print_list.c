/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 21:46:03 by aben-ham          #+#    #+#             */
/*   Updated: 2024/09/04 11:08:46 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>
#include <linked_list.h>

static void	print_permissions(mode_t mode)
{
	char	permissions[12];

	permissions[0] = get_file_type(mode);
	permissions[1] = set_permission((mode & S_IRUSR), 'r');
	permissions[2] = set_permission((mode & S_IWUSR), 'w');
	permissions[3] = set_permission((mode & S_IXUSR), 'x');
	permissions[4] = set_permission((mode & S_IRGRP), 'r');
	permissions[5] = set_permission((mode & S_IWGRP), 'w');
	permissions[6] = set_permission((mode & S_IXGRP), 'x');
	permissions[7] = set_permission((mode & S_IROTH), 'r');
	permissions[8] = set_permission((mode & S_IWOTH), 'w');
	permissions[9] = set_permission((mode & S_IXOTH), 'x');
	permissions[10] = 0;
	ft_put_str(1, permissions);
	ft_put_str(1, " ");
}

static void	print_info(t_content *content)
{
	char	*formatted_time;

	print_permissions(content->st_mode);
	ft_put_nbr_buffer(1, content->st_nlink, 2);
	ft_put_str(1, " ");
	ft_put_str(1, content->pw_name);
	ft_put_str(1, " ");
	ft_put_str(1, content->gr_name);
	ft_put_str(1, " ");
	ft_put_nbr_buffer(1, content->st_size, 10);
	ft_put_str(1, " ");
	formatted_time = ctime(&(content->m_time));
	formatted_time[10] = 0;
	formatted_time[16] = 0;
	ft_put_str_buffer(1, formatted_time + 4, 7);
	ft_put_str(1, " ");
	ft_put_str_buffer(1, formatted_time + 11, 5);
	ft_put_str(1, " ");
	ft_put_str(1, content->name);
	if (content->linked_file)
	{
		ft_put_str(1, " -> ");
		ft_put_str(1, content->linked_file);
	}
	ft_put_str(1, "\n");
}

static void	print_name(t_node *node, t_content *content)
{
	ft_put_str(1, content->name);
	if (node->next != NULL)
		ft_put_str(1, " ");
	else
		ft_put_str(1, "\n");
}

static void	print_node(t_node *node, t_config *config)
{
	t_content	*content;

	content = (t_content *)(node->p);
	if (config->show_hidden != 0 || content->name[0] != '.')
	{
		if (config->list == 1)
			print_info(content);
		else
			print_name(node, content);
	}
}

void	print_list(t_list *list, t_config *config)
{
	t_node	*node;

	if (config->list == 1)
	{
		ft_put_str(1, "total: ");
		ft_put_nbr(1, list->nb_blocks / 2);
		ft_put_str(1, "\n");
	}
	node = list->head;
	while (node != NULL)
	{
		print_node(node, config);
		node = node->next;
	}
}
