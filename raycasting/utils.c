#include "../cub3d.h"

void	put_pixel(mlx_image_t* image, uint32_t x, uint32_t y, uint32_t color)
{
	uint8_t*	pixel;

	pixel = &image->pixels[(y * image->width + x) * sizeof(int32_t)];
	*(pixel++) = (uint8_t)(color >> 24);
	*(pixel++) = (uint8_t)(color >> 16);
	*(pixel++) = (uint8_t)(color >> 8);
	*(pixel++) = (uint8_t)(color & 0xFF);
}
