/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_append_after.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 11:37:26 by aben-ham          #+#    #+#             */
/*   Updated: 2022/02/14 15:06:39 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

//append a node after node1
//it's not protected
void	l_append_after(t_list *list, t_node *node1, t_node *node2)
{
	if (!node1)
	{
		node2->next = list->head;
		list->head = node2;
		if (!list->last)
			list->last = list->head;
	}
	else
	{
		if (list->last == node1)
			list->last = node2;
		node2->next = node1->next;
		node1->next = node2;
	}
	list->len++;
}
