/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 19:02:12 by aben-ham          #+#    #+#             */
/*   Updated: 2022/02/15 15:38:01 by aben-ham         ###   ########.fr       */
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
	long		len;
	long		nb_blocks;
};

//NULL in case of malloc error
void	*l_init(void);

//NULL in case of not found
t_node	*l_get(t_list *list, long pos);

//NULL in case of malloc error
t_node	*l_create_node(void *p);

/*
* these functions return 0 in case of an error => nothing will be added
* be careful to create a pointer in the seconde parameter
	that will produce a leak in case of an error occurs 
	(nothing will be added => the reference of the pointer will be lost)
*/
int		l_append_front(t_list *list, void *p);
int		l_append_end(t_list *list, void *p);
int		l_append_index(t_list *list, long index, void *p);
void	l_append_after(t_list *list, t_node *node1, t_node *node2);

/*
* NULL if the creating of Nodes failed
* if clone_ptr is NULL => all pointers of the cloned list will be NULL
*/
t_list	*l_clone(t_list *list, void *(*clone_ptr)(void *p));

//if del_ptr is NULL free(p) will specified
void	l_del_by_prev(t_list *list, t_node *prev, void (*del_ptr)(void *p));
void	l_del_by_index(t_list *list, long index, void (*del_ptr)(void *p));
void	l_clear(t_list *list, void (*del_ptr)(void *p));
void	l_del_cond(t_list *lists,
			void *p,
			int (*condition)(t_node *node, void *p),
			void (*del_ptr)(void *p));

#endif
