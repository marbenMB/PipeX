/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 00:05:34 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/04/12 00:07:42 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	process_execution(t_cmd_pack *cmd_pack, int ac, char **av, char **env)
{
	if (!ft_strncmp(av[1], "here_doc", 8))
		execute_here_doc(cmd_pack, ac, av, env);
	else
		execute_cmd(cmd_pack, ac, av, env);
}

void	process_cmd(int fd[2], int ac, char **av, char **env)
{
	t_cmd_pack	*cmd_pack;
	int			j;

	j = -1;
	cmd_pack = get_cmd_pack(ac, av, env);
	while (++j < ac - 3)
	{
		cmd_pack[j].in_fd = fd[0];
		cmd_pack[j].out_fd = fd[1];
	}
	process_execution(cmd_pack, ac, av, env);
	free_struct(cmd_pack, ac - 4);
}

void	process_here_doc(int ac, char **av, char **env)
{
	int			idx;
	t_cmd_pack	*cmd_pack;

	idx = 2;
	while (++idx < ac)
	{
		if (!av[idx] || av[idx][0] == 0)
			error_fill_arg(av[idx]);
		if (!ft_strncmp(av[idx], " ", 2))
			error_fill_arg(av[idx]);
	}
	cmd_pack = get_cmd_pack(ac, av, env);
	process_execution(cmd_pack, ac, av, env);
	free_struct(cmd_pack, ac - 5);
}

void	process_args(int ac, char **av, char **env)
{
	int	idx;
	int	fd[2];

	if (!ft_strncmp(av[1], "here_doc", 8))
		process_here_doc(ac, av, env);
	else
	{
		idx = 0;
		while (++idx < ac)
		{
			if (!av[idx] || av[idx][0] == 0)
				error_fill_arg(av[idx]);
			if (!ft_strncmp(av[idx], " ", 2))
				error_fill_arg(av[idx]);
		}
		fd[0] = open(av[1], O_RDONLY, 0666);
		if (fd[0] < 0)
			error_files();
		fd[1] = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0666);
		if (fd[1] < 0)
			error_files();
		process_cmd(fd, ac, av, env);
	}
}
