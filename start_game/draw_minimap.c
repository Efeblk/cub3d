#include "cub3d.h"

int	my_get_pixel_color(t_img_data *img, int x, int y)
{
	char			*pixel_addr;
	unsigned int	*pixel;
	unsigned int	color;

	pixel_addr = img->addr
		+ (y * img->line_length + x * (img->bits_per_pixel / 8));
	if (img->bits_per_pixel == 32)
	{
		pixel = (unsigned int *)pixel_addr;
		return (*pixel);
	}
	else if (img->bits_per_pixel == 24)
	{
		pixel = (unsigned char *)pixel_addr;
		color = (pixel[2] << 16) | (pixel[1] << 8) | pixel[0];
		return (color);
	}
	else
	{
		return (-1);
	}
}

void	draw_empty_block(t_game *game, int x, int y)
{
	int	dx;
	int	dy;
	int	block_size;
	int	px;
	int	py;

	dx = 0;
	dy = 0;
	block_size = BLOCK_SIZE;
	while (dy < block_size)
	{
		dx = 0;
		while (dx < block_size)
		{
			px = x + dx;
			py = y + dy;
			my_mlx_pixel_put(game->img, px, py, 0);
			dx++;
		}
		dy++;
	}
}

void	draw_wall_block(t_game *game, int x, int y, t_img_data *img)
{
	int	dx;
	int	dy;
	int	block_size;
	int	px;
	int	py;
	int color;

	dx = 0;
	dy = 0;
	block_size = BLOCK_SIZE;
	while (dy < block_size)
	{
		dx = 0;
		while (dx < block_size)
		{
			px = x + dx;
			py = y + dy;
			color = my_get_pixel_color(img, px % BLOCK_SIZE, py % BLOCK_SIZE);
			my_mlx_pixel_put(game->img, px, py, color);
			dx++;
		}
		dy++;
	}
}

void	draw_minimap(t_game *game)
{
	int	i;
	int	j;
	int	x;
	int	y;
	int	block_size;

	i = 0;
	block_size = BLOCK_SIZE;
	while (i < game->map->map_height)
	{
		j = 0;
		while (j < game->map->map_width)
		{
			x = j * block_size;
			y = i * block_size;
			if (game->map->map[i][j] == '1')
				draw_wall_block(game, x, y, game->assets->n);
			else
				draw_empty_block(game, x, y);
			j++;
		}
		i++;
	}
}
