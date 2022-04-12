/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 00:09:55 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/04/12 00:09:58 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

//  includes : 
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include "./libft/libft.h"

//  Structures :
typedef struct s_cmd_pack
{
	char	**cmd;
	char	*cmd_path;
}	t_cmd_pack;

//	functions :
//	**********  Processing functions :
void		process_args(int ac, char **av, char **env);
void		process_cmd(int fd[2], int ac, char **av, char **env);
//	**********  Error handling :
void		error_args(void);
void		error_files(void);
void		error_fill_arg(char *str);
void		error_cmd(char *arg, t_cmd_pack *cmd_pack, int idx);
//	**********  Pipex Utils :
void		free_struct(t_cmd_pack *cmd_pack, int idx);
t_cmd_pack	*fill_cmd_pack(t_cmd_pack *cmd_pack, char **paths, int ac, char **av);
t_cmd_pack	*get_cmd_pack(int ac, char **av, char **env);
#endif
