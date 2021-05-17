/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjeong <tjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 20:23:27 by tjeong            #+#    #+#             */
/*   Updated: 2021/05/09 15:49:37 by tjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	front;
	size_t	back;
	char	*tmp_ptr;
	char	*trimed_str;

	if (!s1 || !set)
		return (NULL);
	front = 0;
	back = 0;
	tmp_ptr = (char *)s1;
	while (s1[front] && ft_strchr(set, s1[front]))
		front++;
	back = ft_strlen(tmp_ptr + front);
	if (back > 0)
		while (tmp_ptr[back + front - 1] &&
				ft_strchr(set, tmp_ptr[back + front - 1]))
			back--;
	if (!(trimed_str = (char *)malloc(back * sizeof(char) + 1)))
		return (NULL);
	ft_strlcpy(trimed_str, tmp_ptr + front, back + 1);
	trimed_str[back] = '\0';
	return (trimed_str);
}
