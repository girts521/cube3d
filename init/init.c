#include "../cub3d.h"

void	init_floor_ceiling(t_data *data)
{
	data->img[C] = mlx_load_png("textures/main/C.png");
	if (!data->img[C])
		clean(data, "load ceiling failed\n", 1, -1);
	data->img[F] = mlx_load_png("textures/main/F8.png");
	if (!data->img[F])
		clean(data, "load floor failed\n", 1, -1);
}

static void	init_game_data(t_data *data)
{
	data->speed = MOVE_SPEED;
	data->stamina = 1.00;
	data->crouch = -1;
	data->dodge = 0;
	data->jump = 0;
	data->move_mult = 1.0;
	data->dodge_timer = 0;
	data->c.cam_height = 0.5;
	data->c.target_height = 0.5;
	data->c.cam_speed_up = CAM_POS_SPEED;
	data->c.cam_speed_down = CAM_POS_SPEED;
	data->last_anim_time = mlx_get_time();
	data->current_anim_frame = -1;
}

void	init_data(t_data *data)
{
	int	i;

	data->mlx = NULL;
	data->player[0] = -1;
	data->player[1] = -1;
	data->player[2] = -1;
	data->map.height = 0;
	data->map.width = 0;
	data->map.grid = NULL;
	init_game_data(data);
	i = -1;
	while (++i < N_TEXTURES)
	{
		data->img[i] = NULL;
		data->anim_img[i][0] = NULL;
	}
	i = -1;
	while (++i < 3)
	{
		data->floor[i] = 0;
		data->ceiling[i] = 0;
	}
}
