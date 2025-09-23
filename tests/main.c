#include "get_line.h"

typedef struct s_output
{
	char	*line;
	size_t	size;
	ssize_t	returned;
}	t_output;

typedef struct s_test
{
	t_output	my;
	t_output	original;
}	t_test;

t_output	create_output(char *line, 

t_test	create_test(char *line1, char *line2)
{
	t_test test;

	test.my = create_output(line1, get_line);
	test.original = create_output(line2, getline);
	return (test);
}
