#include "../cub3d.h"
#include <math.h>

// data->map->width/height
// WIN_HEIGHT/WIN_WIDTH

// #define WIN_WIDTH 1024
// #define WIN_HEIGHT 768
// #define ROT_SPEED 0.05
// #define MOVE_SPEED 0.05
//
//

int worldMap[24][24] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 0, 0, 0, 0, 3, 0, 3, 0, 3, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 3, 0, 0, 0, 3, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 2, 2, 0, 2, 2, 0, 0, 0, 0, 3, 0, 3, 0, 3, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 4, 4, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 4, 0, 4, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 4, 0, 0, 0, 0, 5, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 4, 0, 4, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 4, 0, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 4, 4, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

void render_vertical_line(int x, t_raycasting *ray, t_data *data)
{
    int       y;
    uint32_t  color;
    int       wall_val;

 //FIX: use the proper data map. and the proper boundries instead of 24
    if (ray->mapX < 0 || ray->mapX >= 24 || ray->mapY < 0 || ray->mapY >= 24)
        return;
    else
        wall_val = worldMap[ray->mapY][ray->mapX]; 
    y = ray->drawStart;
    if (wall_val == 1) 
      color = 0xFF0000FF;
    else if (wall_val == 2)
      color = 0x00FF00FF;
    else if (wall_val == 3)
      color = 0x0000FFFF;
    else
      color = 0xFFFF00FF;
    if (ray->side == 1)
        color = (color >> 1) & 0x7F7F7F7F;
    if (x < 0 || x >= WIN_WIDTH) return;
    while (y < ray->drawEnd)
    {
        if (y >= 0 && y < WIN_HEIGHT)
            mlx_put_pixel(data->img[0], x, y, color);
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
    if (ray->mapX < 0 || ray->mapX >= 24 || ray->mapY < 0 || ray->mapY >= 24)
    {
        printf("I am here\n");
        hit = 1; 
        break; 
    }
// FIX: Use the data->wall or something, thats coming from parsing
    if (worldMap[ray->mapY][ray->mapX] > 0)
      hit = 1;
  }
}

void calculate_ray(t_raycasting *ray)
{
  double  perpWallDist;
  int     lineHeight; 

  if (ray->side == 0)
    perpWallDist = (ray->sideDistX - ray->deltaDistX);
  else
    perpWallDist = (ray->sideDistY - ray->deltaDistY);
  lineHeight = (int)(WIN_HEIGHT / perpWallDist);
  ray->drawStart = -lineHeight / 2 + WIN_HEIGHT / 2;
  if (ray->drawStart < 0)
    ray->drawStart = 0;
  ray->drawEnd = lineHeight / 2 + WIN_HEIGHT / 2;
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
