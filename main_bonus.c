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
    char    **paths;
    int     i;

    paths = get_cmd_path(ac, av, env);
    i = -1;
    while (++i < ac - 3)
        printf("%s  \n", paths[i]);
    printf("/*****************************\\\n");
    printf("\\*****************************/\n");
    //cmd_exec(ac, paths, av, env);
    
    return (0);
}