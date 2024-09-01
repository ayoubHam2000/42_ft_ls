/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_del_by_prev.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 23:45:42 by aben-ham          #+#    #+#             */
/*   Updated: 2022/02/15 13:51:32 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

static void	l_default_del_ptr(void	*p)
{
	free(p);
}

void	l_del_by_prev(t_list *list, t_node *prev, void (*del_ptr)(void *p))
{
	t_node	*node;

	if (!list || !(list->len))
		return ;
	if (!del_ptr)
		del_ptr = l_default_del_ptr;
	if (!prev)
	{
		node = list->head;
		list->head = node->next;
	}
	else
	{
		node = prev->next;
		prev->next = node->next;
	}
	if (node == list->last)
		list->last = prev;
	del_ptr(node->p);
	free(node);
	list->len--;
}
