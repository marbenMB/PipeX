
#include "pipex.h"

void    error_args()
{
    ft_putendl_fd("\033[31m ** USAGE : file1 cmd1 cmd2 ... cmdn file2\033[0m", 2);
    exit(-1);
}

void    error_files()
{
    ft_putendl_fd("\033[31m ** FILE : No such file\033[0m", 2);
    exit(-1);
}

void    error_fill_arg(char *str)
{
    ft_putstr_fd("\033[31m ** ARGS : argument error -> \033[0m", 2);
    if (str && str[0] && str[0] != ' ')
        write(2, str, ft_strlen(str));
    else
        write(2, "empty arg", 9);
    exit(-1);
}

void    error_cmd(char *arg, t_cmd_pack *cmd_pack, int idx)
{
    ft_putendl_fd("\033[31m ** CMD : No such command\033[0m", 2);
	//free_struct(cmd_pack, idx);
	//system("leaks pipex");
	exit(-1);
}