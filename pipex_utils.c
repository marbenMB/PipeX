
#include "pipex.h"

t_cmd_pack  *fill_cmd_pack(t_cmd_pack *cmd_pack, char **paths, int ac, char **av)
{
    int     idx[3];
    char    *str;

    idx[1] = 1;
    idx[2] = -1;
    while (++idx[1] < ac - 1)
    {
        cmd_pack[++idx[2]].cmd = ft_split(av[idx[1]], ' ');
        idx[0] = -1;
        while (paths[++idx[0]])
        {
            str = ft_strjoin(paths[idx[0]], "/");
            cmd_pack[idx[2]].cmd_path = ft_strjoin(str, cmd_pack[++idx[2]].cmd[0]);
            free(str);
            if (!access(cmd_pack[idx[2]].cmd_path, X_OK))
                break ;
        }
        if (access(cmd_pack[idx[2]].cmd_path, X_OK))
            error_cmd(av[idx[1]], cmd_pack);
    }
}

t_cmd_pack  *get_cmd_pack(t_cmd_pack *cmd_pack, int ac, char **av, char **env)
{
    int     idx;
    char    **paths;

    idx = -1;
    while (!ft_strnstr(env[++idx], "PATH=", 5))
        ;
    paths = ft_split(env[idx][5], ':');
    cmd_pack = fill_cmd_pack(cmd_pack, paths, ac, av);
    
}