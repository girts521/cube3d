#ifndef RAYCASTING_H
# define RAYCASTING_H

#include "../cub3d.h"

typedef struct s_raycasting
{
	double	pos_x;
	double	pos_y;
	double	plane_x;
	double	plane_y;
	double	time;
	double	old_time;
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	int		step_x;
	int		step_y;
	int		side;
	double	perp_wall_dist;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		color;
	char	wall_type;
}	t_raycasting;

typedef struct s_stripe
{
	mlx_texture_t	*tex;
	double			step;
	double			tex_pos;
	int				tex_y;
	int				y;
	uint32_t		color;
}	t_stripe;

typedef struct s_wall_hit
{
	double	x;
	double	y;
}	t_wall_hit;

#endif
