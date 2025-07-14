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

void	read_line(int fd, char *keep, char *text)
{
	char	*record;
	char	buffer[BUFFER_SIZE + 1];
	size_t	len;
	size_t	i;

	i = 0;
	//if(keep)
	//	record = ft_strdup(keep);
	


	text = ft_calloc(ft_strlen(record) - (ft_strchr(record, '\n') - record), 1);
	while (record[i] && record[i] != '\n')
		text[i++] = record[i];
	text[i] = '\n';
	keep = ft_strdup(ft_strchr(record, '\n'));
	free(record);
}

char	*get_next_line(int fd)
{
	static char	*keep;
	char	*text;

	read_line(fd, keep, text);
	return (text);
}