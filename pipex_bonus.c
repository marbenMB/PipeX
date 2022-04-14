#include "./Pipex_Utils_bonus/pipex_bonus.h"


int	main(int ac, char **av, char **env)
{
	if (ac < 5)
		error_args();
	if (ac >= 5 && env[0] != NULL)
		process_args(ac, av, env);
}

// TODO : Handle the env == NULL case && PATH not found
// TODO : Here_doc handling