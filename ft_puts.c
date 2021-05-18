/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjeong <tjeong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 18:19:56 by tjeong            #+#    #+#             */
/*   Updated: 2021/05/18 18:21:39 by tjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void		ft_putnbr_recur(long long n, int fd)
{
	char tmp;

	if (n > 9)
	{
		ft_putnbr_recur(n / 10, fd);
		tmp = (n % 10) + '0';
		write(fd, &tmp, 1);
	}
	else
	{
		tmp = (n % 10) + '0';
		write(fd, &tmp, 1);
		return ;
	}
}

void			ft_putnbr_fd(long long n, int fd)
{
	if (n < 0)
	{
		n *= -1;
		write(fd, "-", 1);
	}
	ft_putnbr_recur(n, fd);
	return ;
}

void			ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
}

void			ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
