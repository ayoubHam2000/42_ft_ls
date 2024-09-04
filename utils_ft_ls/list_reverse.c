/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_reverse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 21:45:56 by aben-ham          #+#    #+#             */
/*   Updated: 2024/09/03 21:50:32 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <linked_list.h>

void	list_reverse(t_list *list)
{
	t_node	*prev;
	t_node	*current;
	t_node	*next;

	if (list->head == NULL || list->len < 2)
		return ;
	prev = NULL;
	current = list->head;
	next = NULL;
	list->last = list->head;
	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	list->head = prev;
}
