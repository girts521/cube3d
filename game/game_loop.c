#include "../cub3d.h"

void	rotation(t_data *data);
void	movement(t_data *data);
void	head_bob(t_data *data);

static void	fps(void)
{
	static int				frame = 0;
	static struct timeval	start;
	struct timeval			now;
	static int				is_init = 0;

	if (!is_init)
	{
		gettimeofday(&start, NULL);
		is_init = 1;
	}
	gettimeofday(&now, NULL);
	frame++;
	if (now.tv_sec - start.tv_sec >= 1)
	{
		printf("FPS: %d\n", frame);
		frame = 0;
		start = now;
	}
}

void	game_loop(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	rotation(data);
	movement(data);
	head_bob(data);
	raycasting(data);
	fps();
}

// #include <time.h>
// static void fps_2(void)
// {
// 	static int		frame = 0;
// 	static time_t	start_time = 0;
// 	time_t			current_time;

// 	if (start_time == 0)
// 		start_time = time(NULL);
// 	current_time = time(NULL);
// 	frame++;
// 	if (current_time - start_time >= 1)
// 	{
// 		printf("FPS crude: %d\n", frame);
// 		frame = 0;
// 		start_time = current_time;
// 	}
// }
