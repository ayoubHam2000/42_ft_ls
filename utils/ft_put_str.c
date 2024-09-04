/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 21:34:43 by aben-ham          #+#    #+#             */
/*   Updated: 2024/09/04 10:33:22 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <utils.h>

void	ft_put_str(int fd, const char *str)
{
	write(fd, str, ft_strlen(str));
}

void	ft_put_str_buffer(int fd, const char *str, size_t	buf_size)
{
	size_t	len;

	len = ft_strlen(str);
	write(fd, str, len);
	while (len < buf_size)
	{
		write(fd, " ", 1);
		len++;
	}
}
