/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:13:53 by aben-ham          #+#    #+#             */
/*   Updated: 2022/02/15 16:01:24 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"
#include <stdio.h>

void	*p_int(int a)
{
	int	*p;

	p = malloc(4);
	*p = a;
	return (p);
}

void	*c_int(void *p)
{
	int	*n;

	n = malloc(4);
	*n = *((int *)p);
	return (n);
}

int	main(void)
{
	t_list	*list;
	t_list	*c_list;
	t_node	*node;

	list = l_init();
	l_append_end(list, p_int(10));
	l_append_end(list, p_int(18));
	l_append_end(list, p_int(8));
	c_list = l_clone(list, c_int);
	node = c_list->head;
	while (node)
	{
		if (node->p)
			printf("%d, ", *((int *)(node->p)));
		node = node->next;
	}
	printf("\n");
	system("leaks linked_list");
	return (0);
}
