/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_create_node.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 21:28:38 by aben-ham          #+#    #+#             */
/*   Updated: 2022/02/14 11:19:02 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

t_node	*l_create_node(void *p)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->p = p;
	new->next = NULL;
	return (new);
}
