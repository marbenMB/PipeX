/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:38:04 by mbenbajj          #+#    #+#             */
/*   Updated: 2021/11/25 05:47:32 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}

int	ft_tab_count(char *s, char c)
{
	int	i;

	i = 0;
	while (*s)
	{
		if (*s != c && s[1] == c)
			i++;
		s++;
	}
	if (*(s - 1) != c)
		i++;
	return (i + 1);
}

int	ft_char_count(char *s, char c)
{
	int	i;

	i = -1;
	while (s[++i] != c && s[i])
		;
	return (i++);
}

char	**ft_fill(char *s, char c)
{
	int		nb_tab;
	int		nb_char;
	char	**tab;
	int		i;

	if (!s)
		return (NULL);
	nb_tab = ft_tab_count((char *)s, c);
	tab = (char **)malloc(sizeof(char *) * nb_tab);
	if (!tab)
		return (NULL);
	i = 0;
	while (*s && i < nb_tab - 1)
	{
		nb_char = ft_char_count((char *)s, c);
		tab[i] = (char *)malloc(sizeof(char) * nb_char + 1);
		if (!tab[i])
			return (ft_free(tab), NULL);
		ft_strlcpy(tab[i], (char *)s, nb_char + 1);
		s += nb_char;
		while (*s == c)
			s++;
		i++;
	}
	return (tab[i] = NULL, tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;

	if (s)
	{
		if (*s == '\0' && c == 0)
		{
			tab = (char **)malloc(sizeof(char *));
			tab[0] = NULL;
			return (tab);
		}
		else if (c == 0)
		{
			tab = (char **)malloc(sizeof(char *) * 2);
			if (!tab)
				return (NULL);
			tab[0] = ft_strdup(s);
			return (tab[1] = NULL, tab);
		}
		while (*s == c)
			s++;
		tab = ft_fill((char *)s, c);
		return (tab);
	}
	return (NULL);
}
