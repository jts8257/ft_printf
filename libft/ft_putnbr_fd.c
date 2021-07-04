/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjeong <tjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 21:25:31 by tjeong            #+#    #+#             */
/*   Updated: 2021/05/07 20:40:14 by tjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_recur(int n, int fd)
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

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		n *= -1;
		write(fd, "-", 1);
	}
	ft_putnbr_recur(n, fd);
	return ;
}
