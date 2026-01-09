#include "cub3d.h"

int	clean(t_data *data, char *err_mess, int status, int fd)
{
	if (data)
	{
		//clean

		mlx_close_window(data->mlx);
		mlx_terminate(data->mlx);
	}
	if (err_mess)
		printf("\nError\n%s", err_mess);
	if (fd != -1)
		close(fd);
	exit(status);
}
