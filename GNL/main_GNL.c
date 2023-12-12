#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int		fd;
	char	*line;

	int i = 0;
	fd = open("test.txt", O_RDONLY);
	while (i < 3)
	{
		line = get_next_line(fd);
		printf("%s\n", line);
		if (line == NULL)
		{
			free (line);
			break;
		}
		free (line);
		i++;
	}

	close(fd);
	return (0);
}
