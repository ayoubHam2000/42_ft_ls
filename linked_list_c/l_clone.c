/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_clone.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 11:40:27 by aben-ham          #+#    #+#             */
/*   Updated: 2022/02/15 15:39:07 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

t_list	*l_empty_list(t_list *list)
{
	t_list	*new_list;
	t_node	*node;

	new_list = l_init();
	if (!new_list)
		return (NULL);
	node = list->head;
	while (node)
	{
		if (!l_append_end(new_list, NULL))
		{
			l_clear(new_list, NULL);
			free(new_list);
			return (NULL);
		}
		node = node->next;
	}
	return (new_list);
}

t_list	*l_clone(t_list *list, void *(*clone_ptr)(void *p))
{
	t_list	*new_list;
	t_node	*node;
	t_node	*new_node;

	new_list = l_empty_list(list);
	if (!new_list)
		return (NULL);
	node = list->head;
	new_node = new_list->head;
	while (node)
	{
		if (node->p && clone_ptr)
			new_node->p = clone_ptr(node->p);
		node = node->next;
		new_node = new_node->next;
	}
	return (new_list);
}
