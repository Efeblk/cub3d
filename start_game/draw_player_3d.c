#include "cub3d.h"

void draw_vertical_line(void *mlx, void *window, int x, int draw_start, int draw_end, int color)
{
    for (int y = draw_start; y < draw_end; y++)
    {
        mlx_pixel_put(mlx, window, x, y, color);
    }
}

void draw_player_3d(t_game *game)
{
    int fov = 60; // adjust as per your game's requirements
    int screen_width = 800; // adjust as per your game's requirements
    for (int i = -fov / 2; i <= fov / 2; i++) {
        double ray_length = 0.0;
        double rad = (game->map->player->look_dir + i) * M_PI / 180.0;
        int hit = 0;
        int ray_end_x, ray_end_y;

        while (!hit) {
            ray_length += 1.0; // adjust this value as needed
            ray_end_x = game->map->player->x + ray_length * cos(rad);
            ray_end_y = game->map->player->y + ray_length * sin(rad);

            // check if the ray has hit a wall
            int map_x = ray_end_x / 64; // adjust as per your tile size
            int map_y = ray_end_y / 64; // adjust as per your tile size
            if (map_x < 0 || map_x >= game->map->map_width || map_y < 0 || map_y >= game->map->map_height) {
                hit = 1;
            } else if (game->map->map[map_y][map_x] == '1') {
                hit = 1;
            }
        }

        // calculate the height of the line to draw
        double line_height = 800 / ray_length; // adjust the constant as per your game's requirements

        // calculate the start and end points of the line
        int draw_start = -line_height / 2 + game->window_height / 2; // replace screen_height with game->window_height
        int draw_end = line_height / 2 + game->window_height / 2; // replace screen_height with game->window_height

        // draw the line
// draw the line
        int x = (i + fov / 2) * (screen_width / fov);
        draw_vertical_line(game->mlx, game->window, x, draw_start, draw_end, 0xFF0000);
    }

    // draw 2D minimap
    //draw_minimap(game);
}