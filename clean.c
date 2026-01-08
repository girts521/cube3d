#include "cub3d.h"

int	clean(t_data *data, char *err_mess, int status)
{
	if (data)
	{
		//clean

		mlx_close_window(data->mlx);
		mlx_terminate(data->mlx);
	}
	if (err_mess)
		printf("Error\n%s", err_mess);
	return (status);
}
