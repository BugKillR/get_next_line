#include "get_next_line.h"

static char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	slen;
	size_t	i;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start >= slen)
		return (ft_strdup(""));
	if (start + len > slen)
		len = slen - start;
	substr = (char *)malloc(len + 1);
	if (!substr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

static void	ft_realloc(char **ptr1, char *ptr2)
{
	char	*temp;

	temp = ft_strjoin(*ptr1, ptr2);
	free(*ptr1);
	*ptr1 = temp;
}

static int ft_splitfromnew(char **text, char *newline, char **keep)
{
	char	*temp;

	*keep = ft_strdup(newline + 1);
	temp = ft_substr(*text, 0, newline - *text + 1);
	free(*text);
	*text = NULL;
	*text = temp;
	if (!*text || **text == '\0')
	{
		free(*text);
		return (0);
	}
	return (1);
}

#include <stdio.h>

char	*get_next_line(int fd)
{
	static char	*keep;
	char		*buffer;
	char		*text;
	char		*newline;
	ssize_t		bytes_read;

	if (fd < 0 || fd > 1023 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!keep)
		text = ft_strdup("");
	else
	{
		text = ft_strdup(keep);
		if (!text)
			return (free(keep), NULL);
	}
	if (keep && !*text)
		return (NULL);
	free(keep);
	while (!(newline = ft_strchr(text, '\n')))
	{
		buffer = ft_calloc(BUFFER_SIZE + 1, 1);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			return (free(buffer), free(text), free(keep), NULL);
		ft_realloc(&text, buffer);
		free(buffer);	
	}
	if(!ft_splitfromnew(&text, newline, &keep))
		return (free(keep), NULL);
	return (text);
}
