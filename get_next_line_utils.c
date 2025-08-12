#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char			*d;
	const unsigned char		*s;
	size_t					i;

	d = (unsigned char *)dest;
	s = (unsigned const char *)src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1len;
	size_t	s2len;
	char	*news;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	news = (char *)malloc(s1len + s2len + 1);
	if (news == NULL)
		return (NULL);
	ft_memcpy(news, s1, s1len);
	ft_memcpy(news + s1len, s2, s2len);
	news[s1len + s2len] = '\0';
	return (news);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	slen;
	size_t	actuallen;

	if (s == NULL)
		return (NULL);
	slen = ft_strlen(s);
	if (start >= slen)
		actuallen = 0;
	else
	{
		if (len + start > slen)
			actuallen = slen - start;
		else
			actuallen = len;
	}
	substr = (char *)malloc(actuallen + 1);
	if (substr == NULL)
		return (NULL);
	ft_memcpy(substr, s + start, actuallen);
	substr[actuallen] = '\0';
	return (substr);
}
char	*ft_strdup(const char *s)
{
	int		len;
	char	*dest;
	int		i;

	len = ft_strlen(s);
	dest = malloc(len + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}