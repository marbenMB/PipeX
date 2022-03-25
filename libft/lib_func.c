/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 16:32:42 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/03/13 16:32:45 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (n)
	{
		while (*str1 == *str2 && --n)
		{
			if (!*str1 || !*str2)
				return (*str1 - *str2);
			str1++;
			str2++;
		}
		return (*str1 - *str2);
	}
	return (0);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
	{
		while (*s)
		{
			ft_putchar_fd(*s, fd);
			s++;
		}
	}
}

void	ft_putendl_fd(char *s, int fd)
{
	if (s)
		ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}
