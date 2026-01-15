#include "../cub3d.h"
#include <math.h>

void	put_pixel(mlx_image_t* image, uint32_t x, uint32_t y, uint32_t color);

static uint32_t get_texture_pixel(mlx_image_t *tex, int x, int y)
{
  int index;

  if (x < 0 || x >= (int)tex->width || y < 0 || y >= (int)tex->height)
      return (0x000000FF);
  index = (y * tex->width + x) * 4;

  return (tex->pixels[index] << 24) |
          (tex->pixels[index + 1] << 16) |
          (tex->pixels[index + 2] << 8) |
          (tex->pixels[index + 3]);
}

void render_vertical_line(int x, t_raycasting *ray, t_data *data)
{
    mlx_image_t *tex;
    double      wallX;
    int         texX;
    int         texY;
    double      step;
    double      texPos;
    int         y;
    uint32_t    color;

    if (ray->mapX < 0 || ray->mapX >= data->map.width ||
        ray->mapY < 0 || ray->mapY >= data->map.height)
        return;

    if (ray->side == 0)
    {
      if (ray->rayDirX > 0)
        tex = data->img[WE];
      else
        tex = data->img[EA];
    }
    else
    {
      if (ray->rayDirY > 0)
        tex = data->img[NO];
      else
        tex = data->img[SO];
    }

    if (ray->side == 0)
        wallX = ray->pos_y + ray->perpWallDist * ray->rayDirY;
    else
        wallX = ray->pos_x + ray->perpWallDist * ray->rayDirX;

    wallX -= floor(wallX);

    texX = (int)(wallX * (double)tex->width);

    if (ray->side == 0 && ray->rayDirX > 0)
        texX = tex->width - texX - 1;
    if (ray->side == 1 && ray->rayDirY < 0)
        texX = tex->width - texX - 1;

    step = 1.0 * tex->height / ray->lineHeight;

    texPos = (ray->drawStart - WIN_HEIGHT / 2 + ray->lineHeight / 2) * step;

    y = ray->drawStart;
    if (x < 0 || x >= WIN_WIDTH) return;

    while (y < ray->drawEnd)
    {
        texY = (int)texPos & (tex->height - 1);
        texPos += step;

        color = get_texture_pixel(tex, texX, texY);

		if (ray->side == 1)
			color = TINT_COLOR(color, TINT_FACTOR);

        if (y >= 0 && y < WIN_HEIGHT)
            mlx_put_pixel(data->screen, x, y, color);
        y++;
    }
}

void init_ray(t_raycasting *ray, t_data *data)
{
  ray->side = 0;
  ray->pos_x = data->player[0];
  ray->pos_y = data->player[1];
  ray->plane_x = -data->dir_y * 0.66;
  ray->plane_y = data->dir_x * 0.66;
  ray->time = 0;
  ray->oldTime = 0;
  ray->mapY = (int)ray->pos_y;
  ray->mapX = (int)ray->pos_x;
}

void set_delta(t_raycasting *ray)
{
  if (ray->rayDirX == 0)
    ray->deltaDistX = 1e30;
  else
    ray->deltaDistX = fabs(1 / ray->rayDirX);
  if (ray->rayDirY == 0)
    ray->deltaDistY = 1e30;
  else
    ray->deltaDistY = fabs(1 / ray->rayDirY);
}

void set_sideDist(t_raycasting *ray)
{
  if (ray->rayDirX < 0)
  {
    ray->stepX = -1;
    ray->sideDistX = (ray->pos_x - ray->mapX) * ray->deltaDistX;
  }
  else
  {
    ray->stepX = 1;
    ray->sideDistX = (ray->mapX + 1.0 - ray->pos_x) * ray->deltaDistX;
  }
  if (ray->rayDirY < 0)
  {
    ray->stepY = -1;
    ray->sideDistY = (ray->pos_y - ray->mapY) * ray->deltaDistY;
  }
  else
  {
    ray->stepY = 1;
    ray->sideDistY = (ray->mapY + 1.0 - ray->pos_y) * ray->deltaDistY;
  }
}

void find_wall(t_raycasting *ray, t_data *data)
{
  int hit;

  hit = 0;
  (void)data;
  while (hit == 0)
  {
    if (ray->sideDistX < ray->sideDistY)
    {
      ray->sideDistX += ray->deltaDistX;
      ray->mapX += ray->stepX;
      ray->side = 0;
    }
    else
    {
      ray->sideDistY += ray->deltaDistY;
      ray->mapY += ray->stepY;
      ray->side = 1;
    }
    if (ray->mapX < 0 || ray->mapX >= data->map.width || ray->mapY < 0 || ray->mapY >= data->map.height)
    {
        //printf("mapX: %d\n mapY: %d\n", ray->mapX, ray->mapY);
        hit = 1;
        break;
    }
    if (data->map.grid[ray->mapY][ray->mapX] > '0')
      hit = 1;
  }
}

void calculate_ray(t_raycasting *ray)
{
  if (ray->side == 0)
    ray->perpWallDist = (ray->sideDistX - ray->deltaDistX);
  else
    ray->perpWallDist = (ray->sideDistY - ray->deltaDistY);
  ray->lineHeight = (int)(WIN_HEIGHT / ray->perpWallDist);
  ray->drawStart = -ray->lineHeight / 2 + WIN_HEIGHT / 2;
  if (ray->drawStart < 0)
    ray->drawStart = 0;
  ray->drawEnd = ray->lineHeight / 2 + WIN_HEIGHT / 2;
  if (ray->drawEnd >= WIN_HEIGHT)
    ray->drawEnd = WIN_HEIGHT - 1;
}

void raycasting(t_data *data)
{
  t_raycasting ray;
  int           x;

  x = 0;
  init_ray(&ray, data);
  fill_background(data);

  while (x < (double)WIN_WIDTH)
  {
    ray.mapX = (int)ray.pos_x;
    ray.mapY = (int)ray.pos_y;

    ray.cameraX = 2 * x / (double)WIN_WIDTH - 1;
    ray.rayDirX = data->dir_x + ray.plane_x * ray.cameraX;
    ray.rayDirY = data->dir_y + ray.plane_y * ray.cameraX;

    set_delta(&ray);
    set_sideDist(&ray);
    find_wall(&ray, data);
    calculate_ray(&ray);
    render_vertical_line(x, &ray, data);
    x++;
  }
}
