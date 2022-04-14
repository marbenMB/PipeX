/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 18:37:34 by mbenbajj          #+#    #+#             */
/*   Updated: 2021/12/22 21:02:19 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

// includes :
# include <stdlib.h>
# include <string.h>
# include <stddef.h>
# include <unistd.h>
# include <fcntl.h>

// functions :
size_t	str_len_ft(char *s, char c);
void	*ft_calloc(size_t count, size_t size);
int		ft_srh(char *str, int start);
char	*ft_join(char *s1, char *s2);
char	*ft_rest(char *str);
char	*ft_get_line(char *str);
char	*get_stc_buff(int fd, char *stc_buff);
char	*get_next_line(int fd);
#endif
