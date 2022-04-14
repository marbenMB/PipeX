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
SRC = pipex.c ./Pipex_Utils/pipex_utils.c ./Pipex_Utils/error_handling.c ./Pipex_Utils/ft_process.c ./Pipex_Utils/ft_execute.c
.SILENT :
OBJECT = $(SRC:.c=.o)
BNS_SRC = pipex_bonus.c ./Pipex_Utils_bonus/pipex_utils_bonus.c ./Pipex_Utils_bonus/error_handling_bonus.c ./Pipex_Utils_bonus/ft_process_bonus.c ./Pipex_Utils_bonus/ft_execute_bonus.c
BNS_OBJ = $(SRC:.c=.o)
CFlAGS = -Wall -Wextra -Werror -I.

all : $(NAME)

$(NAME) : $(OBJECT) ./Pipex_Utils/pipex.h
	# gcc $(OBJECT) -o $(NAME)
	make -C ./libft
	@gcc $(SRC) -o $(NAME) ./libft/libft.a -g

bonus :	$(BNS_NAME)

$(BNS_NAME) : $(BNS_OBJ) ./Pipex_Utils_bonus/pipex_bonus.h
	# gcc $(BNS_OBJ) -o $(BNS_NAME)
	make -C ./libft
	@gcc $(BNS_SRC) -o $(BNS_NAME) ./libft/libft.a -g

clean :
	@rm -rf $(OBJECT) $(BNS_OBJ)

fclean : clean
	make fclean -C ./libft
	@rm -rf $(NAME) $(BNS_NAME)

re : fclean all

rb : fclean bonus
