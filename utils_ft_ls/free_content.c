/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_content.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 10:45:51 by aben-ham          #+#    #+#             */
/*   Updated: 2024/09/04 10:46:09 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	free_content(void *p)
{
	t_content	*content;

	content = p;
	free(content->name);
	free(content->pw_name);
	free(content->gr_name);
	free(content->linked_file);
	free(content);
}
