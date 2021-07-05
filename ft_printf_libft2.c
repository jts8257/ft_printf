/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_libft2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjeong <tjeong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 11:16:57 by tjeong            #+#    #+#             */
/*   Updated: 2021/07/05 15:02:45 by tjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

int	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return (0);
	write(fd, s, ft_strlen(s));
	return (ft_strlen(s));
}

char	*ft_strdup(const char *s1)
{
	size_t	len;
	size_t	i;
	char	*new_ptr;

	len = 0;
	while (s1[len])
		len++;
	new_ptr = (char *)malloc((len + 1) * sizeof(char));
	if (!new_ptr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new_ptr[i] = s1[i];
		i++;
	}
	new_ptr[i] = '\0';
	return (new_ptr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	str_len;
	char	*substr;

	if (s == 0)
		return (NULL);
	str_len = ft_strlen(s);
	if (start >= str_len)
		return (ft_strdup(""));
	if (len >= str_len - start)
		len = str_len - start;
	substr = (char *)malloc(len * sizeof(char) + 1);
	if (!substr)
		return (NULL);
	i = 0;
	while (s[start + i] && i < len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*concat;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	concat = (char *)malloc((s1_len + s2_len) * sizeof(char) + 1);
	if (!concat)
		return (NULL);
	ft_bzero(concat, (s1_len + s2_len + 1));
	ft_strlcpy(concat, (char *)s1, s1_len + 1);
	ft_strlcpy(&concat[s1_len], (char *)s2, s2_len + 1);
	free(s1);
	free(s2);
	return (concat);
}
