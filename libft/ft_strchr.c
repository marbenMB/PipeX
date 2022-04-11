/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:48:41 by mbenbajj          #+#    #+#             */
/*   Updated: 2021/11/10 22:36:22 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{	
	if (c != 0)
	{
		while (*s)
		{
			if (*s == (char )c)
				return ((char *)s);
			s++;
		}
		return (NULL);
	}
	return ((char *)(s + ft_strlen(s)));
}
