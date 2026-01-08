#include "cub3d.h"



static void	init_data(t_data *data)
{
	int	i;

	data->mlx = NULL;
	data->map.player_pos[0] = -1;
	data->map.player_pos[1] = -1;
	data->map.player_pos[2] = -1;
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
	exit(clean(data, NULL, 0));
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
			exit(clean(data, NULL, 0));
		}
	}
}

int	main(int argc, char *argv[])
{
	t_data	data;
	(void) argv;
	if (argc != 2)
		return (clean(NULL, "Wrong num of args\n", 1));
	init_data(&data);

	data.mlx = mlx_init(WIN_WIDTH, WIN_WIDTH, "cub3d", true);

	mlx_key_hook(data.mlx, key_handler, &data);
	mlx_close_hook(data.mlx, cross_handler, &data);
	mlx_loop(data.mlx);

	//mlx_terminate(data.mlx);
}
