#include "cub3d.h"

static void	clean_grid(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height && map->grid[i])
	{
		free(map->grid[i]);
		map->grid[i++] = NULL;
	}
	free(map->grid);
	map->grid = NULL;
}

static void	clean_mlx(t_data *data)
{
	int	i;

	i = -1;
	while (++i < N_TEXTURES && data->img[i] != NULL)
	{
		mlx_delete_image(data->mlx, data->img[i]);
		data->img[i] = NULL;
	}
	if (data->mlx != NULL)
	{
		mlx_close_window(data->mlx);
		mlx_terminate(data->mlx);
	}
	data->mlx = NULL;
}

int	clean(t_data *data, char *err_mess, int status, int fd)
{
	if (data)
	{
		clean_grid(&data->map);
		clean_mlx(data);
	}
	if (err_mess)
		printf("\nError\n%s", err_mess);
	if (fd != -1)
		close(fd);
	ma_engine_uninit(&data->audio_engine);
	exit(status);
}
