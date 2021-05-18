#ifndef PRINTF_H
 #define PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>


int			ft_printf(const char *s, ...);

size_t		ft_strlen(const char *s);
void		ft_putchar_fd(char c, int fd);
void		ft_putnbr_fd(long long n, int fd);
void		ft_putstr_fd(char *s, int fd);

char		*treat_hexx(unsigned int num, char format);
char		*treat_hexp(unsigned long long num);

#endif
