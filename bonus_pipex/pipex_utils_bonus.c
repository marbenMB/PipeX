/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 00:16:31 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/04/12 00:18:22 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	free_tab(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}

void	free_struct(t_cmd_pack *cmd_pack, int idx)
{
	int	i;

	i = -1;
	while (++i <= idx)
	{
		free_tab(cmd_pack[i].cmd);
		free(cmd_pack[i].cmd_path);
	}
	free(cmd_pack);
}

char	*get_cmd_path(char *cmd_path, char *cmd, char **paths)
{
	char	*str;
	int		idx;

	idx = -1;
	while (paths[++idx])
	{
		str = ft_strjoin(paths[idx], "/");
		cmd_path = ft_strjoin(str, cmd);
		free(str);
		if (!access(cmd_path, X_OK))
			break ;
		free(cmd_path);
	}
	return (cmd_path);
}

t_cmd_pack	*fill_cmd_pack(t_cmd_pack *cmd_pack, \
			char **paths, int ac, char **av)
{
	int		idx[2];
	char	*str;

	if (!ft_strncmp(av[1], "here_doc", 8))
		idx[0] = 2;
	else
		idx[0] = 1;
	idx[1] = -1;
	while (++idx[0] < ac - 1)
	{
		if (av[idx[0]][0] == '/')
		{
			cmd_pack[++idx[1]].cmd = ft_split(av[idx[0]], ' ');
			cmd_pack[idx[1]].cmd_path = ft_strdup(cmd_pack[idx[1]].cmd[0]);
		}
		else
		{
			cmd_pack[++idx[1]].cmd = ft_split(av[idx[0]], ' ');
			cmd_pack[idx[1]].cmd_path = get_cmd_path(cmd_pack[idx[1]].cmd_path, \
										cmd_pack[idx[1]].cmd[0], paths);
		}
		if (access(cmd_pack[idx[1]].cmd_path, X_OK))
			error_cmd(av[idx[0]], cmd_pack, idx[1]);
	}
	return (cmd_pack);
}

t_cmd_pack	*get_cmd_pack(int ac, char **av, char **env)
{
	int			idx;
	char		**paths;
	t_cmd_pack	*cmd_pack;

	cmd_pack = (t_cmd_pack *)malloc(sizeof(t_cmd_pack) * ac - 3);
	if (!cmd_pack)
		error();
	idx = -1;
	while (!ft_strnstr(env[++idx], "PATH=", 5) && env[idx])
		;
	if (env[idx] == NULL)
		error();
	paths = ft_split(&env[idx][5], ':');
	cmd_pack = fill_cmd_pack(cmd_pack, paths, ac, av);
	free_tab(paths);
	return (cmd_pack);
}
