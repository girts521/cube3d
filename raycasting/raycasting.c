#include "../cub3d.h"

// data->map->width/height
// WIN_HEIGHT/WIN_WIDTH

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

int ft_abs(int i) {
  if (i < 0)
    return -i;
  else
    return i;
}

void raycasting(t_data *data) {
  double pos_x;
  double pos_y;
  double plane_x;
  double plane_y;
  double time;
  double oldTime;
  int x;
  double cameraX;
  double rayDirX;
  double rayDirY;
  int mapX;
  int mapY;
  double sideDistX;
  double sideDistY;
  double perpWallDist;
  double deltaDistX;
  double deltaDistY;
  int stepX;
  int stepY;
  int hit;
  int side;
  int lineHeight;
  int drawStart;
  int drawEnd;
  int color;
  char wall_type;

  hit = 0;
  side = 0;
  pos_x = data->player[0];
  pos_y = data->player[1];
  plane_x = -data->dir_y * 0.66;
  plane_y = data->dir_x * 0.66;
  time = 0;
  oldTime = 0;
  x = 0;

  while (x < (double)WIN_WIDTH) {
    cameraX = 2 * x / (double)WIN_WIDTH - 1;
    rayDirX = data->dir_x + plane_x * cameraX;
    rayDirY = data->dir_y + plane_y * cameraX;

    mapY = (int)pos_y;
    mapX = (int)pos_x;

    if (rayDirX == 0)
      deltaDistX = 1e30;
    else
      ft_abs(1 / rayDirX);

    if (rayDirY == 0)
      deltaDistY = 1e30;
    else
      ft_abs(1 / rayDirY);

    if (rayDirX < 0) {
      stepX = -1;
      sideDistX = (pos_x - mapX) * deltaDistX;
    } else {
      stepX = 1;
      sideDistX = (mapX + 1.0 - pos_x) * deltaDistX;
    }
    if (rayDirY < 0) {
      stepY = -1;
      sideDistY = (pos_y - mapY) * deltaDistY;
    } else {
      stepY = 1;
      sideDistY = (mapY + 1.0 - pos_y) * deltaDistY;
    }

    while (hit == 0) {
      if (sideDistX < sideDistY) {
        sideDistX += deltaDistX;
        mapX += stepX;
        side = 0;
      } else {
        sideDistY += deltaDistY;
        mapY += stepY;
        side = 1;
      }
      if (worldMap[mapX][mapY] > 0)
        hit = 1;
    }

    if (side == 0)
      perpWallDist = (sideDistX - deltaDistX);
    else
      perpWallDist = (sideDistY - deltaDistY);

    lineHeight = (int)(WIN_HEIGHT / perpWallDist);
    drawStart = -lineHeight / 2 + WIN_HEIGHT / 2;
    if (drawStart < 0)
      drawStart = 0;
    drawEnd = lineHeight / 2 + WIN_HEIGHT / 2;
    if (drawEnd >= WIN_HEIGHT)
      drawEnd = WIN_HEIGHT - 1;

    wall_type = data->map.grid[mapY][mapX];

    if (wall_type == '1')
      color = 0xFF0000;
    else if (wall_type == '2')
      color = 0x00FF00;
    else if (wall_type == '3')
      color = 0x0000FF;
    else
      color = 0xFFFF00;

    if (side == 1)
      color = (color >> 1) & 8355711;
    // #TODO
    // render_vertical_line(x, drawStart, drawEnd, color, data);
    x++;
  }
  //
  // #TODO:
  //   take note of the fps
  //   redraw
  //   handle keys
}
