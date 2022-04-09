
#ifndef PIPEX_H
# define PIPEX_H

//  includes : 
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>

//  Structures :
typedef struct s_cmd_pack
{
    char **cmd;
    char *cmd_path;
}   t_cmd_pack;

//	functions :
//	**********  libft :
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int	    ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strrchr(const char *s, int c);

//	**********  Processing functions :
void    process_args(int ac, char **av, char **env);
void    process_cmd(int fd[2], int ac, char **av, char **env);
//	**********  Error handling :
void    error_args();
void    error_files();
void    error_fill_arg(char *str);
void    error_cmd(char *arg, t_cmd_pack *cmd_pack, int idx);
//	**********  Pipex Utils :
void	free_struct(t_cmd_pack *cmd_pack, int idx);
t_cmd_pack  *fill_cmd_pack(t_cmd_pack *cmd_pack, char **paths, int ac, char **av);
t_cmd_pack  *get_cmd_pack(int ac, char **av, char **env);
#endif
