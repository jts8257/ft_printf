/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjeong <tjeong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 16:21:37 by tjeong            #+#    #+#             */
/*   Updated: 2021/07/05 16:23:04 by tjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	pointer_format(unsigned long long n, t_opt *opt)
{
	int		print_len;
	char	*addr;

	if (n == 0 && opt->prec == 0)
		addr = ft_strdup("");
	else if (n == 0 && opt->prec == -1)
		addr = ft_strdup("0");
	else
		addr = treat_ptr(n);
	addr = apply_prec(opt->prec, addr);
	addr = ft_strjoin(ft_strdup("0x"), addr);
	addr = apply_width(opt, ft_strdup(""), addr);
	if (!addr)
		return (-1);
	print_len = ft_putstr_fd(addr, 1);
	free(addr);
	return (print_len);
}

int	hex_format(unsigned int n, t_opt *opt)
{
	int		print_len;
	char	*arg;

	if (opt->prec == 0 && n == 0)
		arg = ft_strdup("");
	else if (opt->type == 'x')
		arg = treat_hex(n, "0123456789abcdef");
	else if (opt->type == 'X')
		arg = treat_hex(n, "0123456789ABCDEF");
	else
		return (0);
	arg = apply_prec(opt->prec, arg);
	arg = apply_width(opt, ft_strdup(""), arg);
	if (!arg)
		return (-1);
	print_len = ft_putstr_fd(arg, 1);
	free(arg);
	return (print_len);
}
