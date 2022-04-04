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

char	**fill_cmd_tab(int ac, char **paths, char **cmd_path,char **av)
{
	int		idx[3];
	char	**cmd;

	idx[1] = 1;
	idx[2] = 0;
	while (++idx[1] < ac - 1)
	{
		idx[0] = -1;
		while (paths[++idx[0]] && !(!av[idx[1]] || !av[idx[1]][0]))
		{
			cmd = ft_split(av[idx[1]], ' ');
			if (cmd[0] == NULL)
			{
				ft_putendl_fd("\033[31m ** CMD : No such command", 2);
				//	free the biggest table
				exit(-1);
			}
			cmd_path[idx[2]] = ft_strjoin(paths[idx[0]], "/");
			cmd_path[idx[2]] = ft_strjoin(cmd_path[idx[2]], cmd[0]);
			if (access(cmd_path[idx[2]], X_OK) == 0)
				break;
		}
		if (access(cmd_path[idx[2]], X_OK) != 0 || (!av[idx[1]] || !av[idx[1]][0]))
		{
			ft_putendl_fd("\033[31m ** CMD : No such command", 2);
			// free the smallest tables and the biggest too
			exit(-1);
		}
		idx[2]++;
	}
	cmd_path[idx[2]] = NULL;
	return (cmd_path);
}

char	**get_cmd_path(int ac, char **av, char **env)
{
	int		idx;
	char	**paths;
	char	**cmd_path;
	char	**cmd;

	if (env[0])
	{
		idx = -1;
		while (!ft_strnstr(env[++idx], "PATH=", 5))
			;
		paths = ft_split(&env[idx][5], ':');
		if (paths[0] == NULL)
		{
			ft_putendl_fd("\033[31m ** No such PATHS", 2);
			exit(-1);
		}
		cmd_path = (char **)malloc(sizeof(char **) * (ac - 2));
		if (!cmd_path)
			exit(-1);
		cmd_path = fill_cmd_tab(ac, paths, cmd_path, av);
	}
	return (cmd_path);
}

