#ifndef GET_LINE_H
# define GET_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>

# define STDERR		2
# define BUF_SIZE	1024

int	ft_strlen(char *str);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
size_t	ft_putstr_fd(char *str, int fd);
void	*ft_realloc(void *ptr, size_t bytes);
size_t	get_line(char **lineptr, size_t *n, int fd);

#endif
