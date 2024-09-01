/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_append_index.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 11:36:15 by aben-ham          #+#    #+#             */
/*   Updated: 2022/02/14 14:29:07 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

static int	l_check(t_list *list, long *index)
{
	if (!list)
		return (0);
	if (*index < 0)
		*index = (list->len) + *index + 1;
	if (*index < 0 || *index > (list->len))
		return (0);
	return (1);
}

int	l_append_index(t_list *list, long index, void *p)
{
	t_node	*node_prev;
	t_node	*new_node;

	if (!l_check(list, &index))
		return (0);
	if (!index)
	{
		new_node = l_create_node(p);
		if (!new_node)
			return (0);
		l_append_after(list, NULL, new_node);
		return (1);
	}
	node_prev = l_get(list, index - 1);
	if (node_prev)
	{
		new_node = l_create_node(p);
		if (!new_node)
			return (0);
		l_append_after(list, node_prev, new_node);
		return (1);
	}
	return (0);
}
