#include "get_next_line.h"

static char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	size_t	slen;

	if (!s)
		return (NULL);
	i = 0;
	slen = ft_strlen(s);
	while (i < slen + 1)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}

static void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	char	*str;
	int		i;

	i = 0;
	ptr = (void *)malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	str = (char *)ptr;
	while (i < nmemb * size)
	{
		str[i] = 0;
		i++;
	}
	return (ptr);
}

char	*read_line(int fd, char *keep)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*text;
	char	*tmp;
	size_t	i;
	size_t	k;

	i = 1;
	if (!ft_strchr(keep, '\n'))
	{
		
	}
	else
	{
		split_line();
	}

	
	// while (!ft_strchr(keep, '\n'))
	// {
	// 	text = ft_calloc((i++ * (BUFFER_SIZE) + 1), 1);
	// 	read(fd, buffer, BUFFER_SIZE);
	// 	ft_strjoin(text, buffer);
	// }
	
	return (tmp);
}

char	*split_line(int fd, char *keep)
{

}

char	*get_next_line(int fd)
{
	static char	*keep;
	char	buffer[BUFFER_SIZE + 1];
	char	*newline;
	ssize_t	bytes;

	if (ft_strchr(keep, '\n'))
		split_line(fd, keep, newline);
	else
		read_line(fd, keep);
	return (text);
}