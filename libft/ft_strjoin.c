/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 20:31:30 by mbenbajj          #+#    #+#             */
/*   Updated: 2021/11/14 16:05:46 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*n_str;
	size_t	len;
	size_t	i;

	if (s1 && s1)
	{
		len = ft_strlen(s1) + ft_strlen(s2) + 1;
		n_str = (char *)malloc(len * sizeof(char));
		if (!n_str)
			return (0);
		i = 0;
		while (i <= ft_strlen(s1) && s1[i])
		{
			n_str[i] = s1[i];
			i++;
		}
		while (i <= len && *s2)
			n_str[i++] = *s2++;
		n_str[i] = '\0';
		return (n_str);
	}
	return (NULL);
}
