char *get_next_line(int fd)
{
	char	stash[BUFFER_SIZE + 1];
	char	*line;

	read_and_stash(fd, &line)
	// 2. add to line

	return (line);
}

void	read_and_add(int fd, char **line)
{
	int readed;

	readed = 1;
	while (readed > 0)
	{
		readed = read(fd, buf, BUFFER_SIZE);
		if (readed < 1)
			break;
		if (found_newline(buf, readed))
		{

		}
		else 
		{
			ft_strjoin(line, buf);
		}
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
	else
	{
		while (*s1)
			*ptr++ = *s1++;
		while (*s2)
			*ptr++ = *s2++;
		*ptr = '\0';
	}
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
