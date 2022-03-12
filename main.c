/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 09:03:52 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/03/09 09:07:53 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **env)
{
	if (ac != 5)
	{
		ft_putendl_fd("\033[31m Execution syntax : ./pipex infile \"cmd_1\" \"cmd_2\" outfile", 2);
		return(0);
	}
	pipex(ac, av, env);
	return (0);
}
