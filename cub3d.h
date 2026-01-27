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

# define N_TEXTURES 7
# define N_ANIM_TEXTURES 25

# define TINT_FACTOR 0.8f

# define ROT_SPEED 0.05
# define HOR_SENS 0.00002f
# define VER_SENS 0.05
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
	C,
	S_BAR
}	t_texture;

typedef struct s_hud
{
	int	bar_x_start;
	int	bar_y_start;
	int	bar_total_w;
	int	bar_h;
	int	draw_width;
}	t_hud;

typedef struct s_map
{
	char	**grid;
	int		height;
	int		width;
}	t_map;

typedef struct s_sound
{
	ma_engine	audio_engine;
	ma_sound	music;
	ma_sound	walk;
	ma_sound	dodge;
	ma_sound	jump;
}	t_sound;

typedef struct s_cam
{
	double		pitch;
	double		bob_pitch;
	double		cam_height;
	double		target_height;
	double		cam_speed_up;
	double		cam_speed_down;
}	t_cam;

typedef struct s_data
{
	mlx_t		*mlx;
	mlx_texture_t	*img[N_TEXTURES];
	mlx_texture_t	*anim_img[N_TEXTURES][N_ANIM_TEXTURES];
	mlx_image_t	*screen;
	int			floor[3];
	int			ceiling[3];
	double		last_anim_time;
	double		player[3];
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		speed;
	double		stamina;
	int			crouch;
	int			dodge;
	int			jump;
	double		move_mult;
	int			dodge_timer;
	double		walk_timer;
	double		dt;
	int			current_anim_frame;
	t_map		map;
	t_hud		hud;
	t_sound		s;
	t_cam		c;
}	t_data;

void	parse_input(t_data *data, char *argv[]);
int		clean(t_data *data, char *err_mess, int status, int fd);
void	fill_background(t_data *data);
void	raycasting(t_data *data);

#endif
