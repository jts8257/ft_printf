/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_libft1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjeong <tjeong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 11:16:53 by tjeong            #+#    #+#             */
/*   Updated: 2021/07/05 15:02:40 by tjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (c);
	return (0);
}

void	ft_bzero(void *s, size_t n)
{
	char	*tmp_ptr;
	size_t	i;

	tmp_ptr = (char *)s;
	i = 0;
	while (n--)
	{
		tmp_ptr[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*new_ptr;
	size_t	i;

	new_ptr = (char *)malloc(size * count);
	if (!new_ptr)
		return (NULL);
	i = 0;
	while (i < size * count)
	{
		new_ptr[i] = '\0';
		i++;
	}
	return ((void *)new_ptr);
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*tmp_ptr;

	tmp_ptr = (unsigned char *)b;
	i = 0;
	while (len--)
		tmp_ptr[i++] = (unsigned char)c;
	return (b);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
