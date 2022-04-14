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
	if (ac >= 5 && env[0] != NULL)
		process_args(ac, av, env);
}

// TODO : Handle the env == NULL case && PATH not found
// TODO : Here_doc handling
