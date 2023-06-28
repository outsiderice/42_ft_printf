# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amagnell <amagnell@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/11 15:57:33 by amagnell          #+#    #+#              #
#    Updated: 2023/06/28 19:11:13 by amagnell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -MD
INCLUDE = ft_printf.h
SOURCES = ft_printf.c\
		  ft_putchar.c\
		  ft_putnbr.c\
		  ft_putstr.c\
		  ft_strchr.c\
		  ft_nbrs.c\
		  ft_putptr.c\
		  ft_sort_format.c\
		  ft_strlen.c\
		  ft_putunbr.c

OBJECTS = $(SOURCES:.c=.o)

DEP = $(SOURCES:.c=.d)

$(NAME) : $(OBJECTS)
	ar -rsc $@ $(OBJECTS)

all : $(NAME)

fclean : clean
	rm -f $(NAME)

clean :
	rm -f $(OBJECTS) $(DEP)

re : fclean all

.PHONY: all re clean fclean

-include $(DEP)
