/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjeong <tjeong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 10:28:21 by tjeong            #+#    #+#             */
/*   Updated: 2021/07/05 12:50:07 by tjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static char	*next_addr(char *str)
{
	while (*str)
	{
		if (ft_strchr(TYPES, *str))
		{
			return (++str);
		}
		str++;
	}
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int			print_len;
	int			rtn;
	va_list		ap;

	rtn = 0;
	va_start(ap, str);
	while (*str != '\0')
	{
		if (*str == '%')
		{
			print_len = find_format((char *)++str, &ap);
			if (print_len == -1)
			{
				va_end(ap);
				return (-1);
			}
			rtn += print_len;
			str = next_addr((char *)str);
		}
		else
			rtn += ft_putchar_fd(*str++, 1);
	}
	va_end(ap);
	return (rtn);
}
