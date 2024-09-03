/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path_join.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 21:33:46 by aben-ham          #+#    #+#             */
/*   Updated: 2024/09/03 21:37:06 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <utils.h>

char	*ft_path_join(const char *s1, const char *s2)
{
	size_t	len_1;
	size_t	len_2;
	char	*res;
	int		i;

	i = 0;
	len_1 = ft_strlen(s1);
	len_2 = ft_strlen(s2);
	res = ft_malloc(len_1 + len_2 + 2);
	while (*s1 != 0)
	{
		res[i++] = *s1;
		s1++;
	}
	res[i++] = '/';
	while (*s2 != 0)
	{
		res[i++] = *s2;
		s2++;
	}
	res[i] = 0;
	return (res);
}
