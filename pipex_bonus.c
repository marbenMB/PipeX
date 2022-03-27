/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 08:55:33 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/03/21 08:55:35 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*get_cmd_path(char	**cmd, char **env)
{
	char	**path;
	char	*cmd_path;
	int		i;
	char	**ev;

	i = -1;
	while (!(ft_strnstr(env[++i], "PATH=", 5) && env[i]))
		;
	path = ft_split(&env[i][5], ':');
	while (path++)
	{
		cmd_path = ft_strjoin(path[0], "/");
		cmd_path = ft_strjoin(cmd_path, cmd[0]);
		if (access(cmd_path, X_OK) == 0)
			break ;
	}
	if (access(cmd_path, X_OK) == 0)
		return (cmd_path);
	return (NULL);
}

void	exec_cmd(char *cmd_path, char **cmd, char **env)
{
	int		pip;
	int		pip_fd[2];
	pid_t	id;

	pip = pipe(pip_fd);
	id = fork();
	if (id < 0 || pip < 0)
	{
		ft_putendl_fd("\033[31m ERROR : Fork() or Pipe() problem", 2);
		exit (-1);
	}
	else if (id == 0)
		execve(cmd_path, cmd, env);
	else
		wait(NULL);
}

void	process_here_doc(char *limiter)
{
	
}

void	process_cmd(int ac, char **av, char **env)
{
	char	**cmd;
	char	*cmd_path;
	int		i;

	i = 1;
	while (++i < ac - 1)
	{
		cmd = ft_split(av[i], ' ');
		cmd_path = get_cmd_path(cmd, env);
		printf("%s \n", cmd_path);
		
	}
}

void	process_args(int ac, char **av, char **env)
{
	if (ft_strncmp(av[1], "here_doc", 8))
		process_here_doc(av[2]);
	else
		process_cmd(ac, av, env);
}

int	main(int ac, char **av, char **env)
{
	if (ac < 5)
	{
		ft_putendl_fd("\033[31m ERROR : number of arguments.", 2);
		exit (-1);
	}
	process_args(ac, av, env);
	return (0);
}
