/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 18:39:33 by mbenbajj          #+#    #+#             */
/*   Updated: 2021/12/26 00:40:20 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

size_t	str_len_ft(char *s, char c)
{
	size_t	i;

	i = -1;
	while (s[++i] != c && s[i])
		;
	return (i);
}

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

int	ft_srh(char *str, int start)
{
	int	i;

	i = --start;
	while (str[++i])
	{
		if (str[i] == '\n')
			return (-1);
	}
	return (0);
}

char	*ft_join(char *s1, char *s2)
{
	char	*new_str;
	size_t	big_len;
	size_t	s1_len;
	size_t	i;

	if (!s2)
		return (NULL);
	s1_len = str_len_ft(s1, '\0');
	big_len = s1_len + str_len_ft(s2, '\0') + 1;
	new_str = (char *)malloc(sizeof(char) * big_len);
	if (!new_str)
		return (free(s2), NULL);
	i = 0;
	while (s1[i])
	{
		new_str[i] = s1[i];
		i++;
	}
	while (*s2)
	{
		new_str[i] = *s2++;
		i++;
	}
	new_str[i] = '\0';
	return (free(s1), new_str);
}

char	*ft_rest(char *buffer_static)
{
	char	*str;
	int		index;
	int		jdx;
	int		len;

	index = str_len_ft(buffer_static, '\n');
	if (!buffer_static[index])
		return (free(buffer_static), NULL);
	len = str_len_ft(buffer_static, '\0') - index + 1;
	str = (char *)ft_calloc(sizeof(char), len);
	index++;
	jdx = 0;
	while (buffer_static[index])
		str[jdx++] = buffer_static[index++];
	return (free(buffer_static), str);
}
