#include "get_line.h"

static ssize_t	fill_buffer(int fd, char *buffer, char **ptr, size_t *bytes_read)
{
	static ssize_t	bytes;

	if (!buffer)
		return (-1);
	if (!*ptr || !**ptr)
	{
		*ptr = buffer;
		bytes = read(fd, buffer, BUF_SIZE);
		if (bytes > 0)
			buffer[bytes] = 0;
	}
	if (bytes_read)
		*bytes_read = bytes;
	return (bytes);
}

ssize_t	get_line(char **lineptr, size_t *n, int fd)
{
	static char	buf[BUF_SIZE + 1];
	static char	*ptr;
	size_t		bytes_read;
	char		*start;

	if (!lineptr || !n)
		return (-1);
	*n = 0;
	while (fill_buffer(fd, buf, &ptr, &bytes_read) > 0)
	{
		start = ptr;
		while (*ptr && *ptr != '\n')
			ptr++;
		*lineptr = ft_realloc(*lineptr, *n + (ptr - start) + 1);
		if (!*lineptr)
			return (-1);
		ft_strlcpy(*lineptr + *n, start, ptr - start + 1);
		*n += ptr - start;
		if (*ptr == '\n' && ++ptr)
			break ;
	}
	return (bytes_read);
}
