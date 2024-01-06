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

void player_2d_pov(t_game *game)
{
    int fov;
    int i;
    double ray_length;
    double rad;
    int hit;
    int ray_end_x;
    int ray_end_y;
    int map_x;
    int map_y;

    fov = 60;
    i = -fov / 2;
    while (i <= fov / 2) 
    {
        ray_length = 0.0;
        rad = (game->map->player->look_dir + i) * M_PI / 180.0;
        hit = 0;

        while (!hit) {
            ray_length += 1.0; // adjust this value as needed
            ray_end_x = game->map->player->x + ray_length * cos(rad);
            ray_end_y = game->map->player->y + ray_length * sin(rad);

            // check if the ray has hit a wall
            map_x = ray_end_x / 64; // adjust as per your tile size
            map_y = ray_end_y / 64; // adjust as per your tile size

            // add boundary check
            if (map_x < 0 || map_x >= game->map->map_width || map_y < 0 || map_y >= game->map->map_height) {
                hit = 1;
            } else if (game->map->map[map_y][map_x] == '1') {
                hit = 1;
            }
        }
        draw_line(game->mlx, game->window, game->map->player->x / MINI_MAP_SCALE, game->map->player->y / MINI_MAP_SCALE, ray_end_x / MINI_MAP_SCALE, ray_end_y / MINI_MAP_SCALE, 0xFF0000);
        ++i;
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