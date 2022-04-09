
#include "pipex.h"

void	free_struct(t_cmd_pack *cmd_pack, int idx)
{
	int	i;
	int	j;

	i = -1;
	while (++i <= idx)
	{
		j = -1;
		while (cmd_pack[i].cmd[++j])
			free(cmd_pack[i].cmd[j]);
		free(cmd_pack[i].cmd_path);
	}
	free(cmd_pack);
}

t_cmd_pack  *fill_cmd_pack(t_cmd_pack *cmd_pack, char **paths, int ac, char **av)
{
    int     idx[3];
    char    *str;

    idx[1] = 1;
    idx[2] = -1;
    while (++idx[1] < ac - 1)
    {
		if (av[idx[1]][0] == '/')
		{
			if (!access(cmd_pack[idx[2]].cmd_path, X_OK))
			{
				// get command from the absolute path strrchr(/) + strtrim(/)
				cmd_pack[idx[2]].cmd_path = av[idx[1]];
                continue ;
			}
		}
		else
		{
			cmd_pack[++idx[2]].cmd = ft_split(av[idx[1]], ' ');
			idx[0] = -1;
			while (paths[++idx[0]])
			{
				str = ft_strjoin(paths[idx[0]], "/");
				cmd_pack[idx[2]].cmd_path = ft_strjoin(str, cmd_pack[idx[2]].cmd[0]);
				free(str);
				if (!access(cmd_pack[idx[2]].cmd_path, X_OK))
					break ;
				//free(cmd_pack[idx[2]].cmd_path);
			}
		}
        if (access(cmd_pack[idx[2]].cmd_path, X_OK))
            error_cmd(av[idx[1]], cmd_pack, idx[2]);
    }
	return (cmd_pack);
}

t_cmd_pack  *get_cmd_pack(int ac, char **av, char **env)
{
    int     idx;
    char    **paths;
	t_cmd_pack  *cmd_pack;

    cmd_pack = (t_cmd_pack *)malloc(sizeof(t_cmd_pack) * ac - 3);
    if (!cmd_pack)
        exit(-1);
    idx = -1;
    while (!ft_strnstr(env[++idx], "PATH=", 5))
        ;
    paths = ft_split(&env[idx][5], ':');
    cmd_pack = fill_cmd_pack(cmd_pack, paths, ac, av);
    return (cmd_pack);
}