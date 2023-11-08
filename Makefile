# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seohyeki <seohyeki@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/05 21:29:03 by seohyeki          #+#    #+#              #
#    Updated: 2023/11/07 20:21:14 by seohyeki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a
SRCS=ft_printf.c
OBJS=$(SRCS:.c=.o)
LIBFT=./libft/libft.a
LIBFT_DIR=./libft
CFLAGS=-Wall -Wextra -Werror

all: $(NAME)
	
$(NAME) : $(OBJS)
	make -C $(LIBFT_DIR)
	cp $(LIBFT) $(NAME)
	ar -cr $@ $^

%.o : %.c
	cc $(CFLAGS) -c $< -o $@

clean : 
	rm -f $(OBJS)
	make clean -C $(LIBFT_DIR)

fclean : clean
	rm -f $(NAME) $(LIBFT)

re : 
	make fclean 
	make all

.PHONY: all clean fclean re
