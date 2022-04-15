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
# .SILENT :
SRC = ./Pipex_Manda/pipex.c ./Pipex_Manda/pipex_utils.c ./Pipex_Manda/error_handling.c ./Pipex_Manda/ft_process.c ./Pipex_Manda/ft_execute.c
OBJECT = $(SRC:.c=.o)
BNS_SRC = ./bonus_pipex/pipex_bonus.c ./bonus_pipex/pipex_utils_bonus.c ./bonus_pipex/error_handling_bonus.c ./bonus_pipex/ft_process_bonus.c \
			./bonus_pipex/ft_execute_bonus.c ./bonus_pipex/ft_here_doc.c ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c 
BNS_OBJ = $(BNS_SRC:.c=.o)
CFlAGS = -Wall -Wextra -Werror -I

all : $(NAME)

$(NAME) : $(OBJECT) ./Pipex_Manda/pipex.h
	make -C ./libft
	gcc $(OBJECT) -o $(NAME) ./libft/libft.a -g

bonus :	$(BNS_OBJ) ./bonus_pipex/pipex_bonus.h ./get_next_line/get_next_line.h
	make -C ./libft
	gcc $(BNS_SRC) -o $(NAME) ./libft/libft.a -g

clean :
	rm -rf $(OBJECT) $(BNS_OBJ)

fclean : clean
	make fclean -C ./libft
	rm -rf $(NAME)

re : fclean all

rb : fclean bonus
