#include "cub3d.h"

static void	rotate_player(t_data *data, double speed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->dir_x;
	data->dir_x = data->dir_x * cos(speed) - data->dir_y
		* sin(speed);
	data->dir_y = old_dir_x * sin(speed) + data->dir_y
		* cos(speed);
	old_plane_x = data->plane_x;
	data->plane_x = data->plane_x * cos(speed)
		- data->plane_y * sin(speed);
	data->plane_y = old_plane_x * sin(speed)
		+ data->plane_y * cos(speed);
}

static void	move_player(t_data *data, double speed)
{
	if (data->map.grid[(int)data->player[1]][
		(int)(data->player[0]
		+ data->dir_x * speed)] == '0')
		data->player[0] += data->dir_x * speed;
	if (data->map.grid[(int)(data->player[1] + data->dir_y
			* speed)][(int)data->player[0]] == '0')
		data->player[1] += data->dir_y * speed;
}

void	game_loop(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
		rotate_player(data, ROT_SPEED);
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
		rotate_player(data, -ROT_SPEED);
	if (mlx_is_key_down(data->mlx, MLX_KEY_W))
		move_player(data, MOVE_SPEED);
	if (mlx_is_key_down(data->mlx, MLX_KEY_S))
		move_player(data, -MOVE_SPEED);
	raycasting(data);
}
