/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gikarcev <gikarcev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 14:21:06 by gikarcev          #+#    #+#             */
/*   Updated: 2026/02/13 14:26:42 by gikarcev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include <math.h>

void		put_pixel(mlx_image_t *image, uint32_t x, uint32_t y, \
						uint32_t color);
uint32_t	get_pixel(mlx_image_t *img, uint32_t x, uint32_t y);
uint32_t	blend_colors(uint32_t fg, uint32_t bg, double alpha);

static uint32_t	get_map_color(t_data *data, int map_x, int map_y)
{
	if (map_x < 0 || map_x >= data->map.width || map_y < 0 || \
			map_y >= data->map.height)
		return (MMAP_COLOR_VOID);
	if (data->map.grid[map_y][map_x] == '1')
		return (MMAP_COLOR_WALL);
	if (data->map.grid[map_y][map_x] != ' ')
		return (MMAP_COLOR_FLOOR);
	return (MMAP_COLOR_VOID);
}

static void	draw_fov_cone(t_data *data)
{
	int			y;
	int			x;
	int			cone_width;
	double		alpha;
	uint32_t	bg_color;

	y = 0;
	while (y < 60)
	{
		cone_width = (int)(y * 0.7);
		alpha = 0.5 * (1.0 - ((double)y / 60));
		x = -cone_width;
		while (x <= cone_width)
		{
			bg_color = get_pixel(data->screen, MMAP_CENTER_X + x, \
								MMAP_CENTER_Y - y);
			put_pixel(data->screen, MMAP_CENTER_X + x, MMAP_CENTER_Y - y,
				blend_colors(MMAP_COLOR_FOV, bg_color, alpha));
			x++;
		}
		y++;
	}
}

void	draw_player(t_data *data)
{
	int	i;
	int	j;

	i = -3;
	j = 0;
	while (i <= 3)
	{
		j = -3;
		while (j <= 3)
		{
			if (i * i + j * j <= 9)
				put_pixel(data->screen, MMAP_CENTER_X + i, MMAP_CENTER_Y + j,
					MMAP_COLOR_PLAYER);
			j++;
		}
		i++;
	}
}

void	draw_map(t_data *data, int y, int x)
{
	int		map_x;
	int		map_y;
	int		dist_sq;
	double	angle;

	angle = atan2(data->dir_y, data->dir_x) + M_PI_2;
	while (x <= MMAP_RADIUS)
	{
		dist_sq = x * x + y * y;
		if (dist_sq <= MMAP_RADIUS * MMAP_RADIUS)
		{
			map_x = (int)(data->player[0] + (x * cos(angle) - y * \
							sin(angle)) / MMAP_SCALE);
			map_y = (int)(data->player[1] + (x * sin(angle) + y * \
							cos(angle)) / MMAP_SCALE);
			put_pixel(data->screen, MMAP_CENTER_X + x, MMAP_CENTER_Y + y,
				get_map_color(data, map_x, map_y));
			if (dist_sq > (MMAP_RADIUS - 3) * (MMAP_RADIUS - 3))
				put_pixel(data->screen, MMAP_CENTER_X + x, \
					MMAP_CENTER_Y + y, 0xFFFFFFFF);
		}
		x++;
	}
}

void	draw_minimap(t_data *data)
{
	int		x;
	int		y;

	y = -MMAP_RADIUS;
	while (y <= MMAP_RADIUS)
	{
		x = -MMAP_RADIUS;
		draw_map(data, y, x);
		y++;
	}
	draw_fov_cone(data);
	draw_player(data);
}
