#include "../cub3d.h"

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

static void	handle_mouse(t_data *data)
{
	int32_t	x;
	int32_t	y;
	int		delta_x;

	mlx_get_mouse_pos(data->mlx, &x, &y);
	delta_x = x - (WIN_WIDTH / 2);
	if (delta_x != 0)
	{
		rotate_player(data, delta_x * MOUSE_SENS);
		mlx_set_mouse_pos(data->mlx, WIN_WIDTH / 2, WIN_HEIGHT / 2);
	}
}

void	rotation(t_data *data)
{
	handle_mouse(data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
		rotate_player(data, ROT_SPEED);
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
		rotate_player(data, -ROT_SPEED);
}
