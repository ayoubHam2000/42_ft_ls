/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_nbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 21:34:45 by aben-ham          #+#    #+#             */
/*   Updated: 2024/09/03 21:34:46 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

static void	ft_putnbr_fd_rec(ssize_t n, int fd, size_t sign)
{
	if (n == 0)
		write (fd, "0", 1);
	else
	{
		if (n / 10 != 0)
			ft_putnbr_fd_rec(n / 10, fd, sign);
		ft_putchar_fd((n % 10) * sign + '0', fd);
	}
}

void	ft_put_nbr(int fd, ssize_t n)
{
	size_t	sign;

	sign = 1;
	if (n < 0)
	{
		sign = -1;
		write (fd, "-", 1);
	}
	ft_putnbr_fd_rec(n, fd, sign);
}
