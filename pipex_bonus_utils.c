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

/*	char	**fill_cmd_tab(int ac, char **paths, char **cmd_path,char **av)
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
} */

////////////////// ************************************* \\\\\\\\\\\\\\\\\\\\\\\

t_cmd_pack	**fill_struct(t_cmd_pack **cmd_pack, int ac, char **paths, char **av)
{
	int		av_dx;
	int		s_dx;
	int		p_dx;
	int		index;
	char	*str;

	av_dx = 2;
	s_dx = 0;
	index = 0;
	while (av_dx < ac - 1)
	{
		cmd_pack[s_dx] = (t_cmd_pack *)malloc(sizeof(t_cmd_pack));
		if (!cmd_pack[s_dx])
			exit(-1);
		cmd_pack[s_dx]->cmd = ft_split(av[av_dx], ' ');
		p_dx = -1;
		while (paths[++p_dx])
		{
			str = ft_strjoin(paths[p_dx], "/");
			cmd_pack[s_dx]->cmd_path = ft_strjoin(str, cmd_pack[s_dx]->cmd[0]);
			index = access(cmd_pack[s_dx]->cmd_path, X_OK);
			if (index == 0)
			{
				av_dx++;
				break;
			}
			else
			{
				free(str);
				free(cmd_pack[s_dx]->cmd_path);
			}
		}
		if (index != 0)
		{
			printf("---%s\n",cmd_pack[s_dx]->cmd[0]);
			printf("cmd not found !");
			exit(1);
		}
		s_dx++;
		
	}
	cmd_pack[s_dx] = NULL;
	while (index < ac - 3)
	{
		printf("cmd_pack[%d]->cmd_path = %s\n",index,cmd_pack[index]->cmd_path);
		index++;
	}
	printf("cmd done !");
	return (cmd_pack);
}

t_cmd_pack	**get_cmd_path(int ac, char **av, char **env)
{
	int		idx;
	char	**paths;
	t_cmd_pack	**cmd_pack;

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
		cmd_pack = (t_cmd_pack **)malloc(sizeof(t_cmd_pack *));
		if (!cmd_pack)
			exit(-1);
		cmd_pack = fill_struct(cmd_pack, ac, paths, av);
	}
	// while (*cmd_pack)
	// {
	// 	printf("cmd |%s\ncmd_path |%s\n", (*cmd_pack)->cmd, (*cmd_pack)->cmd_path);
	// 	cmd_pack++;
	// }
	return (cmd_pack);
}

//\\\\\\\\\\\\\\\\ ************************************* ///////////////////////

