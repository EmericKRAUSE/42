#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

char	*get_next_line(int fd);
void	read_and_add(int fd, char **line, char stash[BUFFER_SIZE + 1]);
int		found_newline(char *buf, int readed);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *str);
char	*ft_strdup(char *str);
void	extract_line(char *buf, char **line);
void	add_to_stash(char stash[BUFFER_SIZE + 1], char *buf);

#endif