#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("get_next_line.h", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		printf ("%s", line);
		if (line == NULL)
		{
			free (line);
			return (0);
		}
		free (line);
	}
	return (0);
}
