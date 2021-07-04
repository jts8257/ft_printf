#ifndef HEAD_H
 #define HEAD_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include "./libft/libft.h"
# define TYPES "csdiupxX%"

typedef struct	s_opt
    {
        size_t		minus;
        size_t		zero;
        int			width;
        int			prec;
        char		type;
    }			t_opt;

int             ft_printf(const char *str, ...);
int             data_type(va_list ap, t_opt *opt);
size_t          char_format(int ch, t_opt *opt);
size_t          str_format(char *str, t_opt *opt);
size_t			int_format(int n, t_opt *opt);
size_t			pointer_format(long long n, t_opt *opt);
size_t			uint_format(unsigned int n, t_opt *opt);

int             in_format(char c);
char            *set_padding(size_t zr_flg, size_t size);
char            *set_sorting(size_t mns_flg, char *arg, char *padding);
char            *applies_to_prec(int prec, char *arg);
char            *applies_to_width(t_opt *opt, char *sign, char *arg);
size_t			uint_format(unsigned int n, t_opt *opt);
size_t			pointer_format(long long n, t_opt *opt);
int             ft_dupl_check(char *str, int length);
t_opt           *init_opt();

char			*ft_tobase_n(long long n, char *base);


#endif








