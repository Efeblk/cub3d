#include "cub3d.h"

void	draw_circle(t_img_data *data, int center_x, int center_y, int radius, int color)
{
	int	x;
	int	y;
	int	err;

	x = radius;
	y = 0;
	err = 0;
	while (x >= y)
	{
		my_mlx_pixel_put(data, center_x + x, center_y + y, color);
		my_mlx_pixel_put(data, center_x + y, center_y + x, color);
		my_mlx_pixel_put(data, center_x - y, center_y + x, color);
		my_mlx_pixel_put(data, center_x - x, center_y + y, color);
		my_mlx_pixel_put(data, center_x - x, center_y - y, color);
		my_mlx_pixel_put(data, center_x - y, center_y - x, color);
		my_mlx_pixel_put(data, center_x + y, center_y - x, color);
		my_mlx_pixel_put(data, center_x + x, center_y - y, color);
		if (err <= 0)
		{
			y += 1;
			err += 2 * y + 1;
		}
		if (err > 0)
		{
			x -= 1;
			err -= 2 * x + 1;
		}
	}
}

void	draw_player(t_game *game)
{
	int player_2d_x;
	int player_2d_y;

	player_2d_x = game->map->player->pos_x * game->block_size_2d;
	player_2d_y = game->map->player->pos_y * game->block_size_2d;
	draw_circle(game->img, player_2d_x,
		player_2d_y, game->block_size_2d / 2, 0x00FF00);
}
