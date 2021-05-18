#include "printf.h"


int				is_format(char c)
{
	char	formats[9];
	int		i;

	foramts = "cspdiuxX%";
	i = 0;
	while(formats[i])
	{
		if (c== formats[i])
			return (1);
		i++;
	}
	return (0);
}

void			ft_produce(char c, t_list ap)
{
	if (s[i + 1] == 'c')
		ft_putchar_fd((char)va_arg(ap, int), 1);
	else if (s[i + 1] == 's')
		ft_putstr_fd((char *)va_arg(ap, char *), 1);
	else if (s[i + 1] == 'd' || s[i + 1] == 'i')
		ft_putnbr_fd((int)va_arg(ap, int), 1);
	else if (s[i + 1] == 'u')
		ft_putnbr_fd((unsigned int)va_arg(ap, unsigned int), 1);
	else if (s[i + 1] == 'p')
		ft_putstr_fd(treat_hexp((unsigned long long)
					va_arg(ap,unsigned long long)), 1);
	else if (s[i + 1] == 'x' || s[i + 1] == 'X')
		ft_putstr_fd(treat_hexx(
					(unsigned int)va_arg(ap, unsigned int),s[i + 1]), 1);
	else if (s[i + 1] == '%')
		write(1, "%", 1);
}

int				ft_printf(const char *s, ...)
{
	va_list		ap;
	int			i;
	
	va_start(ap, s);

	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
			while (!is_format(s[i])


		else
			write(1, &s[i], 1);
		i++;
	}
	va_end(ap);
	return (0);
}
