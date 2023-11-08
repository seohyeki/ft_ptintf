# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seohyeki <seohyeki@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/05 21:29:03 by seohyeki          #+#    #+#              #
#    Updated: 2023/11/06 00:19:25 by seohyeki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a
SRCS=ft_printf.c conversions1.c conversions2.c ft_strlen.c ft_itoa.c ft_uitoa.c
OBJS=$(SRCS:.c=.o)
CFLAGS=-Wall -Wextra -Werror

all: $(NAME)
	
$(NAME) : $(OBJS)
	ar -cr $@ $^

%.o : %.c
	cc $(CFLAGS) -c $< -o $@

clean : 
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
