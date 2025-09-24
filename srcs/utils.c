#include "get_line.h"

int	ft_strlen(char *str)
{
	char	*ptr;

	if (!str)
		return (0);
	ptr = str;
	while (*ptr)
		ptr++;
	return (ptr - str);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	char	*ptr;

	if (!dest || !src)
		return (0);
	ptr = dest;
	while (n-- && *src)
		*ptr++ = *src++;
	return (dest);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	
	if (!dest || !src)
		return (0);
	i = 0;
	while (src[i] && size-- > 1)
		*dest++ = src[i++];
	*dest = 0;
	while (src[i])
		i++;
	return (i);
}

size_t	ft_putchar_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}

size_t	ft_putstr_fd(char *str, int fd)
{
	size_t	bytes;

	if (!str)
		return (ft_putstr_fd("(nil)", STDERR));
	bytes = 0;
	while (*str)
		bytes += ft_putchar_fd(*str++, fd);
	return (bytes);
}

void	*ft_memcpy(void *dest, void *src, size_t size)
{
	unsigned char	*p1;
	unsigned char	*p2;

	p1 = dest;
	p2 = src;
	while (size--)
		*p1++ = *p2++;
	return (dest);
}

int	get_block_size(void *ptr)
{
	size_t	*block_ptr;
	
	block_ptr = ptr;
	if (block_ptr)
		return (*--block_ptr);
	return (-1);
}

void	*ft_realloc(void *ptr, size_t bytes)
{
	void	*new;
	int	block_size;

	block_size = get_block_size(ptr);
	if (block_size < 0)
		return (malloc(bytes));
	if (bytes <= (size_t) block_size)
	{
		if (!bytes)
		{
			free(ptr);
			ptr = 0;
		}
		return (ptr);
	}
	new = malloc(bytes);
	if (!new)
		return (0);
	ft_memcpy(new, ptr, block_size);
	free(ptr);
	return (new);
}
