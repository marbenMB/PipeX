/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 23:57:38 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/04/14 23:57:40 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int ac, char **av, char **env)
{
	if (ac < 5)
		error_args();
	if (ac >= 5 && env[0] != NULL)
		process_args(ac, av, env);
}

// TODO : Handle the env == NULL case && PATH not found
// TODO : Here_doc handling
