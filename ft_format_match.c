/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_match.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjeong <tjeong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 10:28:43 by tjeong            #+#    #+#             */
/*   Updated: 2021/07/05 10:41:43 by tjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

size_t	char_format(int ch, t_opt *opt)
{
	size_t	print_len;
	char	*padding;

	if (opt->width > 0)
		padding = set_padding(opt->zero, (size_t)opt->width - sizeof(char));
	else
		padding = ft_strdup("");
	if (opt->minus == 0)
	{
		print_len = ft_putstr_fd(padding, 1);
		print_len += ft_putchar_fd((char)ch, 1);
	}
	else
	{
		print_len = ft_putchar_fd((char)ch, 1);
		print_len += ft_putstr_fd(padding, 1);
	}
	free(padding);
	return (print_len);
}

size_t	str_format(char *str, t_opt *opt)
{
	size_t	print_len;
	char	*arg;
	char	*padding;

	if (str == NULL)
		str = "(null)";
	if (opt->prec > -1)
	{
		arg = ft_substr(str, 0, opt->prec);
	}
	else
		arg = ft_strdup(str);
	if (opt->width > 0 && (size_t)opt->width > ft_strlen(arg))
	{
		padding = set_padding(opt->zero, opt->width - ft_strlen(arg));
		arg = set_sorting(opt->minus, arg, padding);
	}
	print_len = ft_putstr_fd(arg, 1);
	free(arg);
	return (print_len);
}

size_t	int_format(int n, t_opt *opt)
{
	size_t	print_len;
	char	*sign;
	char	*arg;

	if (n < 0)
		sign = ft_strdup("-");
	else
		sign = ft_strdup("");
	if (opt->prec == 0 && n == 0)
		arg = ft_strdup("");
	else if (n < 0)
		arg = ft_itoa((long long)n * -1);
	else
		arg = ft_itoa(n);
	arg = applies_to_prec(opt->prec, arg);
	arg = applies_to_width(opt, sign, arg);
	print_len = ft_putstr_fd(arg, 1);
	free(arg);
	return (print_len);
}

size_t	pointer_format(long long n, t_opt *opt)
{
	size_t	print_len;
	char	*addr;

	if (n == 0 && opt->prec == 0)
		addr = ft_strdup("");
	else if (n == 0 && opt->prec == -1)
		addr = ft_strdup("0");
	else
		addr = ft_tobase_n(n, "0123456789abcdef");
	addr = applies_to_prec(opt->prec, addr);
	addr = ft_strjoin(ft_strdup("0x"), addr);
	addr = applies_to_width(opt, ft_strdup(""), addr);
	print_len = ft_putstr_fd(addr, 1);
	free(addr);
	return (print_len);
}

size_t	uint_format(unsigned int n, t_opt *opt)
{
	size_t	print_len;
	char	*arg;

	if (opt->prec == 0 && n == 0)
		arg = ft_strdup("");
	else if (opt->type == 'u')
		arg = ft_itoa(n);
	else if (opt->type == 'x')
		arg = ft_tobase_n(n, "0123456789abcdef");
	else if (opt->type == 'X')
		arg = ft_tobase_n(n, "0123456789ABCDEF");
	else
		return (0);
	arg = applies_to_prec(opt->prec, arg);
	arg = applies_to_width(opt, ft_strdup(""), arg);
	print_len = ft_putstr_fd(arg, 1);
	free(arg);
	return (print_len);
}
