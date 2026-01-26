#include "../cub3d.h"

void	rotation(t_data *data);
void	movement(t_data *data);
void	audio(t_data *data);
void	hud(t_data *data);

// static void	fps(void)
// {
// 	static int				frame = 0;
// 	static struct timeval	start;
// 	struct timeval			now;
// 	static int				is_init = 0;

// 	if (!is_init)
// 	{
// 		gettimeofday(&start, NULL);
// 		is_init = 1;
// 	}
// 	gettimeofday(&now, NULL);
// 	frame++;
// 	if (now.tv_sec - start.tv_sec >= 1)
// 	{
// 		printf("FPS: %d\n", frame);
// 		frame = 0;
// 		start = now;
// 	}
// }



void track_time(t_data *data)
{
	// Static variables persist across function calls
	static struct timeval   last_frame_time;
	static struct timeval   fps_start_time;
	static int              frame_count = 0;
	static int              is_init = 0;
	struct timeval          current_time;

	gettimeofday(&current_time, NULL);

	// 1. One-time Initialization (replaces setup in main)
	if (!is_init)
	{
		last_frame_time = current_time;
		fps_start_time = current_time;
		is_init = 1;
	}

	// 2. Calculate Delta Time (dt) for Movement
	//    We compare NOW vs LAST FRAME (happens every loop)
	long long seconds = current_time.tv_sec - last_frame_time.tv_sec;
	long long microseconds = current_time.tv_usec - last_frame_time.tv_usec;

	data->dt = seconds + (microseconds / 1000000.0);
	if (data->dt > 0.1)
	{
		printf("LAG SPIKE DETECTED: dt was %.4f!\n", data->dt);
		data->dt = 0.1;
	}


	// Update last_frame_time immediately for the next loop
	last_frame_time = current_time;

	// 3. FPS Counter (happens once per second)
	//    We compare NOW vs FPS START TIME
	frame_count++;
	if (current_time.tv_sec - fps_start_time.tv_sec >= 1)
	{
		printf("FPS: %d | dt: %.5f\n", frame_count, data->dt);
		frame_count = 0;
		fps_start_time = current_time; // Reset only the FPS timer
	}
}

static void	head_bob(t_data *data)
{
	if (mlx_is_key_down(data->mlx, MLX_KEY_W)
		|| mlx_is_key_down(data->mlx, MLX_KEY_S)
		|| mlx_is_key_down(data->mlx, MLX_KEY_A)
		|| mlx_is_key_down(data->mlx, MLX_KEY_D))
	{
		data->walk_timer += 0.1 * data->move_mult;
		data->bob_pitch = sin(data->walk_timer) * HEAD_BOB;
	}
	else
	{
		data->bob_pitch = 0;
		data->walk_timer = 0;
	}
}

static void	cam_height_transition (t_data *data)
{
	if (data->cam_height < data->target_height)
		data->cam_height += data->cam_speed_up;
	else if (data->cam_height > data->target_height)
		data->cam_height -= data->cam_speed_down;
	if (fabs(data->cam_height - data->target_height) < CAM_POS_SPEED)
		data->cam_height = data->target_height;
}

void	animate(t_data *data)
{
	static int			current_frame = -1;
	double				now;

	now = mlx_get_time();
	if (now - data->last_anim_time > 0.11)
	{
		current_frame++;
		if (current_frame >= N_ANIM_TEXTURES)
			current_frame = 0;
		data->img[EA] = data->anim_img[EA][current_frame];
		//data->img[S_BAR] = data->anim_img[S_BAR][current_frame];
		data->last_anim_time = now;
	}
}

void	game_loop(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	audio(data);
	track_time(data);
	rotation(data);
	movement(data);
	cam_height_transition(data);
	head_bob(data);
	animate(data);
	raycasting(data);
	hud(data);
	//fps();
}
//printf("speed: %f, move_mult: %f\n", data->speed, data->move_mult);
