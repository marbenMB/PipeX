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

	i = -1;
	while (!(ft_strnstr(env[++i], "PATH=", 5)) && env[i])
		;
	env[i] = &env[i][5];
	path = ft_split(env[i], ':');
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

void	exec_cmd(int ac, char **av, char **env)
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

/* int	main(int ac, char **av, char **env)
{
	pid_t	id;
	int		pip;
	int		fd[2];

	if (ac != 5)
	{
		ft_putendl_fd("\033[31m ERROR : number of arguments.", 2);
		exit (-1);
	}
	id = fork();
	pip = pipe(fd);
	if (id < 0 || pip < 0)
	{
		ft_putendl_fd("\033[31m ERROR : Fork() or Pipe() problem", 2);
		exit (-1);
	}
	if (id == 0)
		exec_cmd(ac, av, env);
	if (id != 0)
		wait(NULL);
	return (0);
} */

