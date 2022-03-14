/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 09:04:03 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/03/09 09:04:06 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// TODO : add functions : get_path_cmd
// func_exec && handle the right form of argument to the program

char	**get_cmd_path(char **av, char **env)
{
	int		i;
	char	**paths;
	char	**cmd_path;
	char	**cmd_1;
	char	**cmd_2;

	i = -1;
	while(!(ft_strnstr(env[++i], "PATH=", 5)) && env[i])
		;
	env[i] = &env[i][5];
	paths = ft_split(env[i], ':');
	cmd_1 = ft_split(av[2], ' ');
	cmd_2 = ft_split(av[3], ' ');
	i = -1;

	cmd_path = malloc(sizeof(char **) * 2);
	i = -1;
	while(paths[++i])
	{
		cmd_path[0] = ft_strjoin(paths[i], "/");
		cmd_path[0] = ft_strjoin(cmd_path[0], cmd_1[0]);
		if (access(cmd_path[0], X_OK) == 0)
			break;
		
	}
	i = -1;
	while (paths[++i])
	{
		cmd_path[1] = ft_strjoin(paths[i], "/");
		cmd_path[1] = ft_strjoin(cmd_path[1], cmd_2[0]);
		if (access(cmd_path[1], X_OK) == 0)
			break;
	}
	return (cmd_path);
}

void	cmd_exec(int fides[2], char **cmd_paths, char **av, char **env)
{
	char	**cmd;
	pid_t	id;
	int		pip;
	int		fd[2];

	cmd = ft_split(av[2], ' ');
	pip = pipe(fd);
	id = fork();
	if (id < 0)
		fork();
	if (id == 0)
	{
		fides[0] = dup2(fides[0], 0);
		fd[1] = dup2(fd[1], 1);
		execve(cmd_paths[0], cmd, env);
	}

	//  ** Forking for second time 

	int		out_fd;
	
	cmd = ft_split(av[3], ' ');
	if (id != 0)
		id = fork();
	if (id == 0)
	{
		fides[1] = dup2(fides[1], 1);
		execve(cmd_paths[1], cmd, env);
	}
	wait(NULL);
}

void	pipex(int ac, char **av, char **env)
{
	int		fd[2];
	char	**cmd_paths;

	if (!av[2] || !av[2][0] || !env)
	{
		if (!av[2] || !av[2][0])
			ft_putendl_fd("\033[31m ** CMD : No such command", 2);
		return ;
	}
	fd[0] = open(av[1], O_RDONLY);
	fd[1] = open(av[ac - 1], O_RDONLY);
	cmd_paths = get_cmd_path(av, env);
	if (cmd_paths[0] == NULL || cmd_paths[1] == NULL || fd < 0)
	{
		if (fd < 0)
			ft_putendl_fd("\033[31m ** FILE : No such file or directory", 2);
		else if (!cmd_paths)
			ft_putendl_fd("\033[31m ** CMD : No such file or directory", 2);
		return ;
	}
	else if (cmd_paths)
	{
		cmd_exec(fd, cmd_paths, av, env);
	}
}
