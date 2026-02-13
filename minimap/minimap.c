#include "../cub3d.h"
#include <math.h>

static uint32_t	get_map_color(t_data *data, int map_x, int map_y)
{
	if (map_x < 0 || map_x >= data->map.width || 
		map_y < 0 || map_y >= data->map.height)
		return (MMAP_COLOR_VOID);
	if (data->map.grid[map_y][map_x] == '1')
		return (MMAP_COLOR_WALL);
	if (data->map.grid[map_y][map_x] != ' ')
		return (MMAP_COLOR_FLOOR);
	return (MMAP_COLOR_VOID);
}

static void	draw_fov_cone(t_data *data)
{
	int       y;
	int       x;
	int       cone_dist;
	int       cone_width;
	double    alpha;
	uint32_t  bg_color;

	cone_dist = 60;
	y = 0;
	while (y < cone_dist)
	{
		cone_width = (int)(y * 0.7); 
		alpha = 0.5 * (1.0 - ((double)y / cone_dist));
		x = -cone_width;
		while (x <= cone_width)
		{
			bg_color = get_pixel(data->screen, MMAP_CENTER_X + x, MMAP_CENTER_Y - y);
			put_pixel(data->screen, 
                MMAP_CENTER_X + x, 
                MMAP_CENTER_Y - y, 
                blend_colors(MMAP_COLOR_FOV, bg_color, alpha));
			x++;
		}
		y++;
	}
}

void	draw_minimap(t_data *data)
{
	int     x;
	int     y;
	int     dist_sq;
	double  angle;
	double  rot_x;
	double  rot_y;
	int     map_x;
	int     map_y;

	angle = atan2(data->dir_y, data->dir_x) + M_PI_2;
	y = -MMAP_RADIUS;
	while (y <= MMAP_RADIUS)
	{
		x = -MMAP_RADIUS;
		while (x <= MMAP_RADIUS)
		{
			dist_sq = x * x + y * y;
			if (dist_sq <= MMAP_RADIUS * MMAP_RADIUS)
      {
				rot_x = x * cos(angle) - y * sin(angle);
				rot_y = x * sin(angle) + y * cos(angle);
				map_x = (int)(data->player[0] + rot_x / MMAP_SCALE);
				map_y = (int)(data->player[1] + rot_y / MMAP_SCALE);
				put_pixel(data->screen, MMAP_CENTER_X + x, MMAP_CENTER_Y + y,
                    get_map_color(data, map_x, map_y));
				if (dist_sq > (MMAP_RADIUS - 3) * (MMAP_RADIUS - 3))
					put_pixel(data->screen, MMAP_CENTER_X + x, MMAP_CENTER_Y + y, 0xFFFFFFFF);
			}
			x++;
		}
		y++;
	}

	draw_fov_cone(data);

	int i = -3;

	while (i <= 3)
	{
		int j = -3;
		while (j <= 3)
		{
			if (i*i + j*j <= 9)
				put_pixel(data->screen, MMAP_CENTER_X + i, MMAP_CENTER_Y + j, MMAP_COLOR_PLAYER);
			j++;
		}
		i++;
	}
}
