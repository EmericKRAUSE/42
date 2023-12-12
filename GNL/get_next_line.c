#include "get_next_line.h"
//a enlever
#include <stdio.h>

char *get_next_line(int fd)
{
	printf ("test (1) \n");
	char	stash[BUFFER_SIZE + 1];
	char	*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	printf ("test (2) \n");
	read_and_add(fd, &line);

	return (line);
}

void	read_and_add(int fd, char **line)
{
	int		readed;
	char	*buf;

	readed = 1;
	printf ("test (3) \n");
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
		printf ("test (4) \n");
		if (found_newline(buf, readed))
		{
			extract_line(buf, line, stash);
			clear_stash(strash);
		}
		else 
		{
			printf ("test (5) \n");
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

	printf ("test (6) \n");
	if (!s1 && !s2)
		return (NULL);
	else if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
	printf ("test (7) \n");
	ptr = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	printf ("test (8) \n");
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

void	extract_line(buf, line, stash)
{

}