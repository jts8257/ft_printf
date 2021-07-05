/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_libft3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjeong <tjeong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 10:13:03 by tjeong            #+#    #+#             */
/*   Updated: 2021/07/05 15:02:50 by tjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	ft_digit(long long n)
{
	int	digit;

	digit = 0;
	while (n)
	{
		digit++;
		n /= 10;
	}
	return (digit);
}

static	void	ft_itoa_insert(long long n, char *converted, int size)
{
	int	limit;
	int	sign;

	limit = 0;
	sign = 1;
	converted[size] = '\0';
	if (n < 0)
	{
		converted[0] = '-';
		limit = 1;
		sign = -1;
	}
	while (size-- > limit)
	{
		converted[size] = (((n % 10) * sign) + '0');
		n /= 10;
	}
}

char	*ft_itoa(long long n)
{
	char	*converted;
	int		size;

	if (n <= 0)
		size = ft_digit(n) + 1;
	else
		size = ft_digit(n);
	converted = (char *)malloc(size * sizeof(char) + 1);
	if (!converted)
		return (NULL);
	else
		ft_itoa_insert(n, converted, size);
	return (converted);
}
