#include "get_next_line.h"

static void	ft_realloc(char **ptr1, char *ptr2)
{
	char	*temp;
	size_t	i;

	i = 0;
	temp = ft_calloc(ft_strlen(*ptr1) + 1, 1);
	if (!temp)
		return ;
	while ((*ptr1)[i])
		temp[i++] = (*ptr1)[i];
	free(*ptr1);
	*ptr1 = ft_strjoin(temp, ptr2);
	free(temp);
}

static char	*read_line(int fd, char *keep, char **record)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*newline;
	ssize_t	bytes;

	if (keep)
		*record = ft_strdup(keep);
	else
		*record = ft_strdup("");
	newline = ft_strchr(*record, '\n');
	while (!newline)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes <= 0)
			break ;
		buffer[bytes] = '\0';
		ft_realloc(record, buffer);
	}
	return (newline);
}

static void	copy_record(char **text, char *record)
{
	size_t	i;

	i = 0;
	while (record[i] && record[i] != '\n')
		(*text)[i++] = record[i];
	(*text)[i++] = '\n';
	(*text)[i] = '\0';
}

char	*get_next_line(int fd)
{
	static char	*keep;
	char		*newline;
	char		*text;
	char		*record;
	size_t		i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	newline = read_line(fd, keep, &record);
	if (!record || !*record)
		return (free(record), NULL);
	if (!newline)
	{
		text = ft_strdup(record);
		free(keep);
		return (free(record), text);
	}
	text = ft_calloc((newline - record) + 2, 1);
	copy_record(&text, record);
	free(keep);
	if (!newline)
		keep = ft_strdup(newline + 1);
	return (free(record), text);
}
