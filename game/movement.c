#include "../cub3d.h"

static void	attempt_move(t_data *data, double move_x, double move_y)
{
	double	new_x;
	double	new_y;

	new_x = data->player[0] + move_x;
	new_y = data->player[1] + move_y;
	if (new_x < 0 || new_x >= data->map.width || new_y < 0
		|| new_y >= data->map.height)
		return ;
	if (data->map.grid[(int)data->player[1]][(int)new_x] == '0')
		data->player[0] += move_x;
	if (data->map.grid[(int)new_y][(int)data->player[0]] == '0')
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

void	head_bob(t_data *data)
{
	if (mlx_is_key_down(data->mlx, MLX_KEY_W)
		|| mlx_is_key_down(data->mlx, MLX_KEY_S)
		|| mlx_is_key_down(data->mlx, MLX_KEY_A)
		|| mlx_is_key_down(data->mlx, MLX_KEY_D))
	{
		data->walk_timer += 0.1 * data->move_mult;
		data->pitch = sin(data->walk_timer) * HEAD_BOB;
	}
	else
	{
		data->pitch = 0;
		data->walk_timer = 0;
	}
}

static void	handle_dodge(t_data *data)
{
	if (data->dodge_timer != 0)
		data->dodge_timer--;
	if (!data->dodge)
		return ;
	if (data->move_mult > MAX_SPEED)
	{
		data->move_mult -= 0.2;
		data->pitch = 0;
		data->walk_timer = 0;
	}
	else
	{
		data->dodge = 0;
		data->dodge_timer = 60;
		if (data->crouch != 1)
			data->target_height = 0.5;
	}
}

void	movement(t_data *data)
{
	double	speed;

	handle_dodge(data);
	if (data->move_mult <= MAX_SPEED)
		sprint(data);
	speed = data->speed * data->move_mult;
	//speed = (data->speed * data->move_mult) * data->dt;
	if (mlx_is_key_down(data->mlx, MLX_KEY_W))
		attempt_move(data, data->dir_x * speed,
			data->dir_y * speed);
	if (mlx_is_key_down(data->mlx, MLX_KEY_S))
		attempt_move(data, -data->dir_x * speed,
			-data->dir_y * speed);
	if (mlx_is_key_down(data->mlx, MLX_KEY_D))
		attempt_move(data, -data->dir_y * (speed / 2.5),
			data->dir_x * (speed / 2.5));
	if (mlx_is_key_down(data->mlx, MLX_KEY_A))
		attempt_move(data, data->dir_y * (speed / 2.5),
			-data->dir_x * (speed / 2.5));
}
