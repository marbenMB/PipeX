
#ifndef	PIPEX_BONUS_H
# define PIPEX_BONUS_H

//	includes :
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>

//	functions :
	//	libft:
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
	//	pipex :
void	pipex(int ac, char **av, char **env);
char	**get_cmd(int ac, char **av, char **env);
//char	*get_cmd_path(char *av, char **env);
void	cmd_exec(int ac, char **cmd_paths, char **av, char **env);
char	**get_cmd_path(int ac, char **av, char **env);

#endif