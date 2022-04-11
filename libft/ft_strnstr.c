/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 20:38:52 by mbenbajj          #+#    #+#             */
/*   Updated: 2021/11/06 17:48:37 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		i;
	int		n;

	i = 0;
	if (!(*(char *)needle))
		return ((char *)haystack);
	while (*(char *)haystack && len)
	{
		n = len;
		if ((char)haystack[i] == (char)needle[i])
		{
			while (haystack[i] == needle[i] && (char)needle[i] && n)
			{
				i++;
				n--;
			}
		}
		if ((char)needle[i] == '\0')
			return ((char *)haystack);
		i = 0;
		haystack++;
		len--;
	}
	return (NULL);
}
