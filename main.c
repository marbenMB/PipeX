/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 00:19:49 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/04/12 00:19:59 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **env)
{
	if (ac < 5)
		error_args();
	process_args(ac, av, env);
	//sleep(555);
	//system("leaks pipex");
}

// TODO : Forking -> Piping -> excuting 
// TODO : Here_doc handling
