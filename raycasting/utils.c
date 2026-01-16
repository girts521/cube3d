#include "../cub3d.h"

void	put_pixel(mlx_image_t *image, uint32_t x, uint32_t y, uint32_t color)
{
	uint8_t	*pixel;

	pixel = &image->pixels[(y * image->width + x) * sizeof(int32_t)];
	*(pixel++) = (uint8_t)(color >> 24);
	*(pixel++) = (uint8_t)(color >> 16);
	*(pixel++) = (uint8_t)(color >> 8);
	*(pixel++) = (uint8_t)(color & 0xFF);
}

void	init_ray(t_raycasting *ray, t_data *data)
{
	ray->side = 0;
	ray->pos_x = data->player[0];
	ray->pos_y = data->player[1];
	ray->plane_x = -data->dir_y * 0.66;
	ray->plane_y = data->dir_x * 0.66;
	ray->time = 0;
	ray->old_time = 0;
	ray->map_y = (int)ray->pos_y;
	ray->map_x = (int)ray->pos_x;
}

void	set_delta(t_raycasting *ray)
{
	if (ray->ray_dir_x == 0)
		ray->delta_dist_x = 1e30;
	else
		ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
	if (ray->ray_dir_y == 0)
		ray->delta_dist_y = 1e30;
	else
		ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
}

void	set_side_dist(t_raycasting *ray)
{
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (ray->pos_x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - ray->pos_x) * ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (ray->pos_y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - ray->pos_y) * ray->delta_dist_y;
	}
}

uint32_t	apply_color_tint(uint32_t color, double factor)
{
	uint32_t	r;
	uint32_t	g;
	uint32_t	b;
	uint32_t	a;

	r = (uint32_t)(((color >> 24) & 0xFF) * factor);
	g = (uint32_t)(((color >> 16) & 0xFF) * factor);
	b = (uint32_t)(((color >> 8) & 0xFF) * factor);
	a = (uint32_t)((color & 0xFF) * factor);
	return ((r << 24) | (g << 16) | (b << 8) | a);
}
