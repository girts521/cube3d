#include "../cub3d.h"

static void	crouch(t_data *data)
{
	data->crouch *= -1;
	if (data->crouch == 1)
	{
		data->target_height = 0.3;
		data->speed /= 2.5;
	}
	else
	{
		data->target_height = 0.5;
		data->speed = MOVE_SPEED;
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
	}
}
