/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_del_cond.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:58:16 by aben-ham          #+#    #+#             */
/*   Updated: 2022/02/15 14:00:33 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

static void	l_default_del_ptr(void	*p)
{
	free(p);
}

static void	del_target(
				t_list *list, t_node *target,
				t_node *prev, void (*del_ptr)(void *p)
				)
{
	t_node	*tmp;

	if (target == list->head)
	{
		if (list->head == list->last)
			list->last = NULL;
		tmp = list->head->next;
		del_ptr(list->head->p);
		free(list->head);
		list->head = tmp;
	}
	else
	{
		if (target == list->last)
			list->last = prev;
		del_ptr(target->p);
		free(target);
	}
	list->len--;
}

void	l_del_cond(
		t_list *list,
		void *p,
		int (*condition)(t_node *node, void *p),
		void (*del_ptr)(void *p))
{
	t_node	*prev;
	t_node	*node;
	t_node	*target;

	if (!list || !condition)
		return ;
	if (!del_ptr)
		del_ptr = l_default_del_ptr;
	node = list->head;
	prev = NULL;
	while (node)
	{
		if (condition(node, p))
		{
			target = node;
			node = target->next;
			del_target(list, target, prev, del_ptr);
			if (prev)
				prev->next = node;
			continue ;
		}
		prev = node;
		node = node->next;
	}
}
