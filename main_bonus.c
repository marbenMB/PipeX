/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 08:59:57 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/03/21 08:59:58 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int main(int ac, char **av, char **env)
{
    t_cmd_pack    **paths;
    int     i;

	if (ac < 5)
	{
		ft_putendl_fd("\033[31m ** Usage : infile cmd_1 ... cmd_n outfile", 2);
		exit(-1);
	}
    paths = get_cmd_path(ac, av, env);
    printf("/*****************************\\\n");
    i = 0;
    while (paths[i] != NULL)
	{
        printf("%s	-%s	:	%s  \n",paths[i]->cmd[0], paths[i]->cmd[1], paths[i]->cmd_path);
		i++;
	}
    printf("\\*****************************/\n");
    //cmd_exec(ac, paths, av, env);
    
    return (0);
}