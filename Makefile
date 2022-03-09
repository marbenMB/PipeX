# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbenbajj <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/09 09:03:44 by mbenbajj          #+#    #+#              #
#    Updated: 2022/03/09 09:03:47 by mbenbajj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
SRC = main.c pipex.c libft/auto_func.c libft/ft_split.c
OBJECT = $(SRC:.c=.o)
CFlAGS = -Wall -Wextra -Werror -I.

all : $(NAME)

$(NAME) : $(OBJECT) pipex.h
	gcc $(OBJECT) -o $(NAME)

clean :
	rm -rf $(OBJECT)

fclean : clean
	rm -rf $(NAME)

re : fclean all
