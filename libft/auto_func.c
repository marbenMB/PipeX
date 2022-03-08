#include "../pipex.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = -1;
	if (!s)
		return (-1);
	while (s[++i])
		;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	s_len;
	int		dst_s;
	int		i;

	s_len = ft_strlen(src);
	dst_s = (int)dstsize;
	i = 0;
	if (dst_s)
	{
		while (src[i] && --dst_s)
		{
			*dst++ = src[i++];
		}
		*dst = '\0';
	}
	return (s_len);
}

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	len;
	size_t	i;

	str = (char *)s1;
	len = ft_strlen(s1);
	str = (char *)malloc((len + 1) * sizeof(char));
	i = 0;
	if (!str)
		return (NULL);
	while (i < len && *s1)
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}


char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		i;
	int		n;

	i = 0;
	if (!(*(char *)needle))
		return ((char *)haystack);
	while (*(char *)haystack && len)
	{
		n = len;
		if ((char)haystack[i] == (char)needle[i])
		{
			while (haystack[i] == needle[i] && (char)needle[i] && n)
			{
				i++;
				n--;
			}
		}
		if ((char)needle[i] == '\0')
			return ((char *)haystack);
		i = 0;
		haystack++;
		len--;
	}
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*n_str;
	size_t	len;
	size_t	i;

	if (s1 && s1)
	{
		len = ft_strlen(s1) + ft_strlen(s2) + 1;
		n_str = (char *)malloc(len * sizeof(char));
		if (!n_str)
			return (0);
		i = 0;
		while (i <= ft_strlen(s1) && s1[i])
		{
			n_str[i] = s1[i];
			i++;
		}
		while (i <= len && *s2)
			n_str[i++] = *s2++;
		n_str[i] = '\0';
		return (n_str);
	}
	return (NULL);
}