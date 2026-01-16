#include "../cub3d.h"

int	detect_map(char *line)
{
	while (*line == ' ')
		line++;
	if (*line == '1')
		return (1);
	return (0);
}

int	check_trailing_lines(int fd, t_data *data)
{
	char	*line;
	char	malloc_failure;
	int		i;

	i = -1;
	while (1)
	{
		line = get_next_line(fd, &malloc_failure, 0);
		if (malloc_failure)
			clean(data, "failure inside gnl\n", 1, fd);
		if (!line)
			break ;
		while (line[++i])
		{
			if (!(line[i] == ' ' || line[i] == '\n' || line[i] == '\0'))
			{
				free(line);
				return (1);
			}
		}
		free(line);
		i = -1;
	}
	return (0);
}

static void	check_zero(t_data *data, int x, int y)
{
	if (y == 0 || y == data->map.height - 1
		|| x == 0 || x == data->map.width - 1)
		clean(data, "0 touches border\n", 1, -1);
	if (data->map.grid[y - 1][x] == ' '
		|| data->map.grid[y + 1][x] == ' '
		|| data->map.grid[y][x - 1] == ' '
		|| data->map.grid[y][x + 1] == ' ')
		clean(data, "0 touches empty space\n", 1, -1);
}

void	validate_map(t_data *data)
{
	int	y;
	int	x;

	y = -1;
	while (++y < data->map.height)
	{
		x = -1;
		while (++x < data->map.width)
		{
			if (data->map.grid[y][x] == '0')
				check_zero(data, x, y);
		}
	}
}

void	helper_fill_player(t_data *data, int o, int dir_x, int dir_y)
{
	data->player[2] = o;
	data->dir_x = dir_x;
	data->dir_y = dir_y;
}
