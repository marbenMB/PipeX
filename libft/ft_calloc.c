/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 16:29:35 by mbenbajj          #+#    #+#             */
/*   Updated: 2021/11/14 16:23:26 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;
	size_t	i;

	p = (void *)malloc(count * size);
	if (!p)
		return (NULL);
	i = 0;
	while (((char *)p) && i < count * size)
	{
		((char *)p)[i] = 0;
		i++;
	}
	return (p);
}
