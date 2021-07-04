# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tjeong <tjeong@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/04 12:36:20 by tjeong            #+#    #+#              #
#    Updated: 2021/05/10 10:40:09 by tjeong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libft.a
CC = gcc
AR = ar rcs
CFLAGS = -Wall -Wextra -Werror

FILES = ft_memset ft_bzero ft_memcpy ft_memccpy ft_memchr ft_memcmp ft_memmove\
		ft_memchr ft_memcmp\
		ft_strlen ft_strlcpy ft_strlcat ft_strchr ft_strrchr ft_strncmp ft_strnstr\
		ft_atoi ft_isalpha ft_isdigit ft_isalnum ft_isascii ft_tolower ft_toupper ft_isprint\
		ft_calloc ft_strdup\
		ft_substr ft_strjoin ft_strtrim ft_split ft_itoa ft_strmapi\
		ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_putnbr_fd

BFILES = ft_lstnew ft_lstadd_front ft_lstsize ft_lstlast ft_lstadd_back\
		 ft_lstdelone ft_lstclear ft_lstiter ft_lstmap

SRCDIR = ./

SRCS = $(addprefix $(SRCDIR), $(addsuffix .c, $(FILES)))
BSRCS = $(addprefix $(SRCDIR), $(addsuffix .c, $(BFILES)))

OBJDIR = ./

OBJS = $(addprefix $(OBJDIR), $(addsuffix .o, $(FILES)))
BOBJS = $(addprefix $(OBJDIR), $(addsuffix .o, $(BFILES)))

$(NAME) : $(OBJS)
	$(AR) $@ $^

bonus : $(BOBJS)
	$(AR) $(NAME) $^

all : $(NAME)

clean : 
	rm -rf $(OBJS) $(BOBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

%.o : %.c
	$(CC) $(CFLAGS) -c $?
