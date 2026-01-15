#include "../cub3d.h"

int check_trailing_lines(int fd, t_data *data);

static int	check_elements_presence(t_data *data)
{
	int	i;

	i = -1;
	while (++i < N_TEXTURES)
	{
		if (data->img[i] == NULL)
			return (1);
	}
	return (0);
}

static int	set_width(char *line, t_data *data)
{
	int	i;

	i = 0;
	while(line[i])
	{
		if (!ft_ischars(line[i], " 01NSEW"))
		{
			printf("Invalid map symbol: '%c'", line[i]);
			free(line);
			return (1);
		}
		i++;
	}
	if (data->map.width < i)
		data->map.width = i;
	return (0);
}

static void	set_height(char *line, t_data *data, int fd)
{
	char	malloc_failure;
	int		i;

	malloc_failure = 0;
	i = 1;
	while (1)
	{
		line = get_next_line(fd, &malloc_failure, 0);
		if (malloc_failure)
			clean(data, "failure inside gnl\n", 1, fd);
		if (!line || *line == '\0') // check \n basically
			break;
		if (set_width(line, data))
			clean(data, "Invalid map symbol\n", 1, fd);
		free(line);
		i++;
	}
	data->map.height = i;
}

static void	map_dimensions(char *line, t_data *data, int fd)
{
	if (set_width(line, data))
		clean(data, "Invalid map symbol\n", 1, fd);
	set_height(line, data, fd);
	if(check_trailing_lines(fd, data))
	{
		free(line);
		clean(data, "Garbage after map\n", 1, fd);
	}
}

void	parse_map(char *line, t_data *data, int fd)
{
	if (check_elements_presence(data))
	{
		free(line);
		clean(data, "Invalid map symbol\n", 1, fd);
	}
	map_dimensions(line, data, fd);


	//printf("\nwidth: %d, height: %d\n", data->map.width, data->map.height);


	// restart with read(fd_len) to parse map properly

	free(line);
}
