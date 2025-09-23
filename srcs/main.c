#include "get_line.h"
#include <stdio.h>
#include <fcntl.h>

//int	main(int argc, char **argv)
//{
//	FILE	*file1;
//	int	file2;
//	char	*my;
//	char	*original;
//	size_t	size1;
//	size_t	size2;
//	ssize_t	return1;
//	ssize_t	return2;
//
//	if (argc != 2)
//		return (1);
//	file1 = fopen(argv[1], "r");
//	if (!file1)
//		return (2);
//	file2 = open(argv[1], O_RDONLY);
//	if (file2 < 0)
//		return (3);
//	my = 0;
//	original = 0;
//	return1 = getline(&original, &size1, file1);
//	return2 = get_line(&my, &size2, file2);
//	printf("size:\t\t%lu\t\toriginal: %s\n", size1, original);
//	printf("return:\t%ld\n\n", return1);
//	printf("size:\t\t%lu\t\tmy: %s\n", size2, my);
//	printf("return:\t%ld\n\n", return2);
//	return (0);
//}

int	main(int argc, char **argv)
{
	int	file;
	char	*line;
	size_t	size;

	if (argc != 2)
		return (1);
	file = open(argv[1], O_RDONLY);
	if (file < 0)
		return (2);
	line = 0;
	printf("return:\t\t%lu\n", get_line(&line, &size, file));
	printf("line:  \t\t%s\n", line);
	return (0);
}
