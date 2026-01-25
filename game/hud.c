#include "../cub3d.h"

uint32_t	get_texture_pixel(mlx_image_t *tex, int x, int y);
void		put_pixel(mlx_image_t *image, uint32_t x,
				uint32_t y, uint32_t color);

// minimap

void	hud(t_data *data)
{
	uint32_t	color;
	int			x;
	int			y;

	data->hud.draw_width = data->hud.bar_total_w * data->stamina;
	y = 0;
	while (y < data->hud.bar_h)
	{
		x = 0;
		while (x < data->hud.draw_width)
		{
			color = get_texture_pixel(data->img[S_BAR], (int)((double)x
						/ data->hud.bar_total_w * data->img[S_BAR]->width),
					(int)((double)y / data->hud.bar_h
						* data->img[S_BAR]->height));
			if ((color & 0xFF) != 0)
				put_pixel(data->screen, data->hud.bar_x_start + x,
					data->hud.bar_y_start + y, color);
			x++;
		}
		y++;
	}
}
