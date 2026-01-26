#include "../cub3d.h"

uint32_t	get_texture_pixel(mlx_texture_t *tex, int x, int y);
void		put_pixel(mlx_image_t *image, uint32_t x, uint32_t y,
				uint32_t color);

static void	compute_wall_intercept(t_raycasting *ray, t_wall_hit *hit)
{
	double	wall_x;

	if (ray->side == 0)
		wall_x = ray->pos_y + ray->perp_wall_dist * ray->ray_dir_y;
	else
		wall_x = ray->pos_x + ray->perp_wall_dist * ray->ray_dir_x;
	wall_x -= floor(wall_x);
	hit->x = ray->map_x + wall_x;
	hit->y = ray->map_y + wall_x;
	if (ray->side == 0)
	{
		hit->x = ray->map_x;
		if (ray->ray_dir_x < 0)
			hit->x += 1.0;
		hit->y = ray->map_y + wall_x;
	}
	else
	{
		hit->x = ray->map_x + wall_x;
		hit->y = ray->map_y;
		if (ray->ray_dir_y < 0)
			hit->y += 1.0;
	}
}

static void	draw_ceiling(t_data *data, t_raycasting *ray, t_wall_hit *hit,
		int x)
{
	int				y;
	double			weight;
	double			cur_dist;
	mlx_texture_t	*tex;
	uint32_t		color;

	y = 0;
	tex = data->img[C];
	while (y < ray->draw_start)
	{
		cur_dist = (WIN_HEIGHT * (1.0 - data->cam_height))
			/ (WIN_HEIGHT / 2.0 + (data->bob_pitch + data->pitch) - y);
		weight = cur_dist / ray->perp_wall_dist;
		color = get_texture_pixel(tex, (int)((weight * hit->x + (1.0 - weight)
						* ray->pos_x) * tex->width) % tex->width,
				(int)((weight * hit->y + (1.0 - weight) * ray->pos_y)
					* tex->height) % tex->height);
		put_pixel(data->screen, x, y, color);
		y++;
	}
}

static void	draw_floor(t_data *data, t_raycasting *ray, t_wall_hit *hit, int x)
{
	int				y;
	double			weight;
	double			cur_dist;
	mlx_texture_t	*tex;
	uint32_t		color;

	y = ray->draw_end;
	if (y < 0)
		y = 0;
	tex = data->img[F];
	while (y < WIN_HEIGHT)
	{
		cur_dist = (WIN_HEIGHT * data->cam_height)
			/ (y - WIN_HEIGHT / 2.0 - (data->bob_pitch + data->pitch));
		weight = cur_dist / ray->perp_wall_dist;
		color = get_texture_pixel(tex, (int)((weight * hit->x + (1.0 - weight)
						* ray->pos_x) * tex->width) % tex->width,
				(int)((weight * hit->y + (1.0 - weight) * ray->pos_y)
					* tex->height) % tex->height);
		put_pixel(data->screen, x, y, color);
		y++;
	}
}

void	render_floor_ceiling(t_data *data, t_raycasting *ray, int x)
{
	t_wall_hit	hit;

	compute_wall_intercept(ray, &hit);
	draw_ceiling(data, ray, &hit, x);
	draw_floor(data, ray, &hit, x);
}
