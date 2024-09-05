/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_directories.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 21:45:54 by aben-ham          #+#    #+#             */
/*   Updated: 2024/09/05 18:40:42 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>
#include <linked_list.h>

static void	get_info(t_info *info, const char *file_name, \
	const char *file_path, t_config *config)
{
	info->res = 1;
	if (config->show_hidden == 0 && file_name[0] == '.')
		return ;
	if (lstat(file_path, &(info->file_stat)) == -1)
	{
		ft_put_str(2, "Could not stat: ");
		ft_put_str(2, file_path);
		ft_put_str(2, "\n");
		return ;
	}
	info->pw = getpwuid(info->file_stat.st_uid);
	if (info->pw == NULL)
	{
		perror("pwuid");
		return ;
	}
	info->gr = getgrgid(info->file_stat.st_gid);
	if (info->gr == NULL)
	{
		perror("grgid");
		return ;
	}
	info->res = 0;
}

static char	*get_linked_file(const char *file_path, mode_t mode)
{
	char	*linked_file;
	ssize_t	len;

	linked_file = NULL;
	if (S_ISLNK(mode))
	{
		linked_file = ft_malloc(LINKED_FILE_SIZE);
		len = readlink(file_path, linked_file, LINKED_FILE_SIZE);
		if (len != -1)
			linked_file[len] = 0;
		else
			perror("readlink");
	}
	return (linked_file);
}

static void	add_content(t_list *res, struct dirent *de, \
	char *path, t_config *config)
{
	t_content	*content;
	char		*file_path;
	t_info		info;

	file_path = ft_path_join(path, de->d_name);
	get_info(&info, de->d_name, file_path, config);
	if (info.res == 1)
	{
		free(file_path);
		return ;
	}
	content = ft_malloc(sizeof(t_content));
	content->name = ft_strdup(de->d_name);
	content->st_size = info.file_stat.st_size;
	content->st_nlink = info.file_stat.st_nlink;
	content->pw_name = ft_strdup(info.pw->pw_name);
	content->gr_name = ft_strdup(info.gr->gr_name);
	content->m_time = info.file_stat.st_mtime;
	content->st_mode = info.file_stat.st_mode;
	content->linked_file = get_linked_file(file_path, info.file_stat.st_mode);
	res->nb_blocks += info.file_stat.st_blocks;
	l_append_end(res, content);
	free(file_path);
}

char	*get_file_name(char *name)
{
	size_t	i;

	i = ft_strlen(name);
	while (i > 0)
	{
		i--;
		if (name[i] == '/')
			return (name + i + 1);
	}
	return (name);
}

static void	add_file_content(t_list *res, char *path, t_config *config)
{
	t_content	*content;
	t_info		info;
	char			*file_name;

	file_name = get_file_name(path);
	get_info(&info, file_name, path, config);
	if (info.res == 1)
	{
		return ;
	}
	content = ft_malloc(sizeof(t_content));
	content->name = ft_strdup(file_name);
	content->st_size = info.file_stat.st_size;
	content->st_nlink = info.file_stat.st_nlink;
	content->pw_name = ft_strdup(info.pw->pw_name);
	content->gr_name = ft_strdup(info.gr->gr_name);
	content->m_time = info.file_stat.st_mtime;
	content->st_mode = info.file_stat.st_mode;
	content->linked_file = get_linked_file(path, info.file_stat.st_mode);
	res->nb_blocks += info.file_stat.st_blocks;
	l_append_end(res, content);
}

static void	sort_list(t_list *res, t_config *config)
{
	list_sort_name(res);
	if (config->sort_time == 1)
		list_sort_time(res);
	if (config->reverse == 1)
		list_reverse(res);
}

t_list	*list_directory(char *path, t_config *config)
{
	t_list			*res;
	DIR				*dr;
	struct dirent	*de;

	dr = opendir(path);
	res = l_init();
	if (dr == NULL)
	{
		add_file_content(res, path, config);
		// ft_put_str(2, "Could not open directory: ");
		// ft_put_str(2, path);
		// ft_put_str(2, "\n");
		// return (NULL);
	}
	else
	{
		de = readdir(dr);
		while (de != NULL)
		{
			add_content(res, de, path, config);
			de = readdir(dr);
		}
		sort_list(res, config);
		closedir(dr);
	}
	return (res);
}
