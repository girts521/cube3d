#include "../cub3d.h"

static void	crouch(t_data *data)
{
	data->crouch *= -1;
	if (data->crouch == 1)
	{
		data->target_height = 0.3;
		data->move_mult = 0.4;
	}
	else
	{
		data->target_height = 0.5;
		data->move_mult = 1.0;
	}
}

static void	dodge(t_data *data)
{
	if (!data->dodge && !data->dodge_timer && data->stamina >= 0.2)
	{
		//if (!ma_sound_is_playing(&data->sound_dodge))
		ma_sound_start(&data->sound_dodge);
		data->stamina -= 0.2;
		data->dodge = 1;
		data->dodge_timer = 60;
		data->move_mult += 4.5;
		if (data->crouch != 1 && data->jump == 0)
		{
			data->target_height = 0.2;
			data->cam_speed_down = 0.05;
		}
	}
}

static void	jump(t_data *data)
{
	if (!data->jump && data->stamina >= 0.15)
	{
		//if (!ma_sound_is_playing(&data->sound_jump))
		ma_sound_start(&data->sound_jump);
		data->stamina -= 0.15;
		data->jump = 1;
		data->target_height = data->cam_height + 0.45;
		data->cam_speed_up = 0.03;
		data->cam_speed_down = 0.01;
	}
}

void	key_handler(mlx_key_data_t keydata, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (keydata.action == MLX_PRESS)
	{
		if (keydata.key == MLX_KEY_ESCAPE)
			clean(data, NULL, 0, -1);
		if (keydata.key == MLX_KEY_C)
			crouch(data);
		if (keydata.key == MLX_KEY_V)
			dodge(data);
		if (keydata.key == MLX_KEY_SPACE)
			jump(data);
	}
}
