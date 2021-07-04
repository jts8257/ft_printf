/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjeong <tjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 14:50:58 by tjeong            #+#    #+#             */
/*   Updated: 2021/05/09 19:03:09 by tjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	unsigned char	data;
	unsigned char	*str;

	data = (unsigned char)c;
	str = (unsigned char *)s;
	i = 0;
	while (str[i])
		i++;
	if (data == '\0')
		return ((char *)(str + i));
	while (i >= 0)
	{
		if (str[i] == data)
			return ((char *)(str + i));
		i--;
	}
	return (0);
}
