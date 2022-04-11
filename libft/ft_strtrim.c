/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 14:08:39 by mbenbajj          #+#    #+#             */
/*   Updated: 2021/11/13 18:39:53 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		i;
	int		j;
	char	*res;

	i = 0;
	j = 0;
	str = (char *)s1;
	if (!str)
		return (NULL);
	while (str[i] && ft_strchr(set, str[i]))
		i++;
	if (str[i] == '\0')
		return (ft_calloc(1, 1));
	j = ft_strlen(str) - 1;
	while (ft_strchr(set, str[j]))
		j--;
	j += 1;
	res = (char *)malloc((j - i + 1) * sizeof(char));
	if (!res)
		return (NULL);
	ft_strlcpy(res, &str[i], (j - i + 1));
	return (res);
}
