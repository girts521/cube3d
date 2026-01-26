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

static void	clean_anim(t_data *data, int idx)
{
	int	i;

	i = -1;
	while (++i < N_ANIM_TEXTURES)
	{
		mlx_delete_texture(data->anim_img[idx][i]);
		data->anim_img[idx][i] = NULL;
	}
}

static void	clean_mlx(t_data *data)
{
	int	i;

	i = -1;
	while (++i < N_TEXTURES && data->img[i] != NULL)
	{
		if (data->anim_img[i][0] == NULL) // skip anim texture
		{
			mlx_delete_texture(data->img[i]);
			data->img[i] = NULL;
		}
		else
			clean_anim(data, i);
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
	ma_engine_uninit(&data->s.audio_engine);
	exit(status);
}
