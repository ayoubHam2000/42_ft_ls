/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_clear.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 23:30:23 by aben-ham          #+#    #+#             */
/*   Updated: 2022/02/15 14:10:52 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

static void	l_default_del_ptr(void	*p)
{
	free(p);
}

void	l_clear(t_list *list, void (*del_ptr)(void *p))
{
	t_node	*node;
	t_node	*target;

	if (!list)
		return ;
	if (!del_ptr)
		del_ptr = l_default_del_ptr;
	node = list->head;
	while (node)
	{
		target = node;
		node = node->next;
		del_ptr(target->p);
		free(target);
	}
	list->head = NULL;
	list->last = NULL;
	list->len = 0;
}
