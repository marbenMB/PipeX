#include "pipex_bonus.h"

char	**get_cmd_path(int ac, char **av, char **env)
{
	int		i[3];
	char	**paths;
	char	**cmd_path;
	char	**cmd;

	if (env[0])
	{
		i[0] = -1;
		while (!ft_strnstr(env[++i[0]], "PATH=", 5))
			;
	}
	if (env[i[0]])
	{
		env[i[0]] = &env[i[0]][5];
		paths = ft_split(env[i[0]], ':');
		
		
		cmd_path = (char **)malloc(sizeof(char **) * (ac - 3 + 1));
		if (!cmd_path)
			return (NULL);
		i[1] = 1;
		i[2] = 0;
		while (++i[1] < ac - 1)
		{
			i[0] = -1;
			while (paths[++i[0]])
			{
				cmd = ft_split(av[i[1]], ' ');
				cmd_path[i[2]] = ft_strjoin(paths[i[0]], "/");
				cmd_path[i[2]] = ft_strjoin(cmd_path[i[2]], cmd[0]);

				if (access(cmd_path[i[2]], X_OK) == 0)
					break;
			}
			if (cmd_path[i[2]] == NULL)
				return (NULL);
			i[2]++;
		}
	}
	cmd_path[i[2]] = NULL;
	return (cmd_path);
}

void	cmd_exec(int ac, char **cmd_paths, char **av, char **env)
{
	int		i;
	int		fides[2];
	pid_t	id;
	char	*cmd;
	int		pip;
	int		pip_fd[2];

	if((fides[0] = open(av[1], O_RDONLY, 0777) < 0) || \
		(fides[1] = open(av[ac - 1], O_WRONLY, O_CREAT, O_TRUNC, 0777) < 0))
		exit(-1);
	i = 1;
	while (++i < ac - 1)
	{
		if (id = fork() == -1)
			id = fork();
		if (i == 2)
			dup2(fides[0], 0);
		else if (i > 2)
			dup2(pip_fd[0], 0);
		else if (i = ac - 2)
			dup2(fides[1], 1);
		if (pip = pipe(pip_fd) == -1)
			pip = pipe(pip_fd);
		if (i > 2 && i < ac - 2)
			dup2(pip_fd[1], 1);

	}
}