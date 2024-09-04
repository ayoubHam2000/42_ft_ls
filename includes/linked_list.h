/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 19:02:12 by aben-ham          #+#    #+#             */
/*   Updated: 2024/09/03 22:00:00 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKED_LIST_H
# define LINKED_LIST_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_node	t_node;
struct s_node
{
	void	*p;
	t_node	*next;
};

typedef struct s_list	t_list;
struct s_list
{
	t_node	*head;
	t_node	*last;
	long	len;
	long	nb_blocks;
};

void	*l_init(void);
t_node	*l_create_node(void *p);
void	l_clear(t_list *list, void (*del_ptr)(void *p));
int		l_append_end(t_list *list, void *p);

#endif
