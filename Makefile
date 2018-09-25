# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmkwanaz <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/24 11:46:17 by lmkwanaz          #+#    #+#              #
#    Updated: 2018/08/25 12:16:13 by lmkwanaz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc -c

CFLAGS = -Wall -Werror -Wextra -g -I"." 

LINK = ./libft/libft.a

SRCS = *.c
	    

OBJS = *.o


all: $(NAME)

$(NAME):
	make -C libft/ 
	$(CC)  $(CFLAGS) $(SRCS)
	ar rc $(NAME) $(OBJS) $(LINK)
	ranlib $(NAME)

clean:
	make -C libft/ clean
	rm -f $(OBJS)

fclean: clean 
	make -C libft/ fclean
	rm -f $(NAME)

re: fclean all

