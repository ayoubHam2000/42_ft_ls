/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_get.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 20:46:00 by aben-ham          #+#    #+#             */
/*   Updated: 2022/02/14 13:51:28 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

static int	l_check(t_list *list, long *index)
{
	if (!list || !(list->len))
		return (0);
	if (*index < 0)
		*index = (list->len) + *index;
	if (*index < 0 || *index >= (list->len))
		return (0);
	return (1);
}

t_node	*l_get(t_list *list, long pos)
{
	t_node	*node;

	if (!l_check(list, &pos))
		return (NULL);
	if (pos == (list->len) - 1)
		return (list->last);
	node = list->head;
	while (node && pos > 0)
	{
		node = node->next;
		pos--;
	}
	return (node);
}
