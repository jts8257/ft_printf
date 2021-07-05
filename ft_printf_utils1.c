/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjeong <tjeong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 10:34:39 by tjeong            #+#    #+#             */
/*   Updated: 2021/07/05 12:51:27 by tjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

t_opt	*init_opt(void)
{
	t_opt	*opt;

	opt = malloc(sizeof(t_opt));
	if (!opt)
		return (0);
	opt->minus = 0;
	opt->zero = 0;
	opt->width = 0;
	opt->prec = -1;
	opt->type = 0;
	return (opt);
}

char	*set_padding(size_t zero_flag, size_t size)
{
	char	*padding;

	if (size < 0)
	{
		padding = ft_strdup("");
		return (padding);
	}
	padding = (char *)calloc(sizeof(char), size + 1);
	if (zero_flag == 0)
		ft_memset(padding, ' ', size);
	else
		ft_memset(padding, '0', size);
	return (padding);
}

char	*set_sorting(size_t mns_flg, char *arg, char *padding)
{
	char	*result;

	if (mns_flg == 0)
		result = ft_strjoin(padding, arg);
	else
		result = ft_strjoin(arg, padding);
	return (result);
}

char	*applies_to_prec(int prec, char *arg)
{
	char	*padding;

	if (prec > -1 && (size_t)prec > ft_strlen(arg))
	{
		padding = set_padding(1, prec - ft_strlen(arg));
		arg = set_sorting(0, arg, padding);
	}
	return (arg);
}

char	*applies_to_width(t_opt *opt, char *sign, char *arg)
{
	char	*padding;

	if (opt->width > 0
		&& (size_t)opt->width > (ft_strlen(sign) + ft_strlen(arg))
		&& opt->width > opt->prec)
	{
		padding = set_padding(opt->zero,
				opt->width - (ft_strlen(sign) + ft_strlen(arg)));
		if (opt->zero == 1)
			padding = ft_strjoin(sign, padding);
		else
			arg = ft_strjoin(sign, arg);
		arg = set_sorting(opt->minus, arg, padding);
	}
	else
		arg = ft_strjoin(sign, arg);
	return (arg);
}
