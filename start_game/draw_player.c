#include "cub3d.h"

void draw_circle(void *mlx, void *window, int xc, int yc, int x, int y)
{
    mlx_pixel_put(mlx, window, xc+x, yc+y, 0x00FF00);
    mlx_pixel_put(mlx, window, xc-x, yc+y, 0x00FF00);
    mlx_pixel_put(mlx, window, xc+x, yc-y, 0x00FF00);
    mlx_pixel_put(mlx, window, xc-x, yc-y, 0x00FF00);
    mlx_pixel_put(mlx, window, xc+y, yc+x, 0x00FF00);
    mlx_pixel_put(mlx, window, xc-y, yc+x, 0x00FF00);
    mlx_pixel_put(mlx, window, xc+y, yc-x, 0x00FF00);
    mlx_pixel_put(mlx, window, xc-y, yc-x, 0x00FF00);
}

void draw_line(void *mlx, void *window, int x0, int y0, int x1, int y1, int color)
{
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = (x0 < x1) ? 1 : -1;
    int sy = (y0 < y1) ? 1 : -1;
    int err = dx - dy;

    while (1)
    {
        mlx_pixel_put(mlx, window, x0, y0, color);
        if (x0 == x1 && y0 == y1)
            break;
        int e2 = 2 * err;
        if (e2 > -dy)
        {
            err -= dy;
            x0 += sx;
        }
        if (e2 < dx)
        {
            err += dx;
            y0 += sy;
        }
    }
}

void draw_player(void *mlx, void *window, char **map, t_game *game)
{
    (void)map;
    printf("x: %d, y: %d\n", game->map->player->x, game->map->player->y);

    int x = 0, y = 10; // radius of the circle
    int d = 3 - 2 * y;
    draw_circle(mlx, window, game->map->player->x, game->map->player->y, x, y);
    while (y >= x)
    {
        x++;
        if (d > 0)
        {
            y--;
            d = d + 4 * (x - y) + 10;
        }
        else
            d = d + 4 * x + 6;
        draw_circle(mlx, window, game->map->player->x, game->map->player->y, x, y);
    }
    double ray_length = 100.0; // adjust as needed
    double rad = game->map->player->look_dir * M_PI / 180.0; // convert to radians
    int ray_end_x = game->map->player->x + ray_length * cos(rad);
    int ray_end_y = game->map->player->y + ray_length * sin(rad);
    draw_line(mlx, window, game->map->player->x, game->map->player->y, ray_end_x, ray_end_y, 0xFF0000);
}