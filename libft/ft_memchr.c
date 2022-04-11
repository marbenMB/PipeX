/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 20:27:49 by mbenbajj          #+#    #+#             */
/*   Updated: 2021/11/13 20:51:20 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	ch;
	unsigned char	*str;

	str = (unsigned char *)s;
	ch = (unsigned char )c;
	if (!n)
		return (NULL);
	while (*str != ch && --n)
		str++;
	if (*str == ch)
		return (str);
	return (NULL);
}
