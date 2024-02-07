#include "cub3d.h"

void	my_mlx_pixel_put(t_img_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void draw_minimap(t_game *game, void *mlx, void *window)
{
    t_img_data img;
    img.img = mlx_new_image(mlx, game->window_width, game->window_height);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    int x = 0;
    int y = 0;
    int color = 0x00FF0000;
    while (y < game->map->map_height)
    {
        x = 0;
        while (x < game->map->map_width)
        {
            if (game->map->map[y][x] == '1')
            {
                my_mlx_pixel_put(&img, x * BLOCK_SIZE, y * BLOCK_SIZE, color);
            }
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(mlx, window, img.img, 0, 0);
    mlx_destroy_image(mlx, img.img);
}

