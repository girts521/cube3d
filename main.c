#include "cub3d.h"



static void	init_data(t_data *data)
{
	int	i;

	data->mlx = NULL;
	data->player[0] = -1;
	data->player[1] = -1;
	data->player[2] = -1;
	data->map.height = 0;
	data->map.width = 0;
	i = -1;
	while (++i < 6)
		data->img[i] = NULL;
}



static void	cross_handler(void *ptr)
{
	t_data	*data;

	data = (t_data *) ptr;

	// mlx_close_window(data->mlx);
	// mlx_terminate(data->mlx);

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
			// mlx_close_window(data->mlx);
			// mlx_terminate(data->mlx);
			clean(data, NULL, 0, -1);
		}
	}
}

int	main(int argc, char *argv[])
{
	t_data	data;
	(void) argv;
	if (argc != 2)
		return (clean(NULL, "Wrong num of args\n", 1, -1));
	init_data(&data);
	data.mlx = mlx_init(WIN_WIDTH, WIN_HEIGHT, "cub3d", true);
	parse_input(&data, argv);


	// for (int i = 0; i < 6; i++)
	// 	printf("%p\n", data.img[i]);
	mlx_image_to_window(data.mlx, data.img[0], 0, 0);

	// print map
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
	printf("\n\nplayer: y=%d , x=%d , direction=%d\n", data.player[0], data.player[1], data.player[2]);
	//
	

	mlx_key_hook(data.mlx, key_handler, &data);
	mlx_close_hook(data.mlx, cross_handler, &data);
	mlx_loop(data.mlx);

	//mlx_terminate(data.mlx);
}
