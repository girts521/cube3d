#ifndef CUB3D_H
# define CUB3D_H

# include ".MLX42/include/MLX42/MLX42.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

# define WIN_WIDTH 1280
# define WIN_HEIGHT 740

# define N_TEXTURES 4

# define TINT_FACTOR 0.8f

typedef enum texture
{
	NO,
	SO,
	WE,
	EA
}	t_texture;

typedef struct s_raycasting
{
	double	pos_x;
	double	pos_y;
	double	plane_x;
	double	plane_y;
	double	time;
	double	oldTime;
	double	cameraX;
	double	rayDirX;
	double	rayDirY;
	int		mapX;
	int		mapY;
	double	sideDistX;
	double	sideDistY;
	double	deltaDistX;
	double	deltaDistY;
	int		stepX;
	int		stepY;
	int		side;
	double	perpWallDist;
	int		lineHeight;
	int		drawStart;
	int		drawEnd;
	int		color;
	char	wall_type;
}	t_raycasting;

typedef struct s_stripe
{
	mlx_image_t	*tex;
	double		step;
	double		tex_pos;
	int			tex_y;
	int			y;
	uint32_t	color;
}	t_stripe;

typedef struct s_map
{
	char	**grid;
	int		height;
	int		width;
}	t_map;

typedef struct s_data
{
	mlx_t		*mlx;
	mlx_image_t	*img[N_TEXTURES];
	mlx_image_t	*screen;
	int			floor[3];
	int			ceiling[3];
	t_map		map;
	double		player[3];
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;

}	t_data;

void	parse_input(t_data *data, char *argv[]);
int		clean(t_data *data, char *err_mess, int status, int fd);
void	fill_background(t_data *data);
void	raycasting(t_data *data);

#endif
