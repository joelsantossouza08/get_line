#include "get_line.h"
#include <stdio.h>

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

t_test	create_test(char *line, FILE *file)
{
	t_test	test;

	test.my.line = line;
	test.original.line = line;
	test.my.returned = get_line(&test.my.line, &test.my.size, fileno(file));
	test.original.returned = getline(&test.original.line, &test.original.size, file);
	return (test);
}

void	output_file(t_output output, char *file_path)
{
	char	command[ft_strlen(output.line) + 1000];

	strcat(command, "echo \"");
	strcat(command, output.line);
	strcat(command, "\" >> ");
	strcat(command, file_path);
	system(command);
}

int	main(int argc, char **argv)
{
	t_test	test;
	int	i;
	FILE	*file;
	int	size;
	char	*lines[] =
	{
		"", "joel", 0, "20934u2-09j230f"
	};

	(void)argc;
	size = sizeof(lines) / sizeof(char *);
	while (*++argv)
	{
		file = fopen(*argv, "r");
		if (!file)
			continue ;
		i = -1;
		while (++i < size)
		{
			test = create_test(lines[i], file);
			output_file(test.my, "tests/myown");
			output_file(test.original, "tests/original");
			free(test.my.line);
			free(test.original.line);
		}
		fclose(file);
	}
	return (0);
}
