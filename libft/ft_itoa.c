/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 21:13:37 by mbenbajj          #+#    #+#             */
/*   Updated: 2021/11/14 23:08:51 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	nbr_len(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i++;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		n_len;
	char	*n_str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	n_len = nbr_len(n) + 1;
	n_str = (char *)malloc(n_len * sizeof(char ));
	if (!n_str)
		return (NULL);
	else if (n < 0)
	{
		n_str[0] = '-';
		n = -n;
	}
	n_str[--n_len] = '\0';
	if (!n)
		n_str[0] = 48;
	while (n)
	{
		n_str[--n_len] = n % 10 + 48;
		n /= 10;
	}
	return (n_str);
}
