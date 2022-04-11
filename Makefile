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
BNS_NAME = pipex_bonus
SRC = main.c pipex.c pipex_utils.c error_handling.c ft_process.c
.SILENT :
OBJECT = $(SRC:.c=.o)
BNS_SRC = main_bonus.c pipex_bonus.c pipex_bonus_utils.c error_handling.c libft/auto_func.c libft/ft_split.c libft/lib_func.c
BNS_OBJ = $(SRC:.c=.o)
CFlAGS = -Wall -Wextra -Werror -I.

all : $(NAME)

$(NAME) : $(OBJECT) pipex.h
	# gcc $(OBJECT) -o $(NAME)
	make -C ./libft
	@gcc $(SRC) -o $(NAME) ./libft/libft.a -g

bonus :	$(BNS_NAME)

$(BNS_NAME) : $(BNS_OBJ) pipex_bonus.h
	# gcc $(BNS_OBJ) -o $(BNS_NAME)
	@gcc $(BNS_SRC) -o $(BNS_NAME) -g

clean :
	@rm -rf $(OBJECT) $(BNS_OBJ)

fclean : clean
	make fclean -C ./libft
	@rm -rf $(NAME) $(BNS_NAME)

re : fclean all

rb : fclean bonus
