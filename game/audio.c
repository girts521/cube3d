#include "../cub3d.h"

static int	is_moving(t_data *data)
{
	if (mlx_is_key_down(data->mlx, MLX_KEY_W)
		|| mlx_is_key_down(data->mlx, MLX_KEY_S)
		|| mlx_is_key_down(data->mlx, MLX_KEY_A)
		|| mlx_is_key_down(data->mlx, MLX_KEY_D))
		return (1);
	return (0);
}

void	audio(t_data *data)
{
	if (is_moving(data) && !data->dodge && !data->jump)
	{
		ma_sound_set_pitch(&data->sound_walk, (float)data->move_mult);
		if (!ma_sound_is_playing(&data->sound_walk))
			ma_sound_start(&data->sound_walk);
	}
	else
	{
		if (ma_sound_is_playing(&data->sound_walk))
		{
			ma_sound_stop(&data->sound_walk);
			ma_sound_set_pitch(&data->sound_walk, 1.0f);
			ma_sound_seek_to_pcm_frame(&data->sound_walk, 0);
		}
	}
}
