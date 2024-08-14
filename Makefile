# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: torandri <torandri@student.42antananari    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/14 12:41:39 by torandri          #+#    #+#              #
#    Updated: 2024/08/14 12:41:40 by torandri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = server

NAME_CLI = client

LIBFT = -L./libft -lft

PRINTF = -L./printf -lftprintf

GNL = -L./gnl -lgnl

RM = rm -f

HEADER = minitalk.h

SRCS_SERVER = server.c

SRCS_CLIENT = client.c minitalk_utils.c

OBJS_SERVER = $(SRCS_SERVER:.c=.o)

OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

SRCS_BONUS_SERVER = server_bonus.c

SRCS_BONUS_CLIENT = client_bonus.c minitalk_utils.c

OBJS_BONUS_SERVER = $(SRCS_BONUS_SERVER:.c=.o)

OBJS_BONUS_CLIENT = $(SRCS_BONUS_CLIENT:.c=.o)

all : $(NAME) $(NAME_CLI)

$(NAME) : $(OBJS_SERVER) $(OBJS_CLIENT)
	make -C ./libft
	make -C ./printf
	make -C ./gnl
	$(CC) $(CFLAGS) -g server.c $(LIBFT) $(PRINTF) $(GNL) -o $(NAME)
	$(CC) $(CFLAGS) -g client.c minitalk_utils.c $(LIBFT) $(PRINTF) $(GNL) -o $(NAME_CLI)
	
bonus : $(OBJS_BONUS_SERVER) $(OBJS_BONUS_CLIENT)
	make -C ./libft
	make -C ./printf
	make -C ./gnl
	$(CC) $(CFLAGS) -g server_bonus.c $(LIBFT) $(PRINTF) $(GNL) -o server_bonus
	$(CC) $(CFLAGS) -g client_bonus.c minitalk_utils.c $(LIBFT) $(PRINTF) $(GNL) -o client_bonus

clean :
	@make clean -C ./libft
	@make clean -C ./printf
	@make clean -C ./gnl
	@$(RM) $(OBJS_SERVER) $(OBJS_CLIENT) $(OBJS_BONUS_CLIENT) $(OBJS_BONUS_SERVER)

fclean : clean
	@make fclean -C ./libft
	@make fclean -C ./printf
	@make fclean -C ./gnl
	@$(RM) $(NAME) $(NAME_CLI) server_bonus client_bonus

re : fclean all
	@make re -C ./libft
	@make re -C ./printf
	@make re -C ./gnl
