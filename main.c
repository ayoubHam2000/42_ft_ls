/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 10:15:05 by aben-ham          #+#    #+#             */
/*   Updated: 2024/09/04 13:37:25 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>
#include <linked_list.h>
#include <string.h>
#include <unistd.h>

int	main(int ac, char **av)
{
	t_list		*paths;
	t_config	config;

	paths = l_init();
	set_config(paths, &config, ac, av);
	ft_ls(paths, &config);
	l_clear(paths, NULL);
	free(paths);
	return (0);
}
