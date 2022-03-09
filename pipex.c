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

int	pipex(int ac, char **av, char **env)
{
	// Searching and geting the command
	char	**paths;
	char	*cmd_path;
	char	**cmd;
	int		i;

	if (!av[1] || !av[1][0])
		return(-5);
	i = -1;
	while (!ft_strnstr(env[++i], "PATH=", 5) && env[i])
		;
	env[i] = &env[i][5];
	paths = ft_split(env[i], ':');
	i = -1;
	cmd = ft_split(av[1], ' ');
	while (paths[++i])
	{
		cmd_path = ft_strjoin(paths[i], "/");
		cmd_path = ft_strjoin(cmd_path, cmd[0]);
		if (access(cmd_path, X_OK) == 0)
			break;
	}
	printf("%s\n", cmd_path);

	// Forking to child process
	int		id;

	id = fork();
	if (id < 0)
		fork();
	else if (id == 0)
	{
		printf("-----\nChild id : %d\n-----\n", id);
		execve(cmd_path, cmd, env);
		return (access(cmd_path, X_OK));
	}
	wait(NULL);
	printf("-----\nParent id : %d\n-----\n", id);
	return (access(cmd_path, X_OK));
}
