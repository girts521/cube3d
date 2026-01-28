#include "../cub3d.h"

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
	int				i;
	char			buf[100];

	i = -1;
	while (++i < N_ANIM_TEXTURES)
	{
		form_path("textures/main/anim/", img_id, i, buf);
		data->anim_img[img_id][i] = mlx_load_png(buf);
		if (!data->anim_img[img_id][i])
			clean(data, "load anim failed\n", 1, -1);
	}
	mlx_delete_texture(data->img[img_id]);
	data->img[img_id] = data->anim_img[img_id][0];
}

void	init_audio(t_data *data)
{
	if (ma_engine_init(NULL, &data->s.audio_engine) != MA_SUCCESS)
		clean(data, "miniaudio init failed\n", 1, -1);
	ma_sound_init_from_file(&data->s.audio_engine, "audio/music.mp3", 0,
		NULL, NULL, &data->s.music);
	ma_sound_set_volume(&data->s.music, 0.35f);
	ma_sound_set_looping(&data->s.music, MA_TRUE);
	ma_sound_start(&data->s.music);
	ma_sound_init_from_file(&data->s.audio_engine, "audio/walking.mp3",
		0, NULL, NULL, &data->s.walk);
	ma_sound_set_looping(&data->s.walk, MA_TRUE);
	ma_sound_set_volume(&data->s.walk, 4.5f);
	ma_sound_init_from_file(&data->s.audio_engine, "audio/dodge.mp3",
		0, NULL, NULL, &data->s.dodge);
	ma_sound_set_looping(&data->s.dodge, MA_FALSE);
	ma_sound_set_volume(&data->s.dodge, 0.6f);
	ma_sound_init_from_file(&data->s.audio_engine, "audio/jump_2.mp3",
		0, NULL, NULL, &data->s.jump);
	ma_sound_set_looping(&data->s.jump, MA_FALSE);
	ma_sound_set_volume(&data->s.jump, 0.25f);
}

void	init_hud(t_data *data)
{
	data->hud.bar_x_start = WIN_WIDTH * 0.78;
	data->hud.bar_y_start = WIN_HEIGHT * 0.94;
	data->hud.bar_total_w = WIN_WIDTH * 0.20;
	data->hud.bar_h = WIN_HEIGHT * 0.05;
	data->img[S_BAR] = mlx_load_png("textures/main/s_bar.png");
	if (!data->img[S_BAR])
		clean(data, "load s_bar failed\n", 1, -1);
}
