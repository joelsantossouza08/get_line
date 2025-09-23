#include "get_line.h"

static int	is_end_of_line(int fd, char buf[BUF_SIZE + 1], int i)
{
	int	bytes_read;

	if (i <= 0)
	{
		bytes_read = read(fd, buf, BUF_SIZE);
		if (bytes_read >= 0)
			buf[bytes_read] = 0;
		else
		{
			ft_putstr_fd(strerror(errno), STDERR);
			return (1);
		}
	}
	return (buf[i] == '\n' || buf[i] == 0);
}

size_t	get_line(char **lineptr, size_t *n, int fd)
{
	static char	buf[BUF_SIZE + 1];
	static int	i;
	int			len;

	if (!lineptr || !n || fd < 0)
		return (-1);
	*n = ft_strlen(*lineptr);
	while (!is_end_of_line(fd, buf, i))
	{
		len = 0;
		while (buf[i + len] && buf[i + len] != '\n')
			len++;
		*lineptr = ft_realloc(*lineptr, *n + len + 1);
		if (!*lineptr)
			return (-1);
		ft_strncpy(*lineptr + *n, buf + i, len);
		*n += len;
		i = (i + len) % BUF_SIZE;
	}
	return (*n);
}
