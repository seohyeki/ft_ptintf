# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seohyeki <seohyeki@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/05 21:29:03 by seohyeki          #+#    #+#              #
#    Updated: 2023/11/08 15:58:46 by seohyeki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a
LIBFT=libft.a
SRCS=main.c
OBJS=$(SRCS:.c=.o)
LIBFT_DIR=./libft
CFLAGS=-Wall -Wextra -Werror

all: $(NAME)
	
$(NAME) : $(OBJS)
	make -C $(LIBFT_DIR)
	mv $(LIBFT_DIR)/$(LIBFT) ./
	mv $(LIBFT) $(NAME)
	ar -cr $@ $^

%.o : %.c
	cc $(CFLAGS) -c $< -o $@

clean : 
	rm -f $(OBJS)
	make clean -C $(LIBFT_DIR)

fclean : clean
	rm -f $(NAME)

re : 
	make fclean 
	make all

.PHONY: all clean fclean re
