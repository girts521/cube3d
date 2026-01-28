#include "../cub3d.h"

uint32_t	get_texture_pixel(mlx_texture_t *tex, int x, int y);
void		put_pixel(mlx_image_t *image, uint32_t x,
				uint32_t y, uint32_t color);

// minimap

uint32_t	blend_colors(uint32_t fg, uint32_t bg, double alpha)
{
	uint8_t	r_res;
	uint8_t	g_res;
	uint8_t	b_res;

	r_res = (uint8_t)(((fg >> 24) & 0xFF) * alpha + ((bg >> 24) & 0xFF)
			* (1.0 - alpha));
	g_res = (uint8_t)(((fg >> 16) & 0xFF) * alpha + ((bg >> 16) & 0xFF)
			* (1.0 - alpha));
	b_res = (uint8_t)(((fg >> 8) & 0xFF) * alpha + ((bg >> 8) & 0xFF)
			* (1.0 - alpha));
	return (r_res << 24 | g_res << 16 | b_res << 8 | 0xFF);
}
// Alpha Blending

uint32_t	get_pixel(mlx_image_t *img, uint32_t x, uint32_t y)
{
	uint8_t	*pixelstart;

	if (x >= img->width || y >= img->height)
		return (0);
	pixelstart = &img->pixels[(y * img->width + x) * 4];
	return ((uint32_t)(pixelstart[0] << 24 | pixelstart[1] << 16
		| pixelstart[2] << 8 | pixelstart[3]));
}

static void	final_pixel(t_data *data, int x, int y)
{
	uint32_t	color;

	color = get_texture_pixel(data->img[S_BAR], (int)((double)x
				/ data->hud.bar_total_w * data->img[S_BAR]->width),
			(int)((double)y
				/ data->hud.bar_h * data->img[S_BAR]->height));
	if ((color & 0xFF) != 0)
	{
		put_pixel(data->screen,
			data->hud.bar_x_start + x,
			data->hud.bar_y_start + y,
			blend_colors(color,
				get_pixel(data->screen,
					data->hud.bar_x_start + x,
					data->hud.bar_y_start + y), 0.55));
	}
}

void	hud(t_data *data)
{
	int	x;
	int	y;

	data->hud.draw_width = data->hud.bar_total_w * data->stamina;
	y = 0;
	while (y < data->hud.bar_h)
	{
		x = 0;
		while (x < data->hud.draw_width)
		{
			final_pixel(data, x, y);
			x++;
		}
		y++;
	}
}

// void	hud(t_data *data)
// {
// 	uint32_t	color;
// 	int			x;
// 	int			y;

// 	data->hud.draw_width = data->hud.bar_total_w * data->stamina;
// 	y = 0;
// 	while (y < data->hud.bar_h)
// 	{
// 		x = 0;
// 		while (x < data->hud.draw_width)
// 		{
// 			color = get_texture_pixel(data->img[S_BAR], (int)((double)x
// 						/ data->hud.bar_total_w * data->img[S_BAR]->width),
// 					(int)((double)y / data->hud.bar_h
// 						* data->img[S_BAR]->height));
// 			if ((color & 0xFF) != 0)
// 				put_pixel(data->screen, data->hud.bar_x_start + x,
// 					data->hud.bar_y_start + y, color);
// 			x++;
// 		}
// 		y++;
// 	}
// }
