/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   audio.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afruhauf <afruhauf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 17:08:46 by afruhauf          #+#    #+#             */
/*   Updated: 2026/02/11 17:08:47 by afruhauf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		ma_sound_set_pitch(&data->s.walk, (float)data->move_mult);
		if (!ma_sound_is_playing(&data->s.walk))
			ma_sound_start(&data->s.walk);
	}
	else
	{
		if (ma_sound_is_playing(&data->s.walk))
		{
			ma_sound_stop(&data->s.walk);
			ma_sound_set_pitch(&data->s.walk, 1.0f);
			ma_sound_seek_to_pcm_frame(&data->s.walk, 0);
		}
	}
}
