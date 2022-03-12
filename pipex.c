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

// TODO : add functions : get_path_cmd , func_exec && handle the right form of argument to the program

char	*get_cmd_path(char *av, char **env)
{
	int		i;
	char	**paths;
	char	*cmd_path;
	char	**cmd;

	i = -1;
	while(!ft_strnstr(env[++i], "PATH=", 5) && env[i])
		;
	env[i] = &env[i][5];
	paths = ft_split(env[i], ':');
	cmd = ft_split(av, ' ');
	i = -1;
	while(paths[++i] != NULL)
	{
		cmd_path = ft_strjoin(paths[i], "/");
		cmd_path = ft_strjoin(cmd_path, cmd[0]);
		if (access(cmd_path, X_OK) == 0)
			return (cmd_path);
	}
	return (NULL);
}

void	cmd_exec(int fd, char *cmd_path, char *av, char **env)
{
	char	**cmd;
	pid_t	id;

	cmd = ft_split(av, ' ');
	fd = dup2(fd, 0);
	id = fork();
	if (id < 0)
		fork();
	if (id == 0)
		execve(cmd_path, cmd, env);
	wait(NULL);
}

void	pipex(int ac, char **av, char **env)
{
	char	*cmd_path;
	int 	fd;

	if (!av[2] || !av[2][0] || !env)
	{
		if (!av[2] || !av[2][0])
		ft_putendl_fd("\033[31m ** CMD : No such command", 2);
		return ;
	}
	cmd_path = get_cmd_path(av[2], env);
	fd = open(av[1], O_RDONLY);
	if (cmd_path == NULL || fd < 0)
	{
		if (fd < 0)
			ft_putendl_fd("\033[31m ** FILE : No such file or directory", 2);
		else if (!cmd_path)
			ft_putendl_fd("\033[31m ** CMD : No such file or directory", 2);
		return ;
	}
	else if (cmd_path)
	{
		//printf("%s\n", cmd_path);
		cmd_exec(fd, cmd_path, av[2], env);
	}

}