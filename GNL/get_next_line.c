#include "get_next_line.h"
#include <stdio.h> // A ENLEVER

char *get_next_line(int fd)
{
	static char	*stash = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1)
		return (NULL);
	line = NULL;
	read_and_add(fd, &line, &stash);
	if (line[0] == '\0')
	{
		return (NULL);
	}
	return (line);
}

void	read_and_add(int fd, char **line, char **stash)
{
	int		readed;
	char	*buf;

	readed = 1;
	while (readed > 0 && !found_newline(*stash))
	{
		buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buf)
			return ;
		readed = read(fd, buf, BUFFER_SIZE);
		if (readed == -1)
		{
			free (buf);
			return ;
		}
		buf[readed] = '\0';
		(*stash) = ft_strjoin(*stash, buf);
		free (buf);
	}
	extract_line(*stash, line);
	clear_stash(stash);
}

int	found_newline(char *stash)
{
	int i;

	if (!stash)
		return (0);
	i = 0;
	while (stash[i])
	{
		if (stash[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char *ptr;
	char *current_ptr;
	char *previous;

	if (!s1 && !s2)
		return (NULL);
	else if (!s2)
		return (ft_strdup(s1));
	else if (!s1)
		return (ft_strdup(s2));
	ptr = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!ptr)
		return (NULL);
	current_ptr = ptr;
	previous = s1;
	while (*s1)
		*ptr++ = *s1++;
	while (*s2)
		*ptr++ = *s2++;
	*ptr = '\0';
	free_stash(previous);
	return (current_ptr);
}

void free_stash(char *stash)
{
    if (stash)
	{
        free(stash);
        stash = NULL;
    }
}

int	ft_strlen(char *str)
{
	int i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char *ft_strdup(char *str)
{
	char *ptr;
	char *current_ptr;

	ptr = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!ptr)
		return (NULL);
	current_ptr = ptr;
	while (*str)
		*ptr++ = *str++;
	*ptr = '\0';
	return (current_ptr);
}

void	extract_line(char *stash, char **line)
{
	int		i;
	char	*str;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return ;
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		str[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
	{
		str[i] = stash[i];
		i++;
	}
	str[i] = '\0';
	(*line) = ft_strjoin(*line, str);
	free (str);
}

void	clear_stash(char **stash)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	j = 0;
	while ((*stash)[i] && (*stash)[i] != '\n')
		i++;
	if ((*stash)[i] == '\n')
		i++;
	temp = malloc(sizeof(char) * (ft_strlen(*stash) - i + 1));
	if (!temp)
		return ;
	while ((*stash)[i])
		temp[j++] = (*stash)[i++];
	temp[j] = '\0';
	free(*stash);
	(*stash) = ft_strdup(temp);
	free (temp);
}
