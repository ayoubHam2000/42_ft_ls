/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 21:34:54 by aben-ham          #+#    #+#             */
/*   Updated: 2024/09/03 21:37:45 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <utils.h>

char	*ft_strdup(const char *s1)
{
	char		*res;
	int			i;

	res = ft_malloc(ft_strlen(s1) + 1);
	i = 0;
	while (*s1 != 0)
	{
		res[i] = *s1;
		s1++;
		i++;
	}
	res[i] = 0;
	return (res);
}
