# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: torandri <torandri@student.42antanana      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/25 12:05:13 by torandri          #+#    #+#              #
#    Updated: 2024/04/09 10:23:05 by torandri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

FLAGS = -Wall -Werror -Wextra

NAME = libftprintf.a

RM = rm -f

HEADER = ft_printf.h

LIBC = ar -rcs

SRCS = ft_print_char.c ft_print_str.c ft_print_pointer.c ft_print_int.c ft_print_unsd.c ft_print_hexa_high.c ft_print_hexa_low.c ft_printf.c

OBJS = ft_print_char.o ft_print_str.o ft_print_pointer.o ft_print_int.o ft_print_unsd.o ft_print_hexa_high.o ft_print_hexa_low.o ft_printf.o

all : $(NAME)

.c.o :
	@$(CC) -c $(FLAGS) -o $@ $<

$(NAME) : $(OBJS)
	@$(LIBC) $(NAME) $(OBJS)
	@ranlib $(NAME)

clean :
	@$(RM) *.o

fclean : clean
	@$(RM) $(NAME)

re : fclean all
