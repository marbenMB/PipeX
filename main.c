#include "pipex.h"

int main(int ac, char **av, char **env)
{
	printf("%d\n", pipex(ac, av, env));
	return (0);
}
