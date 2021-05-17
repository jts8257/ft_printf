
#include <stdio.h>

int		ft_printf(const char *s, ...);

int		main(void)
{
	char	s[] = "abcdefg";
	int		num = 10;
	char	c = 'c';

	printf("%d %s\n", num, s);
	ft_printf("%d %s\n",num, s); 
}
