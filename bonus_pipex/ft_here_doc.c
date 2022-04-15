/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_here_doc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 14:55:09 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/04/15 14:55:10 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_dup_here_doc(t_cmd_pack *cmd_pack, int idx, int fd, int ac)
{
	dup2(cmd_pack->in_fd, 0);
	if (idx == ac - 5)
		dup2(cmd_pack->out_fd, 1);
	else
		dup2(fd, 1);
}

void	start_here_doc(int fd[2], int ac, char **av, char **env)
{
	char	*trim;
	char	*line;

	while (1)
	{
		write(1, "pipe heredoc> ", 14);
		trim = get_next_line(0);
		line = ft_strtrim(trim, "\n");
		free(trim);
		if (ft_strcmp(av[2], line) == 0)
		{
			free(line);
			break ;
		}
		ft_putendl_fd(line, fd[1]);
		free(line);
	}
	close(fd[1]);
}

void	start_execute_cmd(t_cmd_pack *cmd_pack, int ac, char **av, char **env)
{
	int		idx;
	int		*fd;
	int		id;

	idx = -1;
	fd = (int *)malloc(sizeof(int) * 2);
	if (!fd)
		error();
	while (++idx < ac - 4)
	{
		ft_pip(&fd);
		id = ft_fork();
		if (id == 0)
		{
			ft_dup_here_doc(cmd_pack, idx, fd[1], ac);
			close(fd[1]);
			execve(cmd_pack[idx].cmd_path, cmd_pack[idx].cmd, env);
		}
		cmd_pack->in_fd = fd[0];
		close(fd[1]);
	}
	free(fd);
	waitpid(id, NULL, 0);
}
