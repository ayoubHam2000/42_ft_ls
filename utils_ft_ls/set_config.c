/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_config.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 21:46:09 by aben-ham          #+#    #+#             */
/*   Updated: 2024/09/05 18:42:56 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>
#include <linked_list.h>

static void	set_option(t_config *config, char *arg)
{
	int	j;

	j = 1;
	while (arg[j] != 0)
	{
		if (arg[j] == 'l')
			config->list = 1;
		else if (arg[j] == 'a')
			config->show_hidden = 1;
		else if (arg[j] == 'r')
			config->reverse = 1;
		else if (arg[j] == 't')
			config->sort_time = 1;
		else if (arg[j] == 'R')
			config->recursive = 1;
		else
		{
			ft_put_str(2, "ls: invalid option -- ");
			write(2, &(arg[j]), 1);
			ft_put_str(2, "\n");
			exit(1);
		}
		j++;
	}
}

static void	add_folder(t_list *paths, char *arg)
{
	//DIR	*dir;

	if (access(arg, F_OK) == 0)
	{
		l_append_end(paths, ft_strdup(arg));
	}
	else
	{
		ft_put_str(2, "ls: No such file or directory ");
		ft_put_str(2, arg);
		ft_put_str(2, "\n");
	}
}

static void	set_directories(int ac, char **av, t_list *paths)
{
	int	i;
	int	f;

	i = 1;
	f = 0;
	while (i < ac)
	{
		if (av[i][0] != '-')
		{
			add_folder(paths, av[i]);
			f = 1;
		}
		i++;
	}
	if (paths->len == 0 && f == 0)
		l_append_end(paths, ft_strdup("."));
}

void	set_config(t_list *paths, t_config *config, int ac, char **av)
{
	int	i;

	config->list = 0;
	config->show_hidden = 0;
	config->reverse = 0;
	config->sort_time = 0;
	config->recursive = 0;
	i = 1;
	while (i < ac)
	{
		if (av[i][0] == '-')
			set_option(config, av[i]);
		i++;
	}
	set_directories(ac, av, paths);
}
