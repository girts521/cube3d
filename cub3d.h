#ifndef CUB3D_H
# define CUB3D_H

# include ".MLX42/include/MLX42/MLX42.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <sys/time.h>
#include ".miniaudio/miniaudio.h"


# define WIN_WIDTH 1280
# define WIN_HEIGHT 740

# define F_C_TEXTURE 1

# define N_TEXTURES 6

# define TINT_FACTOR 0.8f

# define ROT_SPEED 0.05
# define MOUSE_SENS 0.0005
# define MOVE_SPEED 0.03
//# define MOVE_SPEED 1.8

# define MAX_SPEED 1.7

# define HEAD_BOB 3.0
// 0.0 = off

# define CAM_POS_SPEED 0.015

typedef enum texture
{
	NO,
	SO,
	WE,
	EA,
	F,
	C
}	t_texture;

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
	mlx_image_t	*tex;
	double		step;
	double		tex_pos;
	int			tex_y;
	int			y;
	uint32_t	color;
}	t_stripe;

typedef struct s_wall_hit
{
	double	x;
	double	y;
}	t_wall_hit;

typedef struct s_map
{
	char	**grid;
	int		height;
	int		width;
}	t_map;

typedef struct s_data
{
	mlx_t		*mlx;
	ma_engine	audio_engine;
	mlx_image_t	*img[N_TEXTURES];
	mlx_image_t	*screen;
	int			floor[3];
	int			ceiling[3];
	t_map		map;
	double		player[3];
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		speed;
	int			crouch;
	int			dodge;
	int			jump;
	double		move_mult;
	int			dodge_timer;
	double		walk_timer;
	double		pitch;
	double		bob_pitch;
	double		cam_height;
	double		target_height;
	double		cam_speed_up;
	double		cam_speed_down;
	double		dt;
}	t_data;

void	parse_input(t_data *data, char *argv[]);
int		clean(t_data *data, char *err_mess, int status, int fd);
void	fill_background(t_data *data);
void	raycasting(t_data *data);

#endif
