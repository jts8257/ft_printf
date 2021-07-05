#ifndef PRINTF_H
# define PRINTF_H

# include <stddef.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# define TYPES "csdiupxX%"

typedef struct s_opt
{
	size_t		minus;
	size_t		zero;
	int			width;
	int			prec;
	char		type;
}	t_opt;

int		ft_printf(const char *str, ...);

t_opt	*init_opt(void);
void	change_opt(t_opt *opt);

char	*next_addr(char *str);
void	set_width_or_prec(va_list *ap, t_opt *opt, char ch);
int		find_format(char *fmt, va_list *ap);
int		type_matcging(va_list *ap, t_opt *opt);

size_t	char_format(int ch, t_opt *opt);
size_t	str_format(char *str, t_opt *opt);
size_t	int_format(int n, t_opt *opt);
size_t	pointer_format(long long n, t_opt *opt);
size_t	uint_format(unsigned int n, t_opt *opt);

char	*set_padding(size_t zr_flg, size_t size);
char	*set_sorting(size_t mns_flg, char *arg, char *padding);
char	*applies_to_prec(int prec, char *arg);
char	*applies_to_width(t_opt *opt, char *sign, char *arg);

int		ft_dupl_check(char *str, int length);
char	*ft_tobase_n(long long n, char *base);

void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
int		ft_isdigit(int c);
char	*ft_itoa(long long n);
void	*ft_memset(void *b, int c, size_t len);
size_t	ft_putchar_fd(char c, int fd);
size_t	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strchr(const char *s, int c);

#endif
