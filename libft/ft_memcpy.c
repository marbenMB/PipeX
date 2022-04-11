/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 09:46:07 by mbenbajj          #+#    #+#             */
/*   Updated: 2021/11/11 15:54:06 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*str_s;
	char	*str_d;

	str_s = (char *)src;
	str_d = (char *)dst;
	if (!str_s && !str_d)
		return (NULL);
	while (n--)
		*str_d++ = *str_s++;
	return (dst);
}
