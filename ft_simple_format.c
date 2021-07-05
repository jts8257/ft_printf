/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjeong <tjeong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 10:28:43 by tjeong            #+#    #+#             */
/*   Updated: 2021/07/05 16:22:32 by tjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	char_format(int ch, t_opt *opt)
{
	int		print_len;
	char	*padding;

	if (opt->width > 0)
		padding = zero_padding(opt->zero, (size_t)opt->width - sizeof(char));
	else
		padding = ft_strdup("");
	if (!padding)
		return (-1);
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

int	str_format(char *str, t_opt *opt)
{
	int		print_len;
	char	*arg;
	char	*padding;

	if (str == NULL)
		str = "(null)";
	if (opt->prec > -1)
		arg = ft_substr(str, 0, opt->prec);
	else
		arg = ft_strdup(str);
	if (!arg)
		return (-1);
	if (opt->width > 0 && opt->width > ft_strlen(arg))
	{
		padding = zero_padding(opt->zero, opt->width - ft_strlen(arg));
		arg = minus_sorting(opt->minus, arg, padding);
	}
	if (!arg)
		return (-1);
	print_len = ft_putstr_fd(arg, 1);
	free(arg);
	return (print_len);
}

int	int_format(int n, t_opt *opt)
{
	int		print_len;
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
	arg = apply_prec(opt->prec, arg);
	arg = apply_width(opt, sign, arg);
	if (!arg || !sign)
		return (-1);
	print_len = ft_putstr_fd(arg, 1);
	free(arg);
	return (print_len);
}

int	unint_format(unsigned int n, t_opt *opt)
{
	int		print_len;
	char	*arg;

	if (opt->prec == 0 && n == 0)
		arg = ft_strdup("");
	else
		arg = ft_itoa(n);
	arg = apply_prec(opt->prec, arg);
	arg = apply_width(opt, ft_strdup(""), arg);
	if (!arg)
		return (-1);
	print_len = ft_putstr_fd(arg, 1);
	free(arg);
	return (print_len);
}
