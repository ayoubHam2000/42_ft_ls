/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive_listing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 21:46:06 by aben-ham          #+#    #+#             */
/*   Updated: 2024/09/04 10:45:33 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>
#include <linked_list.h>

void	recursive_listing(const char *path, t_config *config);

static void	print(const char *path, struct dirent *entry, t_config *config)
{
	t_list		*list_dir;
	char		*file_path;

	file_path = ft_path_join(path, entry->d_name);
	if (entry->d_type == DT_DIR && ft_strncmp(entry->d_name, ".", 1) != 0 \
		&& ft_strncmp(entry->d_name, "..", 2) != 0)
	{
		if (config->show_hidden != 0 || entry->d_name[0] != '.')
		{
			list_dir = list_directory(file_path, config);
			if (list_dir != NULL)
			{
				ft_put_str(1, "\n");
				ft_put_str(1, file_path);
				ft_put_str(1, ":\n");
				print_list(list_dir, config);
				l_clear(list_dir, free_content);
				free(list_dir);
				recursive_listing(file_path, config);
			}
		}
	}
	free(file_path);
}

void	recursive_listing(const char *path, t_config *config)
{
	struct dirent			*entry;
	DIR						*dir;

	dir = opendir(path);
	if (dir == NULL)
	{
		ft_put_str(2, "Can't open\n");
		ft_put_str(2, path);
		ft_put_str(2, "\n");
	}
	else
	{
		entry = readdir(dir);
		while (entry)
		{
			print(path, entry, config);
			entry = readdir(dir);
		}
		closedir(dir);
	}
}
