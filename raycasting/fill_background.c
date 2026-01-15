#include "../cub3d.h"

void	put_pixel(mlx_image_t *image, uint32_t x, uint32_t y, uint32_t color);

static uint32_t	get_rgba(int r, int g, int b, int a)
{
	return ((r << 24) | (g << 16) | (b << 8) | a);
}

void	fill_background(t_data *data)
{
	int			j;
	int			i;
	uint32_t	c_color;
	uint32_t	f_color;

	c_color = get_rgba(data->ceiling[0], data->ceiling[1],
			data->ceiling[2], 255);
	f_color = get_rgba(data->floor[0], data->floor[1],
			data->floor[2], 255);
	j = 0;
	while (j < WIN_HEIGHT)
	{
		i = 0;
		while (i < WIN_WIDTH)
		{
			if (j < WIN_HEIGHT / 2)
				put_pixel(data->screen, i, j, c_color);
			else
				put_pixel(data->screen, i, j, f_color);
			i++;
		}
		j++;
	}
}
