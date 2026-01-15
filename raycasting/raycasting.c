#include "../cub3d.h"

void		put_pixel(mlx_image_t *image, uint32_t x,
				uint32_t y, uint32_t color);
void		init_ray(t_raycasting *ray, t_data *data);
void		set_delta(t_raycasting *ray);
void		set_side_dist(t_raycasting *ray);
void		render_vertical_line(int x, t_raycasting *ray,
				t_data *data);

static void	advance_ray(t_raycasting *ray)
{
	if (ray->sideDistX < ray->sideDistY)
	{
		ray->sideDistX += ray->deltaDistX;
		ray->mapX += ray->stepX;
		ray->side = 0;
	}
	else
	{
		ray->sideDistY += ray->deltaDistY;
		ray->mapY += ray->stepY;
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
		if (ray->mapX < 0 || ray->mapX >= data->map.width
			|| ray->mapY < 0 || ray->mapY >= data->map.height)
		{
			hit = 1;
			break ;
		}
		if (data->map.grid[ray->mapY][ray->mapX] > '0')
			hit = 1;
	}
}
//printf("mapX: %d\n mapY: %d\n", ray->mapX, ray->mapY);

void	calculate_ray(t_raycasting *ray)
{
	if (ray->side == 0)
		ray->perpWallDist = (ray->sideDistX - ray->deltaDistX);
	else
		ray->perpWallDist = (ray->sideDistY - ray->deltaDistY);
	ray->lineHeight = (int)(WIN_HEIGHT / ray->perpWallDist);
	ray->drawStart = -ray->lineHeight / 2 + WIN_HEIGHT / 2;
	if (ray->drawStart < 0)
		ray->drawStart = 0;
	ray->drawEnd = ray->lineHeight / 2 + WIN_HEIGHT / 2;
	if (ray->drawEnd >= WIN_HEIGHT)
		ray->drawEnd = WIN_HEIGHT - 1;
}

void	raycasting(t_data *data)
{
	t_raycasting	ray;
	int				x;

	x = 0;
	init_ray(&ray, data);
	fill_background(data);
	while (x < (double)WIN_WIDTH)
	{
		ray.mapX = (int)ray.pos_x;
		ray.mapY = (int)ray.pos_y;
		ray.cameraX = 2 * x / (double)WIN_WIDTH - 1;
		ray.rayDirX = data->dir_x + ray.plane_x * ray.cameraX;
		ray.rayDirY = data->dir_y + ray.plane_y * ray.cameraX;
		set_delta(&ray);
		set_side_dist(&ray);
		find_wall(&ray, data);
		calculate_ray(&ray);
		render_vertical_line(x, &ray, data);
		x++;
	}
}
