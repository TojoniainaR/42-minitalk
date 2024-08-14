# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: torandri <torandri@student.42antanana      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/17 16:10:33 by torandri          #+#    #+#              #
#    Updated: 2024/05/17 16:14:09 by torandri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

FLAGS = -Wall -Werror -Wextra

NAME = libgnl.a

RM = rm -f

HEADER = get_next_line.h get_next_line_bonus.h

LIBC = ar -rcs

SRCS = get_next_line.c get_next_line_utils.c

OBJS = get_next_line.o get_next_line_utils.o

BSRCS = get_next_line_bonus.c get_next_line_utils_bonus.c

BOBJS = get_next_line_bonus.c get_next_line_utils_bonus.o

all : $(NAME)

.c.o :
	@$(CC) -c $(FLAGS) -o $@ $<

$(NAME) : $(OBJS)
	@$(LIBC) $(NAME) $(OBJS)
	@ranlib $(NAME)

bonus : $(OBJS) $(BOBJS)
	@$(LIBC) $(NAME) $(OBJS) $(BOBJS)
	@ranlib $(NAME)

clean :
	@$(RM) *.o

fclean : clean
	@$(RM) $(NAME)

re : fclean all
