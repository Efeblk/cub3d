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

void draw_line(void *mlx, void *win, float x, float y, float angle, int length, int color) 
{
    float angleRad = angle * M_PI / 180.0;  // Convert angle to radians

    int i;
    for (i = 0; i < length; i++) {
        int drawX = x + i * cos(angleRad);
        int drawY = y + i * sin(angleRad);
        mlx_pixel_put(mlx, win, drawX, drawY, color);
    }
}

void player_2d_pov(t_game *game)
{
    int fov = game->map->player->fov;
    while (fov >= 0)
    {
        draw_line(game->mlx, game->window, game->map->player->x, game->map->player->y, fov, 100, 0x00FF00);
        fov -= 1;
    }
}

void draw_player_2d(void *mlx, void *window, char **map, t_game *game)
{
    (void)map;
    printf("x: %f, y: %f\n", game->map->player->x, game->map->player->y);

    int player_x = game->map->player->x / MINI_MAP_SCALE;
    int player_y = game->map->player->y / MINI_MAP_SCALE;
    int x = 0, y = 1; // radius of the circle
    int d = 3 - 2 * y;
    draw_circle(mlx, window, player_x, player_y, x, y);
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
        draw_circle(mlx, window, player_x, player_y, x, y);
    }
    player_2d_pov(game);
}