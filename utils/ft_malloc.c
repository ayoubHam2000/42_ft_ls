/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 21:33:39 by aben-ham          #+#    #+#             */
/*   Updated: 2024/09/03 21:36:29 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	*ft_malloc(size_t size)
{
	void	*p;

	p = malloc(size);
	if (p == NULL)
	{
		exit(2);
	}
	return (p);
}
