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

uint32_t	get_texture_pixel(mlx_image_t *tex, int x, int y)
{
	int	index;

	if (x < 0 || x >= (int)tex->width || y < 0 || y >= (int)tex->height)
		return (0x000000FF);
	index = (y * tex->width + x) * 4;
	return ((tex->pixels[index] << 24)
		| (tex->pixels[index + 1] << 16)
		| (tex->pixels[index + 2] << 8)
		| (tex->pixels[index + 3]));
}

void	init_ray(t_raycasting *ray, t_data *data)
{
	ray->side = 0;
	ray->pos_x = data->player[0];
	ray->pos_y = data->player[1];
	ray->plane_x = -data->dir_y * 0.66;
	ray->plane_y = data->dir_x * 0.66;
	ray->time = 0;
	ray->oldTime = 0;
	ray->mapY = (int)ray->pos_y;
	ray->mapX = (int)ray->pos_x;
}

void	set_delta(t_raycasting *ray)
{
	if (ray->rayDirX == 0)
		ray->deltaDistX = 1e30;
	else
		ray->deltaDistX = fabs(1 / ray->rayDirX);
	if (ray->rayDirY == 0)
		ray->deltaDistY = 1e30;
	else
		ray->deltaDistY = fabs(1 / ray->rayDirY);
}

void	set_sideDist(t_raycasting *ray)
{
	if (ray->rayDirX < 0)
	{
		ray->stepX = -1;
		ray->sideDistX = (ray->pos_x - ray->mapX) * ray->deltaDistX;
	}
	else
	{
		ray->stepX = 1;
		ray->sideDistX = (ray->mapX + 1.0 - ray->pos_x) * ray->deltaDistX;
	}
	if (ray->rayDirY < 0)
	{
		ray->stepY = -1;
		ray->sideDistY = (ray->pos_y - ray->mapY) * ray->deltaDistY;
	}
	else
	{
		ray->stepY = 1;
		ray->sideDistY = (ray->mapY + 1.0 - ray->pos_y) * ray->deltaDistY;
	}
}
