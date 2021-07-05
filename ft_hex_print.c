/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjeong <tjeong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 10:28:34 by tjeong            #+#    #+#             */
/*   Updated: 2021/07/05 16:25:12 by tjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	hexsize(unsigned int num)
{
	int	size;

	size = 0;
	while (num)
	{
		num /= 16;
		size++;
	}
	return (size);
}

static	int	ptrsize(unsigned long long num)
{
	int	size;

	size = 0;
	while (num)
	{
		num /= 16;
		size++;
	}
	return (size);
}

char	*treat_hex(unsigned int num, char *hexlist)
{
	char	*result;
	int		size;

	if (num == 0)
	{
		result = (char *)malloc(sizeof(char) * 2);
		if (!result)
			return (NULL);
		result[0] = '0';
		result[1] = '\0';
	}
	else
	{
		size = hexsize(num);
		result = (char *)malloc(sizeof(char) * size + 1);
		if (!result)
			return (NULL);
		result[size] = '\0';
		while (num)
		{
			result[--size] = hexlist[num % 16];
			num /= 16;
		}
	}
	return (result);
}

char	*treat_ptr(unsigned long long num)
{
	char		*result;
	char		*hexlist;
	int			size;

	hexlist = "0123456789abcdef";
	size = ptrsize(num);
	result = (char *)malloc(sizeof(char) * size + 1);
	if (!result)
		return (NULL);
	result[size] = '\0';
	while (num)
	{
		result[--size] = hexlist[num % 16];
		num /= 16;
	}
	return (result);
}
