#include "cub3d.h"

void	game_loop(void *param);
void	key_handler(mlx_key_data_t keydata, void *param);
void	init_floor_ceiling(t_data *data);
void	init_anim_textures(t_data *data, int img_id);
void	init_audio(t_data *data);
void	init_hud(t_data *data);
void	init_data(t_data *data);

static void	cross_handler(void *ptr)
{
	t_data	*data;

	data = (t_data *) ptr;
	clean(data, NULL, 0, -1);
}

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc != 2)
	{
		printf("\nError\nWrong num of args\n");
		return (1);
	}
	init_data(&data);
	data.mlx = mlx_init(WIN_WIDTH, WIN_HEIGHT, "cub3d", true);
	if (!data.mlx)
		return (1);
	init_audio(&data);
	init_hud(&data);
	mlx_set_cursor_mode(data.mlx, MLX_MOUSE_HIDDEN);
	//mlx_set_mouse_pos(data.mlx, WIN_WIDTH / 2, WIN_HEIGHT / 2);
	data.screen = mlx_new_image(data.mlx, WIN_WIDTH, WIN_HEIGHT);
	parse_input(&data, argv);
	if (F_C_TEXTURE)
		init_floor_ceiling(&data);
	mlx_image_to_window(data.mlx, data.screen, 0, 0);

	init_anim_textures(&data, EA);
	//init_anim_textures(&data, S_BAR);


	mlx_loop_hook(data.mlx, game_loop, &data);
	mlx_key_hook(data.mlx, key_handler, &data);
	mlx_close_hook(data.mlx, cross_handler, &data);
	mlx_loop(data.mlx);

	clean(&data, NULL, 0, -1);
}

// // print map
// 	printf("height: %d, width: %d\n", data.map.height, data.map.width);
// 	for (int i = 0; i < data.map.height; i++)
// 	{
// 		if (i < 10)
// 			printf("\n|%d| :", i);
// 		else
// 			printf("\n|%d|:", i);
// 		for (int i2 = 0; i2 < data.map.width; i2++)
// 			printf("%c", data.map.grid[i][i2]);
// 		printf("|");
// 	}
// 	printf("\n\nplayer: y=%f , x=%f , direction=%f\n", data.player[1], data.player[0], data.player[2]);
// 	printf("\nF: %d, %d, %d \nC: %d, %d, %d\n", data.floor[0], data.floor[1], data.floor[2],
// 			data.ceiling[0], data.ceiling[1], data.ceiling[2]);
