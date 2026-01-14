#include "cub3d.h"

#define ROT_SPEED 0.05
#define MOVE_SPEED 0.05

static void	init_data(t_data *data)
{
	int	i;

	data->mlx = NULL;
	data->player[0] = 22;
	data->player[1] = 12;
	data->player[2] = -1;
	data->map.height = 0;
	data->map.width = 0;
	data->map.grid = NULL;
  //FIX: This has to be done by parser:
  data->dir_x = 0;
  data->dir_y = -1;
	i = -1;
	while (++i < 6)
		data->img[i] = NULL;
}



static void	cross_handler(void *ptr)
{
	t_data	*data;

	data = (t_data *) ptr;
	printf("exit (cross) triggered\n");
	clean(data, NULL, 0, -1);
}

static void	key_handler(mlx_key_data_t keydata, void *param)
{
	t_data	*data;

	if (keydata.action == 1)
	{
		printf("Key detected\n");
		data = (t_data *)param;
		// if (keydata.key == 'W')
		// 	ft_move(data, -1, 0);
		// if (keydata.key == 'S')
		// 	ft_move(data, 1, 0);
		// if (keydata.key == 'A')
		// 	ft_move(data, 0, -1);
		// if (keydata.key == 'D')
		// 	ft_move(data, 0, 1);
		if (keydata.key == 256)
		{
			printf("Escape triggered\n");
			clean(data, NULL, 0, -1);
		}
	}
}

void game_loop(void *param)
{
    t_data *data = (t_data *)param;

    // Rotation
    if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT)) {
        double oldDirX = data->dir_x;
        data->dir_x = data->dir_x * cos(ROT_SPEED) - data->dir_y * sin(ROT_SPEED);
        data->dir_y = oldDirX * sin(ROT_SPEED) + data->dir_y * cos(ROT_SPEED);
        double oldPlaneX = data->plane_x;
        data->plane_x = data->plane_x * cos(ROT_SPEED) - data->plane_y * sin(ROT_SPEED);
        data->plane_y = oldPlaneX * sin(ROT_SPEED) + data->plane_y * cos(ROT_SPEED);
    }
    if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT)) {
        double oldDirX = data->dir_x;
        data->dir_x = data->dir_x * cos(-ROT_SPEED) - data->dir_y * sin(-ROT_SPEED);
        data->dir_y = oldDirX * sin(-ROT_SPEED) + data->dir_y * cos(-ROT_SPEED);
        double oldPlaneX = data->plane_x;
        data->plane_x = data->plane_x * cos(-ROT_SPEED) - data->plane_y * sin(-ROT_SPEED);
        data->plane_y = oldPlaneX * sin(-ROT_SPEED) + data->plane_y * cos(-ROT_SPEED);
    }

    // Movement (Simple check, no collision for simplicity)
    if (mlx_is_key_down(data->mlx, MLX_KEY_W)) {
        data->player[0] += data->dir_x * MOVE_SPEED;
        data->player[1] += data->dir_y * MOVE_SPEED;
    }
    if (mlx_is_key_down(data->mlx, MLX_KEY_S)) {
        data->player[0] -= data->dir_x * MOVE_SPEED;
        data->player[1] -= data->dir_y * MOVE_SPEED;
    }

    raycasting(data);
}

int	main(int argc, char *argv[])
{
	t_data	data;
	(void) argv;
	if (argc != 2)
		return (clean(NULL, "Wrong num of args\n", 1, -1));
	init_data(&data);
	data.mlx = mlx_init(WIN_WIDTH, WIN_HEIGHT, "cub3d", true);
  if (!data.mlx) return (1);
  data.img[0] = mlx_new_image(data.mlx, WIN_WIDTH, WIN_HEIGHT);
  mlx_image_to_window(data.mlx, data.img[0], 0, 0);

	// parse_input(&data, argv);
  game_loop(&data);

	// for (int i = 0; i < 6; i++)
	// 	printf("%p\n", data.img[i]);
	// mlx_image_to_window(data.mlx, data.img[0], 0, 0);

	// print map
	// printf("height: %d, width: %d\n", data.map.height, data.map.width);
	// for (int i = 0; i < data.map.height; i++)
	// {
	// 	if (i < 10)
	// 		printf("\n|%d| :", i);
	// 	else
	// 		printf("\n|%d|:", i);
	// 	for (int i2 = 0; i2 < data.map.width; i2++)
	// 		printf("%c", data.map.grid[i][i2]);
	// 	printf("|");
	// }
	// printf("\n\nplayer: y=%d , x=%d , direction=%d\n", data.player[0], data.player[1], data.player[2]);
	//

  mlx_loop_hook(data.mlx, game_loop, &data);
	mlx_key_hook(data.mlx, key_handler, &data);
	mlx_close_hook(data.mlx, cross_handler, &data);
	mlx_loop(data.mlx);

	clean(&data, NULL, 0, -1);
}
