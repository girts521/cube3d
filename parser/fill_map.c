#include "../cub3d.h"

void	helper_fill_player(t_data *data, int o, int dir_x, int dir_y);

static void	add_row(char **row, int fd, int width)
{
	char	buf;
	ssize_t	byte;
	int		i;

	(void)byte;
	i = -1;
	while (++i < width)
	{
		byte = read(fd, &buf, 1);
		if (buf == '\n')
		{
			while (i < width)
				(*row)[i++] = ' ';
			return ;
		}
		(*row)[i] = buf;
	}
	byte = read(fd, &buf, 1);
}

static void	init_map(t_data *data, int fd)
{
	int	i;

	data->map.grid = (char **)malloc(sizeof(char *) * data->map.height);
	if (!data->map.grid)
		clean(data, "malloc failure\n", 1, fd);
	i = -1;
	while (++i < data->map.height)
		data->map.grid[i] = NULL;
	i = -1;
	while (++i < data->map.height)
	{
		data->map.grid[i] = (char *)malloc(sizeof(char) * data->map.width);
		if (!data->map.grid[i])
			clean(data, "malloc failure\n", 1, fd);
		add_row(&data->map.grid[i], fd, data->map.width);
	}
}

static void	fill_player(t_data *data, int i, int i2, char direction)
{
	data->player[0] = i2;
	data->player[1] = i;
	if (direction == 'N')
		helper_fill_player(data, 0, 0, -1);
	else if (direction == 'E')
		helper_fill_player(data, 1, 1, 0);
	else if (direction == 'S')
		helper_fill_player(data, 2, 0, 1);
	else
		helper_fill_player(data, 3, -1, 0);
	data->map.grid[i][i2] = '0';
}

static void	set_player(t_data *data)
{
	int	i;
	int	i2;

	i = -1;
	while (++i < data->map.height)
	{
		i2 = -1;
		while (++i2 < data->map.width)
		{
			if (ft_ischars(data->map.grid[i][i2], "NSEW"))
			{
				if (data->player[0] != -1)
					clean(data, "duplicate player\n", 1, -1);
				fill_player(data, i, i2, data->map.grid[i][i2]);
			}
		}
	}
}

void	fill_map(t_data *data, char *argv[], int fd_len)
{
	int		fd;
	char	*buf;

	buf = malloc(fd_len);
	if (buf == NULL)
		clean(data, "malloc failure\n", 1, -1);
	fd = open(argv[1], O_RDONLY);
	if (read(fd, buf, fd_len) == -1)
	{
		free(buf);
		clean(data, "read failure\n", 1, fd);
	}
	free(buf);
	init_map(data, fd);
	set_player(data);
}
