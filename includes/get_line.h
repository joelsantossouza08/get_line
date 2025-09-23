#ifndef GET_LINE_H
# define GET_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>


# if BUF_SIZE == 0
#  undef BUF_SIZE
# endif

# ifndef BUF_SIZE
#  define BUF_SIZE	1024
# endif

# define STDERR		2

int	ft_strlen(char *str);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
size_t	ft_putstr_fd(char *str, int fd);
void	*ft_realloc(void *ptr, size_t bytes);
ssize_t	get_line(char **lineptr, size_t *n, int fd);

#endif
