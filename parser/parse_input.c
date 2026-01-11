#include "../cub3d.h"

void	parse_map(char *line, t_data *data, int fd);
int		detect_map(char *line);
void	fill_map(t_data *data, char *argv[], int fd_len);
void	validate_map(t_data *data);

static int	add_element(char *line, int element, t_data *data)
{
	mlx_texture_t	*t;

	while (*line == ' ')
		line++;
	//line[ft_strlen(line) - 1] = '\0';  // \n raplce with '/0' segfault should not happen
	//printf("%s-- %d\n", line, element);
	t = mlx_load_png(line);
	if (!t)
		return (1);
	if (data->img[element] != NULL)
		return (1);
	// if (element == F || C)   // create one-colored image or just add texture liek for bonus?
	// 	data->img[element] = create_image();
	// else
	data->img[element] = mlx_texture_to_image(data->mlx, t);
	if (!data->img[element])
		return (1);
	// if (resize_assets(data)) ??
	// 	return (1);
	return (0);
}

static int	parse_element(char *line, t_data *data)
{
	while (*line == ' ')
		line++;
	if (!ft_strncmp(line, "NO", 2))
		return (add_element(line + 2, NO, data));
	if (!ft_strncmp(line, "SO", 2))
		return (add_element(line + 2, SO, data));
	if (!ft_strncmp(line, "WE", 2))
		return (add_element(line + 2, WE, data));
	if (!ft_strncmp(line, "EA", 2))
		return (add_element(line + 2, EA, data));
	if (!ft_strncmp(line, "F", 1))
		return (add_element(line + 1, F, data));
	if (!ft_strncmp(line, "C", 1))
		return (add_element(line + 1, C, data));
	return (1);
}

static int	process_element(char *line, t_data *data, int *fd_len)
{
	if (line[0] == '\0') // get_next_line retuns \0 with_n=0
	{
		(*fd_len)++;
		return(0);
	}
	*fd_len += (ft_strlen(line) + 1);
	return (parse_element(line, data));
}



static int	handle_line(t_data *data, int fd, int *fd_len)
{
	char	*line;
	char	malloc_failure; // handle malloc inside get_next_line

	line = get_next_line(fd, &malloc_failure, 0);
	if (malloc_failure)
		clean(data, "failure inside get_next_line\n", 1, fd);
	if (!line)
		return (1);
	if (detect_map(line))
	{
		parse_map(line, data, fd);
		return (1);
	}
	if (process_element(line, data, fd_len))
	{
		printf("Culprit >> '%s'", line);
		free(line);
		clean(data, "Wrong input\n", 1, fd);
	}
	free(line);
	return (0);
}

void	parse_input(t_data *data, char *argv[])
{
	int		fd;
	int		fd_len;

	fd_len = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		clean(NULL, "Could not open file\n", 1, -1);
	while (1)
	{
		if (handle_line(data, fd, &fd_len))
			break ;
	}
	if (data->map.height == 0)
		clean(data, "map not found\n", 1, fd);
	close(fd);
	fill_map(data, argv, fd_len);
	validate_map(data);
}
