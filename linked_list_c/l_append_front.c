/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_append_front.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 19:08:58 by aben-ham          #+#    #+#             */
/*   Updated: 2022/02/14 14:27:29 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

int	l_append_front(t_list *list, void *p)
{
	t_node	*new;

	new = l_create_node(p);
	if (!new)
		return (0);
	if (!list->head)
	{
		list->head = new;
		list->last = new;
	}
	else
	{
		new->next = list->head;
		list->head = new;
	}
	list->len++;
	return (1);
}
