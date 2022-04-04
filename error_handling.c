#include "pipex_bonus.h"

void	file_opening(int fd)
{
	if (fd < 0)
	{
		ft_putendl_fd("\033[31m ** FILE : No such file or directory", 2);
		exit(-1);
	}
}