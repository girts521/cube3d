#include "cub3d.h"

void	init_floor_ceiling(t_data *data)
{
	mlx_texture_t	*t;

	t = mlx_load_png("textures/main/C.png");
	if (!t)
		clean(data, "load_png failed\n", 1, -1);
	data->img[C] = mlx_texture_to_image(data->mlx, t);
	if (!data->img[C])
	{
		mlx_delete_texture(t);
		clean(data, "load ceiling failed\n", 1, -1);
	}
	mlx_delete_texture(t);
	t = mlx_load_png("textures/main/F8.png");
	if (!t)
		clean(data, "load_png failed\n", 1, -1);
	data->img[F] = mlx_texture_to_image(data->mlx, t);
	if (!data->img[F])
	{
		mlx_delete_texture(t);
		clean(data, "load floor failed\n", 1, -1);
	}
	mlx_delete_texture(t);
}

static void	append_int(char *buf, int *idx, int n)
{
	if (n > 9)
		append_int(buf, idx, n / 10);
	buf[*idx] = (n % 10) + '0';
	(*idx)++;
}

static void	form_path(char *path, int folder, int file_name, char *buf)
{
	int	i;
	int	len;

	i = -1;
	len = ft_strlen(path);
	while (++i < len)
		buf[i] = path[i];
	append_int(buf, &i, folder);
	buf[i++] = '/';
	append_int(buf, &i, file_name);
	buf[i++] = '.';
	buf[i++] = 'p';
	buf[i++] = 'n';
	buf[i++] = 'g';
	buf[i] = '\0';
}

void	init_anim_textures(t_data *data, int img_id)
{
	mlx_texture_t	*t;
	int				i;
	char			buf[100];

	i = -1;
	while (++i < N_ANIM_TEXTURES)
	{
		form_path("textures/main/anim/", img_id, i, buf);
		t = mlx_load_png(buf);
		if (!t)
			clean(data, "load_png failed\n", 1, -1);
		data->anim_img[img_id][i] = mlx_texture_to_image(data->mlx, t);
		if (!data->anim_img[img_id][i])
		{
			mlx_delete_texture(t);
			clean(data, "load anim failed\n", 1, -1);
		}
		mlx_delete_texture(t);
	}
}

void	init_audio(t_data *data)
{
	if (ma_engine_init(NULL, &data->audio_engine) != MA_SUCCESS)
		clean(data, "miniaudio init failed\n", 1, -1);
	ma_sound_init_from_file(&data->audio_engine, "audio/elmshore.flac", 0,
		NULL, NULL, &data->sound_music);
	ma_sound_set_volume(&data->sound_music, 0.4f);
	ma_sound_set_looping(&data->sound_music, MA_TRUE);
	ma_sound_start(&data->sound_music);
	ma_sound_init_from_file(&data->audio_engine, "audio/walking.mp3",
		0, NULL, NULL, &data->sound_walk);
	ma_sound_set_looping(&data->sound_walk, MA_TRUE);
	ma_sound_set_volume(&data->sound_walk, 4.5f);
	ma_sound_init_from_file(&data->audio_engine, "audio/dodge.mp3",
		0, NULL, NULL, &data->sound_dodge);
	ma_sound_set_looping(&data->sound_dodge, MA_FALSE);
	ma_sound_set_volume(&data->sound_dodge, 0.6f);
	ma_sound_init_from_file(&data->audio_engine, "audio/jump.mp3",
		0, NULL, NULL, &data->sound_jump);
	ma_sound_set_looping(&data->sound_jump, MA_FALSE);
	ma_sound_set_volume(&data->sound_jump, 0.25f);
}

void	init_hud(t_data *data)
{
	mlx_texture_t	*t;

	data->hud.bar_x_start = WIN_WIDTH * 0.68;
	data->hud.bar_y_start = WIN_HEIGHT * 0.90;
	data->hud.bar_total_w = WIN_WIDTH * 0.30;
	data->hud.bar_h = WIN_HEIGHT * 0.05;
	t = mlx_load_png("textures/main/s_bar.png");
	if (!t)
		clean(data, "load_png failed\n", 1, -1);
	data->img[S_BAR] = mlx_texture_to_image(data->mlx, t);
	mlx_delete_texture(t);
}
