#include "cub3d.h"

void	my_mlx_pixel_put(t_img_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void draw_minimap(t_game *game, void *mlx, void *window)
{
    int i = 0;
    int j, x, y, dx, dy;
    int block_size = BLOCK_SIZE; // assuming BLOCK_SIZE is defined somewhere

    while (i < game->map->map_height)
    {
        j = 0;
        while (j < game->map->map_width)
        {
            x = j * block_size;
            y = i * block_size;

            int color;
            if (game->map->map[i][j] == '1')
                color = 0x00FF0000; // Red for walls
            else
                color = 0x000000FF; // Blue for empty space

            dy = 0;
            while (dy < block_size)
            {
                dx = 0;
                while (dx < block_size)
                {
                    int px = x + dx;
                    int py = y + dy;

                    my_mlx_pixel_put(game->img, px, py, color);
                    dx++;
                }
                dy++;
            }
            j++;
        }
        i++;
    }
    mlx_put_image_to_window(mlx, window, game->img->img, 0, 0);
}
