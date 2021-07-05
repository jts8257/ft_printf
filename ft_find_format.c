/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjeong <tjeong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 12:41:52 by tjeong            #+#    #+#             */
/*   Updated: 2021/07/05 15:03:27 by tjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	change_opt(t_opt *opt)
{
	opt->minus = 1;
	opt->width *= -1;
	opt->zero = 0;
}

static void	set_width_prec(va_list *ap, t_opt *opt, char ch)
{
	if (ft_isdigit(ch))
	{
		if (opt->prec == -1)
			opt->width = opt->width * 10 + ch - '0';
		else
			opt->prec = opt->prec * 10 + ch - '0';
	}
	else if (ch == '*')
	{
		if (opt->prec == -1)
		{
			opt->width = va_arg(*ap, int);
			if (opt->width < 0)
				change_opt(opt);
		}
		else
		{
			opt->prec = va_arg(*ap, int);
			if (opt->prec < 0)
				opt->prec = -1;
		}
	}
}

static int	type_matcging(va_list *ap, t_opt *opt)
{
	if (opt->type == 'c')
		return (char_format(va_arg(*ap, int), opt));
	else if (opt->type == 's')
		return (str_format(va_arg(*ap, char *), opt));
	else if (opt->type == 'i' || opt->type == 'd')
		return (int_format(va_arg(*ap, int), opt));
	else if (opt->type == 'u')
		return (unint_format(va_arg(*ap, unsigned int), opt));
	else if (opt->type == 'p')
		return (pointer_format(va_arg(*ap, unsigned long long), opt));
	else if (opt->type == 'x' || opt->type == 'X')
		return (hex_format(va_arg(*ap, unsigned int), opt));
	else if (opt->type == '%')
		return (char_format(opt->type, opt));
	else
		return (-1);
}

int	find_format(char *str, va_list *ap)
{
	int		print_len;
	t_opt	*opt;

	opt = init_opt();
	if (!opt)
		return (-1);
	while (!ft_strchr(TYPES, *str) && *str != '\0')
	{
		if (*str == '-')
			opt->minus = 1;
		else if (*str == '0' && opt->width == 0
			&& opt->prec == -1 && opt->minus == 0)
			opt->zero = 1;
		else if (*str == '.')
			opt->prec = 0;
		else if (ft_isdigit(*str) || *str == '*')
			set_width_prec(ap, opt, *str);
		str++;
	}
	opt->type = *str;
	if ((opt->prec >= 0 || opt->minus > 0) && opt->type != '%')
		opt->zero = 0;
	print_len = type_matcging(ap, opt);
	free(opt);
	return (print_len);
}
