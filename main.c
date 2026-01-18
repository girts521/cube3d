#include "cub3d.h"

void	game_loop(void *param);

static void	init_data(t_data *data)
{
	int	i;

	data->mlx = NULL;
	data->player[0] = -1;
	data->player[1] = -1;
	data->player[2] = -1;
	data->map.height = 0;
	data->map.width = 0;
	data->map.grid = NULL;
	data->speed = MOVE_SPEED;
	data->move_mult = 1.0;
	data->dodge_timer = 0;
	i = -1;
	while (++i < N_TEXTURES)
		data->img[i] = NULL;
	i = -1;
	while (++i < 3)
	{
		data->floor[i] = 0;
		data->ceiling[i] = 0;
	}
}

static void	init_floor_ceiling(t_data *data)
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

static void	cross_handler(void *ptr)
{
	t_data	*data;

	data = (t_data *) ptr;
	clean(data, NULL, 0, -1);
}

static void	key_handler(mlx_key_data_t keydata, void *param)
{
	t_data	*data;

	if (keydata.action == 1)
	{
		data = (t_data *)param;
		if (keydata.key == 256)
			clean(data, NULL, 0, -1);
	}
}

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc != 2)
		return (clean(NULL, "Wrong num of args\n", 1, -1));
	init_data(&data);
	data.mlx = mlx_init(WIN_WIDTH, WIN_HEIGHT, "cub3d", true);
	if (!data.mlx)
		return (1);
	mlx_set_cursor_mode(data.mlx, MLX_MOUSE_HIDDEN); // Still appears on my end??
	mlx_set_mouse_pos(data.mlx, WIN_WIDTH / 2, WIN_HEIGHT / 2);
	data.screen = mlx_new_image(data.mlx, WIN_WIDTH, WIN_HEIGHT);
	parse_input(&data, argv);
	if (F_C_TEXTURE)
		init_floor_ceiling(&data);
	mlx_image_to_window(data.mlx, data.screen, 0, 0);

	// print map
	printf("height: %d, width: %d\n", data.map.height, data.map.width);
	for (int i = 0; i < data.map.height; i++)
	{
		if (i < 10)
			printf("\n|%d| :", i);
		else
			printf("\n|%d|:", i);
		for (int i2 = 0; i2 < data.map.width; i2++)
			printf("%c", data.map.grid[i][i2]);
		printf("|");
	}
	printf("\n\nplayer: y=%f , x=%f , direction=%f\n", data.player[1], data.player[0], data.player[2]);
	printf("\nF: %d, %d, %d \nC: %d, %d, %d\n", data.floor[0], data.floor[1], data.floor[2],
			data.ceiling[0], data.ceiling[1], data.ceiling[2]);


	mlx_loop_hook(data.mlx, game_loop, &data);
	mlx_key_hook(data.mlx, key_handler, &data);
	mlx_close_hook(data.mlx, cross_handler, &data);
	mlx_loop(data.mlx);

	clean(&data, NULL, 0, -1);
}
