#include "../cub3d.h"

void	rotation(t_data *data);
void	movement(t_data *data);
void	head_bob(t_data *data);

void	game_loop(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	rotation(data);
	movement(data);
	head_bob(data);
	raycasting(data);
}
