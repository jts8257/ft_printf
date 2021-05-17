/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjeong <tjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 16:09:40 by tjeong            #+#    #+#             */
/*   Updated: 2021/05/09 13:25:44 by tjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*dst_ptr;
	unsigned char	*src_ptr;

	if (dst == src || len == 0)
		return (dst);
	dst_ptr = (unsigned char *)dst;
	src_ptr = (unsigned char *)src;
	if (dst < src)
		ft_memcpy(dst_ptr, src_ptr, len);
	else
	{
		i = 0;
		while (len - i > 0)
		{
			dst_ptr[len - i - 1] = src_ptr[len - i - 1];
			i++;
		}
	}
	return (dst);
}
