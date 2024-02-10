#include "cub3d.h"

void draw_circle(t_img_data *data, int center_x, int center_y, int radius, int color)
{
    int x = radius;
    int y = 0;
    int err = 0;

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

void draw_player(t_game *game)
{
    draw_circle(game->img, game->map->player->posX, game->map->player->posY, 5, 0x00FF00);
}  