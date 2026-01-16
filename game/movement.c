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

static void	sprint(t_data *data)
{
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT_SHIFT))
	{
		data->move_mult += 0.01;
		if (data->move_mult > MAX_SPEED)
			data->move_mult = MAX_SPEED;
	}
	else
	{
		data->move_mult -= 0.04;
		if (data->move_mult < 1.0)
			data->move_mult = 1.0;
	}
}

void	dodge(t_data *data)
{
	if (mlx_is_key_down(data->mlx, MLX_KEY_SPACE)
		&& data->dodge_timer == 0)
	{
		data->move_mult += 4.5;
		data->dodge_timer = 60;
	}
	if (data->dodge_timer > 0)
		data->dodge_timer--;
	if (data->move_mult > MAX_SPEED)
		data->move_mult -= 0.2;
}

void	movement(t_data *data)
{
	double	speed;

	dodge(data);
	if (data->move_mult <= MAX_SPEED)
		sprint(data);
	speed = MOVE_SPEED * data->move_mult;
	if (mlx_is_key_down(data->mlx, MLX_KEY_W))
		attempt_move(data, data->dir_x * speed,
			data->dir_y * speed);
	if (mlx_is_key_down(data->mlx, MLX_KEY_S))
		attempt_move(data, -data->dir_x * speed,
			-data->dir_y * speed);
	if (mlx_is_key_down(data->mlx, MLX_KEY_D))
		attempt_move(data, -data->dir_y * speed,
			data->dir_x * speed);
	if (mlx_is_key_down(data->mlx, MLX_KEY_A))
		attempt_move(data, data->dir_y * speed,
			-data->dir_x * speed);
}
