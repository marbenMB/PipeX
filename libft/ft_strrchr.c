/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 18:26:13 by mbenbajj          #+#    #+#             */
/*   Updated: 2021/11/07 17:35:39 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;

	len = ft_strlen((char *)s);
	if (c != 0)
	{
		while (*s && len--)
		{
			if (s[len] == (char )c)
				return ((char *)(s + len));
		}
		return (NULL);
	}
	return ((char *)s + len);
}
