#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

#include "libft.h"

int			ft_printf(const char *s, ...)
{

	va_list ap;
	va_start(ap, s);

	int num = va_arg(ap, int);
	ft_putnbr_fd(num, 1);

	char *ss = va_arg(ap, char*);
	ft_putstr_fd(ss, 1);
	//읽으면서 format문자가 있는가? + 오류 검사 
	// 통과하면 출력 + flag 적용해서 출력

	//없으면 그냥 그대로 출력

	return (0);
}
