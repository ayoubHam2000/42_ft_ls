/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_append_end.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 21:27:26 by aben-ham          #+#    #+#             */
/*   Updated: 2022/02/14 14:26:45 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

int	l_append_end(t_list *list, void *p)
{
	t_node	*new;

	new = l_create_node(p);
	if (!new)
		return (0);
	if (list->head)
	{
		list->last->next = new;
		list->last = new;
	}
	else
	{
		list->head = new;
		list->last = new;
	}
	list->len++;
	return (1);
}
