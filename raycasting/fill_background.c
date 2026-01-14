#include "../cub3d.h"

void fill_background(t_data *data)
{
  int j;
  int i;

  j = 0;
  while (j < WIN_HEIGHT)
  {
    i = 0;
    while (i < WIN_WIDTH)
    {
      uint32_t bg_color = (j < WIN_HEIGHT / 2) ? 0x333333FF : 0x666666FF; 
      mlx_put_pixel(data->img[0], i, j, bg_color);
      i++;
    }
    j++;
  }
}
