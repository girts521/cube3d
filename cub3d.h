#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include ".MLX42/include/MLX42/MLX42.h"
# include "libft/libft.h"

# define WIN_WIDTH 640
# define WIN_HEIGHT 480

typedef enum texture
{
	NO,
	SO,
	WE,
	EA,
	F,
	C
}	t_texture;

typedef struct s_map
{
	char	**grid;
	int		height;
	int		width;
}	t_map;

typedef struct s_data
{
	mlx_t		*mlx;
	mlx_image_t	*img[6];
	t_map		map;
	int			player[3];
}	t_data;

void	parse_input(t_data *data, char *argv[]);
int		clean(t_data *data, char *err_mess, int status, int fd);

#endif
