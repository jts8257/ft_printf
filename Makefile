NAME = libftprintf.a
AR = ar rc
CC = gcc
CFLAGS = -Wall -Wextra -Werror

FILES = ft_printf ft_find_format ft_printf_utils\
		ft_simple_format ft_hex_format ft_hex_print\
		ft_printf_libft1 ft_printf_libft2 ft_printf_libft3 ft_printf_libft4

SRCDIR = ./
OBJDIR = ./

SRCS = $(addprefix $(SRCDIR), $(addsuffix .c, $(FILES)))
OBJS = $(addprefix $(OBJDIR), $(addsuffix .o, $(FILES)))

$(NAME) : $(OBJS)
	$(AR) $@ $^

all : $(NAME)

clean : 
	rm -rf $(OBJS) $(BOBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

%.o : %.c
	$(CC) $(CFLAGS) -c $?
