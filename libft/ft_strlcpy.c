/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:47:05 by mbenbajj          #+#    #+#             */
/*   Updated: 2021/11/13 18:43:51 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	s_len;
	int		dst_s;
	int		i;

	s_len = ft_strlen(src);
	dst_s = (int)dstsize;
	i = 0;
	if (dst_s)
	{
		while (src[i] && --dst_s)
		{
			*dst++ = src[i++];
		}
		*dst = '\0';
	}
	return (s_len);
}
