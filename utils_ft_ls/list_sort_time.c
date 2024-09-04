/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_sort_time.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 21:46:01 by aben-ham          #+#    #+#             */
/*   Updated: 2024/09/04 10:13:46 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>
#include <linked_list.h>

static int	compare(void *item1, void *item2)
{
	t_content	*data1;
	t_content	*data2;

	data1 = (t_content *)item1;
	data2 = (t_content *)item2;
	return (data1->m_time < data2->m_time);
}

void	list_sort_time(t_list *list)
{
	int		swapped;
	t_node	*ptr;
	t_node	*last_ptr;
	void	*temp;

	last_ptr = NULL;
	swapped = 1;
	while (swapped && list->len >= 2)
	{
		swapped = 0;
		ptr = list->head;
		while (ptr->next != last_ptr)
		{
			if (compare(ptr->p, ptr->next->p) > 0)
			{
				temp = ptr->p;
				ptr->p = ptr->next->p;
				ptr->next->p = temp;
				swapped = 1;
			}
			ptr = ptr->next;
		}
		last_ptr = ptr;
	}
}
