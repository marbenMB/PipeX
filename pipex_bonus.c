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
/* 
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
			exit(-1);
		}
		idx[2]++;
	}
	cmd_path[idx[2]] = NULL;
	return (cmd_path);
}

char	**get_cmd_path(t_cmd_pack **cmd_pack ,int ac, char **av, char **env)
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
		cmd_pack = fill_cmd_tab(ac, paths, cmd_pack, av);
	}
	return (cmd_path);
} */

t_cmd_pack	*fill_cmd(char **paths, t_cmd_pack *cmd_pack, int ac, char **av)
{
	int		idx[3];
	char	*join;
	int		index;
	idx[1] = 2;
	idx[2] = 0;
	index = 0;
	while (idx[1] < ac - 1)
	{
		
		cmd_pack[idx[2]].cmd = ft_split(av[idx[1]], ' ');
		if (cmd_pack[idx[2]].cmd[0] == NULL)
		{
			ft_putendl_fd("\033[31m ** CMD : No such command", 2);
			exit(-1);
		}
		idx[0] = -1;
		while (paths[++idx[0]])
		{
			join = ft_strjoin(paths[idx[0]], "/");
			cmd_pack[idx[2]].cmd_path = ft_strjoin(join, cmd_pack[idx[2]].cmd[0]);
			printf("************ %s\n", cmd_pack[idx[2]].cmd_path);
			index = access(cmd_pack[idx[2]].cmd_path, X_OK);
			if (index == 0)
				break;
			free(cmd_pack[idx[2]].cmd_path);
			free(join);
		}
		if (index != 0)
		{
			ft_putendl_fd("\033[31m ** CMD9 : No such command", 2);
			exit(-1);
		}
		idx[2]++;
	}
	cmd_pack[idx[2]].cmd = NULL;
	cmd_pack[idx[2]].cmd_path = NULL;
	return (cmd_pack);
}

t_cmd_pack	*get_path(t_cmd_pack *cmd_pack, int ac, char **av, char **env)
{
	int		idx;
	char	**paths;

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
		cmd_pack = fill_cmd(paths,  cmd_pack, ac, av);
	}
	return (cmd_pack);
}


void	process_here_doc(int ac, char **av, char *env[])
{
	
}

void	process_cmd(int ac, char **av, char **env)
{
	t_cmd_pack	*cmd_pack;
	int		i;

	i = -1;
	cmd_pack = (t_cmd_pack *)malloc(sizeof(t_cmd_pack));
	if (!cmd_pack)
		exit(-1);
	cmd_pack = get_path(cmd_pack, ac, av, env);
	printf("/*************************/\n");
	while (cmd_pack[++i].cmd_path)
		printf("%s\n", cmd_pack[i].cmd_path);
	printf("/*************************/\n");

}

void	process_args(int ac, char **av, char **env)
{
	if (!ft_strncmp(av[1], "here_doc", 8))
		process_here_doc(ac, av, env);
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
