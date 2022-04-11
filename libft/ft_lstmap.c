/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 03:15:29 by mbenbajj          #+#    #+#             */
/*   Updated: 2021/11/22 22:52:54 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*n_lst;
	t_list	*x_lst;
	void	*c;

	if (!f && !del)
		return (NULL);
	x_lst = NULL;
	while (lst)
	{
		c = (*f)(lst -> content);
		n_lst = ft_lstnew(c);
		if (!n_lst)
		{
			ft_lstclear(&x_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&x_lst, n_lst);
		lst = lst -> next;
	}
	return (x_lst);
}
