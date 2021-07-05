/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_libft4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjeong <tjeong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 13:04:21 by tjeong            #+#    #+#             */
/*   Updated: 2021/07/05 13:04:37 by tjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	len;
	size_t	i;

	if (!src)
		return (0);
	len = ft_strlen(src);
	i = 0;
	if (dstsize == 0)
		return (len);
	while (src[i] && (i + 1) < dstsize)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	data;
	unsigned char	*str;

	str = (unsigned char *)s;
	data = (unsigned char)c;
	while (*str)
	{
		if (*str == data)
			return ((char *)str);
		str++;
	}
	if (data == '\0')
		return ((char *)str);
	return (NULL);
}
