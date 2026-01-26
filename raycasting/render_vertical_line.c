#include "../cub3d.h"
#include "raycasting.h"

uint32_t	apply_color_tint(uint32_t color, double factor);
void		put_pixel(mlx_image_t *image, uint32_t x, uint32_t y,
				uint32_t color);

uint32_t	get_texture_pixel(mlx_texture_t *tex, int x, int y)
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

static mlx_texture_t	*get_wall_texture(t_data *data, t_raycasting *ray)
{
	if (ray->side == 0)
	{
		if (ray->ray_dir_x > 0)
			return (data->img[WE]);
		return (data->img[EA]);
	}
	if (ray->ray_dir_y > 0)
		return (data->img[NO]);
	return (data->img[SO]);
}

static int	calculate_tex_x(t_raycasting *ray, mlx_texture_t *tex)
{
	double	wall_x;
	int		tex_x;

	if (ray->side == 0)
		wall_x = ray->pos_y + ray->perp_wall_dist * ray->ray_dir_y;
	else
		wall_x = ray->pos_x + ray->perp_wall_dist * ray->ray_dir_x;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * (double)tex->width);
	if ((ray->side == 0 && ray->ray_dir_x > 0)
		|| (ray->side == 1 && ray->ray_dir_y < 0))
		tex_x = tex->width - tex_x - 1;
	return (tex_x);
}

static void	draw_wall_stripe(t_data *data, t_raycasting *ray, int x, int texX)
{
	t_stripe	st;

	st.tex = get_wall_texture(data, ray);
	st.step = 1.0 * st.tex->height / ray->line_height;
	st.tex_pos = (ray->draw_start - (data->c.bob_pitch + data->c.pitch) - WIN_HEIGHT
			/ 2 + ray->line_height * (1.0 - data->c.cam_height)) * st.step;
	st.y = ray->draw_start;
	while (st.y < ray->draw_end)
	{
		st.tex_y = (int)st.tex_pos & (st.tex->height - 1);
		st.tex_pos += st.step;
		st.color = get_texture_pixel(st.tex, texX, st.tex_y);
		if (ray->side == 1)
			st.color = apply_color_tint(st.color, TINT_FACTOR);
		if (st.y >= 0 && st.y < WIN_HEIGHT)
			put_pixel(data->screen, x, st.y, st.color);
		st.y++;
	}
}

void	render_vertical_line(int x, t_raycasting *ray, t_data *data)
{
	mlx_texture_t	*tex;
	int				tex_x;

	if (ray->map_x < 0 || ray->map_x >= data->map.width
		|| ray->map_y < 0 || ray->map_y >= data->map.height)
		return ;
	if (x < 0 || x >= WIN_WIDTH)
		return ;
	tex = get_wall_texture(data, ray);
	tex_x = calculate_tex_x(ray, tex);
	draw_wall_stripe(data, ray, x, tex_x);
}
