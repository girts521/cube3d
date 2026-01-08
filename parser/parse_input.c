#include "../cub3d.h"

static int	parse_map(const char *line, t_data *data, int fd, int fd_len)
{
	// parse first line
	// then get_line again for dimensions (+ invalid char check)
	// restart with read(fd_len) to parse map properly
}

static int	process_line(const char *line, t_data *data, int fd)
{
	static int	fd_len = 0; // keep track of len till map found

	if (detect_map(line))
	{
		check_elements_presence(data);
		return (parse_map(line, data, fd, fd_len));
	}
	fd_len += ft_strlen(line);
	return (parse_element(line, data));
}

void	parse_input(t_data *data, char *argv[])
{
	int		fd;
	char	*line;
	char	malloc_failure; // handle malloc inside get_next_line

	malloc_failure = 0;
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		return (clean(NULL, "Could not open file\n", 1));
	while (1)
	{
		line = get_next_line(fd, &malloc_failure);
		if (malloc_failure)
		{
			close(fd);
			clean(data, "malloc failure inside get_next_line\n", 1);
		}
		if (!line)
			break;
		if (process_line(line, data, fd))
		{
			printf("Culprit >> '%s'", line);
			free(line);
			close(fd);
			clean(data, "Wrong input\n", 1);
		}
		free(line);
	}
	close(fd);
}
