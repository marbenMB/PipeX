#include "pipex.h"

void	ft_pip(int	**fd)
{
	int		pip;

	pip = pipe(*fd);
	if (pip < 0)
		exit (-1);
}

int		ft_fork(void)
{
	pid_t	id;

	id = fork();
	if (id < 0)
		exit (-1);
	return (id);
}

void	execute_cmd(t_cmd_pack *cmd_pack, int ac, char **av, char **env)
{
	int		idx;
	int		*fd;
	int		id;

	if (!ft_strncmp(av[1], "here_doc", 8))
		idx = 0;
	else
		idx = -1;
	fd = (int *)malloc(sizeof(int) * 2);
	while (++idx < ac - 3)
	{
		ft_pip(&fd);
		id = ft_fork();
		if (id == 0)
		{
			 execve(cmd_pack[idx].cmd_path, cmd_pack[idx].cmd, env);
		}
	}
	free(fd);
	system("leaks pipex");
	waitpid(id, NULL, 0);
}