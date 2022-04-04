#include "pipex_bonus.h"

void	process_cmds(int ac, char **av, char **env)
{

}

void	process_here_doc(char **av, char **env)
{

}

void	process_files(int ac, char **av, char **env)
{
	int		fd;

	fd = open(av[1], O_RDONLY, 0666);
	file_opening(fd);
}

void	process_args(int ac, char **av, char **env)
{
	if (!ft_strncmp(av[1], "here_doc", 8))
		process_here_doc(av, env);
	else
		process_files(ac, av, env);
		
}