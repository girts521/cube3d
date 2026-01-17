#include "../cub3d.h"

void		put_pixel(mlx_image_t *image, uint32_t x,
				uint32_t y, uint32_t color);
void		init_ray(t_raycasting *ray, t_data *data);
void		set_delta(t_raycasting *ray);
void		set_side_dist(t_raycasting *ray);
void		render_vertical_line(int x, t_raycasting *ray,
				t_data *data);
void		render_floor_ceiling(t_data *data, t_raycasting *ray, int x);

static void	advance_ray(t_raycasting *ray)
{
	if (ray->side_dist_x < ray->side_dist_y)
	{
		ray->side_dist_x += ray->delta_dist_x;
		ray->map_x += ray->step_x;
		ray->side = 0;
	}
	else
	{
		ray->side_dist_y += ray->delta_dist_y;
		ray->map_y += ray->step_y;
		ray->side = 1;
	}
}

void	find_wall(t_raycasting *ray, t_data *data)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		advance_ray(ray);
		if (ray->map_x < 0 || ray->map_x >= data->map.width
			|| ray->map_y < 0 || ray->map_y >= data->map.height)
		{
			hit = 1;
			break ;
		}
		if (data->map.grid[ray->map_y][ray->map_x] > '0')
			hit = 1;
	}
}
//printf("mapX: %d\n mapY: %d\n", ray->mapX, ray->mapY);

void	calculate_ray(t_raycasting *ray, t_data *data)
{
	if (ray->side == 0)
		ray->perp_wall_dist = (ray->side_dist_x - ray->delta_dist_x);
	else
		ray->perp_wall_dist = (ray->side_dist_y - ray->delta_dist_y);
	ray->line_height = (int)(WIN_HEIGHT / ray->perp_wall_dist);
	ray->draw_start = -ray->line_height / 2 + WIN_HEIGHT / 2 + data->pitch;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + WIN_HEIGHT / 2 + data->pitch;
	if (ray->draw_end >= WIN_HEIGHT)
		ray->draw_end = WIN_HEIGHT - 1;
}

void	raycasting(t_data *data)
{
	t_raycasting	ray;
	int				x;

	x = 0;
	init_ray(&ray, data);
	if (!F_C_TEXTURE)
		fill_background(data);
	while (x < (double)WIN_WIDTH)
	{
		ray.map_x = (int)ray.pos_x;
		ray.map_y = (int)ray.pos_y;
		ray.camera_x = 2 * x / (double)WIN_WIDTH - 1;
		ray.ray_dir_x = data->dir_x + ray.plane_x * ray.camera_x;
		ray.ray_dir_y = data->dir_y + ray.plane_y * ray.camera_x;
		set_delta(&ray);
		set_side_dist(&ray);
		find_wall(&ray, data);
		calculate_ray(&ray, data);
		render_vertical_line(x, &ray, data);
		if (F_C_TEXTURE)
			render_floor_ceiling(data, &ray, x);
		x++;
	}
}
