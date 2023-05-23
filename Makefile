# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amagnell <amagnell@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/11 15:57:33 by amagnell          #+#    #+#              #
#    Updated: 2023/03/11 16:36:59 by amagnell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -MD
INCLUDE = libftprintf.h
SOURCES = libftprintf.c

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
