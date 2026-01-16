#include "../cub3d.h"

static void	attempt_move(t_data *data, double move_x, double move_y)
{
	if (data->map.grid[(int)data->player[1]][
		(int)(data->player[0] + move_x)] == '0')
		data->player[0] += move_x;
	if (data->map.grid[(int)(data->player[1] + move_y)][
		(int)data->player[0]] == '0')
		data->player[1] += move_y;
}

void	movement(t_data *data)
{
	if (mlx_is_key_down(data->mlx, MLX_KEY_W))
		attempt_move(data, data->dir_x * MOVE_SPEED,
			data->dir_y * MOVE_SPEED);
	if (mlx_is_key_down(data->mlx, MLX_KEY_S))
		attempt_move(data, -data->dir_x * MOVE_SPEED,
			-data->dir_y * MOVE_SPEED);
	if (mlx_is_key_down(data->mlx, MLX_KEY_D))
		attempt_move(data, -data->dir_y * MOVE_SPEED,
			data->dir_x * MOVE_SPEED);
	if (mlx_is_key_down(data->mlx, MLX_KEY_A))
		attempt_move(data, data->dir_y * MOVE_SPEED,
			-data->dir_x * MOVE_SPEED);
}
