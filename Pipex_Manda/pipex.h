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
# include "../libft/libft.h"

//  Structures :
typedef struct s_cmd_pack
{
	char	**cmd;
	char	*cmd_path;
	int		in_fd;
	int		out_fd;
}	t_cmd_pack;

//	functions :
//	**********  Processing functions :
void		process_args(int ac, char **av, char **env);
void		process_cmd(int fd[2], int ac, char **av, char **env);
void		process_execution(t_cmd_pack *cmd_pack, \
			int ac, char **env);
//	**********  Error handling :
void		error_args(void);
void		error_files(void);
void		error_fill_arg(char *str);
void		error_cmd(char *arg);
void		error(void);
//	**********  Pipex Utils :
void		free_tab(char **tab);
void		free_struct(t_cmd_pack *cmd_pack, int idx);
char		*get_cmd_path(char *cmd_path, char *cmd, char **paths);
t_cmd_pack	*fill_cmd_pack(t_cmd_pack *cmd_pack, \
			char **paths, int ac, char **av);
t_cmd_pack	*get_cmd_pack(int ac, char **av, char **env);
//	**********  Execute functions :
void		ft_pip(int	**fd);
int			ft_fork(void);
void		ft_dup(t_cmd_pack *cmd_pack, int idx, int fd, int ac);
void		execute_cmd(t_cmd_pack *cmd_pack, int ac, char **env);
#endif
