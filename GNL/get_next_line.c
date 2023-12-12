#include "get_next_line.h"
//a enlever
#include <stdio.h>

char *get_next_line(int fd)
{
	static char stash[BUFFER_SIZE + 1];
	char	*line;

	line = NULL;
	line = ft_strjoin(line, stash);
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	read_and_add(fd, &line, stash);

	return (line);
}

void	read_and_add(int fd, char **line, char stash[BUFFER_SIZE + 1])
{
	int		readed;
	char	*buf;

	readed = 1;
	while (readed > 0)
	{
		buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buf)
			return ;
		readed = read(fd, buf, BUFFER_SIZE);
		if (readed < 0)
		{
			free (buf);
			return ;
		}
		if (found_newline(buf, readed))
		{
			extract_line(buf, line);
			add_to_stash(stash, buf);
			free (buf);
			return ;
		}
		else 
		{
			(*line) = ft_strjoin(*line, buf);
		}
		free (buf);
	}
}

int	found_newline(char *buf, int readed)
{
	int i;

	i = 0;
	while (i < readed)
	{
		if ( buf[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char *ptr;
	char *current_ptr;

	if (!s1 && !s2)
		return (NULL);
	else if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
	ptr = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!ptr)
		return (NULL);
	current_ptr = ptr;
	while (*s1)
		*ptr++ = *s1++;
	while (*s2)
		*ptr++ = *s2++;
	*ptr = '\0';
	return (current_ptr);
}

int	ft_strlen(char *str)
{
	int i;

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

void	extract_line(char *buf, char **line)
{
	int	i;
	char str[BUFFER_SIZE + 1];

	i = 0;
	while (buf[i] && buf[i] != '\n')
	{
		str[i] = buf[i];
		i++;
	}
	if (buf[i] == '\n')
	{
		str[i] = buf[i];
		i++;
 	}
	str[i] = '\0';
	(*line) = ft_strjoin(*line, str);
}

void	add_to_stash(char stash[BUFFER_SIZE + 1], char *buf)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (buf[i] == '\n')
		i++;
	while (buf[i])
		stash[j++] = buf[i++];
	stash[j] = '\0';
}
