#include "get_line.h"

//static int	is_end_of_line(int fd, char buf[BUF_SIZE + 1], int i, ssize_t *bytes_read)
//{
//	if (i <= 0 && bytes_read)
//	{
//		*bytes_read = read(fd, buf, BUF_SIZE);
//		if (*bytes_read >= 0)
//			buf[*bytes_read] = 0;
//		else
//		{
//			ft_putstr_fd(strerror(errno), STDERR);
//			return (1);
//		}
//	}
//	return (buf[i] == '\n' || buf[i] == 0);
//}
//
//ssize_t	get_line(char **lineptr, size_t *n, int fd)
//{
//	static char		buf[BUF_SIZE + 1];
//	static int		i;
//	static ssize_t	bytes_read;
//	int				len;
//
//	if (!lineptr || !n || fd < 0)
//		return (-1);
//	*n = ft_strlen(*lineptr);
//	while (!is_end_of_line(fd, buf, i, &bytes_read))
//	{
//		len = 0;
//		while (buf[i + len] && buf[i + len] != '\n')
//			len++;
//		*lineptr = ft_realloc(*lineptr, *n + len + 1);
//		if (!*lineptr)
//			return (-1);
//		ft_strncpy(*lineptr + *n, buf + i, len);
//		*n += len;
//		i = (i + len) % BUF_SIZE;
//	}
//	i += buf[i] == '\n';
//	return (bytes_read);
//}

// FILL BUF -> SNIFFER -> CONCATER -> CHECK END

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
		ft_strlcpy(*lineptr + *n, start, ptr - start + 1);
		*n += ptr - start;
		if (*ptr == '\n' && ++ptr)
			break ;
	}
	return (bytes_read);
}
