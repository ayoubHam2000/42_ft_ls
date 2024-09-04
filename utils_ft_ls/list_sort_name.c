/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_sort_name.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 21:45:59 by aben-ham          #+#    #+#             */
/*   Updated: 2024/09/04 10:12:38 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>
#include <linked_list.h>

static char	*tmp_str(const char *str)
{
	char	*res;
	int		i;

	res = ft_malloc(ft_strlen(str) + 1);
	i = 0;
	while (*str != 0)
	{
		if ((*str >= 'A' && *str <= 'Z') || \
			(*str >= 'a' && *str <= 'z') || (*str >= '0' && *str <= '9'))
		{
			res[i] = *str;
			if ((*str >= 'A' && *str <= 'Z'))
				res[i] = *str + 32;
			i++;
		}
		str++;
	}
	res[i] = 0;
	return (res);
}

static int	compare(void *item1, void *item2)
{
	int			res;
	t_content	*data1;
	t_content	*data2;
	char		*name1;
	char		*name2;

	data1 = (t_content *)item1;
	data2 = (t_content *)item2;
	name1 = tmp_str(data1->name);
	name2 = tmp_str(data2->name);
	res = ft_strncmp(name1, name2, ft_strlen(name2));
	free(name1);
	free(name2);
	return (res);
}

void	list_sort_name(t_list *list)
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
