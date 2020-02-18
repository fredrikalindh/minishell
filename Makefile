# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frlindh <frlindh@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/23 13:37:02 by frlindh           #+#    #+#              #
#    Updated: 2020/01/23 13:52:32 by frlindh          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	msh
SRCS_LIST	=	main.c parse.c
SRCS		=	$(addprefix srcs/, $(SRCS_LIST))
OBJS		=	$(patsubst %.c, %.o, $(SRCS))
CC			= 	GCC
FLAGS		=	-Wall -Werror -Wextra
INCL		=	./includes/minishell.h

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all