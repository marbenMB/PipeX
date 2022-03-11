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

char	**get_cmd(int ac, char **av, char **env)
{
	char	**paths;
	char	*cmd_path;
	char	**cmd;
	int		i;

	if (!av[1] || !av[1][0])
		return(NULL);
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
		{
			cmd[2] = cmd_path;
			cmd[3] = NULL;
			return (cmd);
		}
	}
	return (NULL);
}

void	pipex(int ac, char **av, char **env)
{
	int		id;
	char	**cmd;
	char 	*cmd_path;

	cmd = get_cmd(ac, av, env);
	cmd_path = cmd[2];
	cmd[2] = NULL;
	if (cmd)
	{
		id = fork();
		if (id < 0)
			fork();
		else if (id == 0)
			execve(cmd_path, cmd, env);
		wait(NULL);
	}
}
