/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_del_by_index.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 23:31:10 by aben-ham          #+#    #+#             */
/*   Updated: 2022/02/15 13:47:29 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

static void	l_default_del_ptr(void	*p)
{
	free(p);
}

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

void	l_del_by_index(t_list *list, long index, void (*del_ptr)(void *p))
{
	t_node	*node;
	t_node	*previous;

	if (!l_check(list, &index))
		return ;
	if (!del_ptr)
		del_ptr = l_default_del_ptr;
	previous = NULL;
	if (index == 0)
	{
		node = list->head;
		list->head = node->next;
	}
	else
	{
		previous = l_get(list, index - 1);
		node = previous->next;
		previous->next = node->next;
	}
	if (node == list->last)
		list->last = previous;
	del_ptr(node->p);
	free(node);
	list->len--;
}
