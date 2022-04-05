/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 08:53:46 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/03/21 08:53:50 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

//	includes :
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>

//	Structures :
typedef struct s_cmd_pack
{
	char	**cmd;
	char	*cmd_path;
}	t_cmd_pack;

//	Functions :

	//***	Libft:	******************************************** //
int	ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

	//***	Pipex :	******************************************** //
void	pipex(int ac, char **av, char **env);

		//***	Process functions :	**************************** //
void	process_args(int ac, char **av, char **env);
void	process_cmd(int ac, char **av, char **env);
void	process_here_doc(int ac, char **av, char *env[]);

		//***	Utils functions :	**************************** //
char	**fill_cmd_tab(int ac, char **paths, char **cmd_path,char **av);
char	**get_cmd_path(int ac, char **av, char **env);
void	exec_cmd(char *cmd_path, char **cmd, char **env);

#endif
