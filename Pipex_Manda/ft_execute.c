/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 00:59:05 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/04/14 00:59:08 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_pip(int	**fd)
{
	int		pip;

	pip = pipe(*fd);
	if (pip < 0)
		exit (-1);
}

int	ft_fork(void)
{
	pid_t	id;

	id = fork();
	if (id < 0)
		exit (-1);
	return (id);
}

void	ft_dup(t_cmd_pack *cmd_pack, int idx, int fd, int ac)
{
	dup2(cmd_pack->in_fd, 0);
	if (idx == ac - 4)
		dup2(cmd_pack->out_fd, 1);
	else
		dup2(fd, 1);
}

void	execute_cmd(t_cmd_pack *cmd_pack, int ac, char **av, char **env)
{
	int		idx;
	int		*fd;
	int		id;

	idx = -1;
	fd = (int *)malloc(sizeof(int) * 2);
	while (++idx < ac - 3)
	{
		ft_pip(&fd);
		id = ft_fork();
		if (id == 0)
		{
			ft_dup(cmd_pack, idx, fd[1], ac);
			close(fd[1]);
			execve(cmd_pack[idx].cmd_path, cmd_pack[idx].cmd, env);
		}
		cmd_pack->in_fd = fd[0];
		close(fd[1]);
	}
	free(fd);
	waitpid(id, NULL, 0);
}
