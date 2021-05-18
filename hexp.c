
#include "printf.h"

static void		to_upper(char *hex)
{
	int			i;
	
	i = 0;
	while (hex[i])
	{
		if (hex[i] >= 'a' && hex[i] <= 'z')
			hex[i] = hex[i] - 32;
		i++;
	}
}

static int		hexsize(unsigned long long num)
{
	int			size;
	size = 0;
	while (num)
	{
		num /= 16;
		size++;
	}
	return (size);
}

static char		*hexnumber(unsigned long long num)
{
	char		*result;
	char		*hexlist;
	int			size;
	int			sign;

	hexlist = "0123456789abcdef";
	size = hexsize(num);
	sign = 1;
	result = (char *)malloc(sizeof(char) * size + 1);
	result[size] = '\0';
	while (num)
	{
		result[--size] = hexlist[num % 16 * sign];
		num = num /16;
	}
	return (result);
}

char	*treat_hexp(unsigned long long num)
{
	write(1, "0x", 2);
	return (hexnumber(num));
}
