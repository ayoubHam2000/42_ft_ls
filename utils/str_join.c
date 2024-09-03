/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_join.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 21:34:48 by aben-ham          #+#    #+#             */
/*   Updated: 2024/09/03 21:36:51 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <utils.h>

char	*str_join(const char *s1, const char *s2)
{
	size_t	len_1;
	size_t	len_2;
	char	*res;
	int		i;

	i = 0;
	len_1 = ft_strlen(s1);
	len_2 = ft_strlen(s2);
	res = ft_malloc(len_1 + len_2 + 1);
	while (*s1 != 0)
	{
		res[i++] = *s1;
		s1++;
	}
	while (*s2 != 0)
	{
		res[i++] = *s2;
		s2++;
	}
	res[i] = 0;
	return (res);
}
