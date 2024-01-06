#include "cub3d.h"

void draw_vertical_line(void *mlx, void *window, int x, int draw_start, int draw_end, int color)
{
    for (int y = draw_start; y < draw_end; y++)
    {
        mlx_pixel_put(mlx, window, x, y, color);
    }
}

void draw_image_slice(t_game *game, void *img, int offset, int x)
{
    int img_width;
    int img_height;

    img_width = 64;
    img_height = 64;
    char *img_data = mlx_get_data_addr(img, &img_width, &img_height, NULL);

    if (offset >= img_width) {
        return; // offset is outside the bounds of the image data
    }

    for (int y = 0; y < img_height; y++)
    {
        if (y >= img_height) {
            return; // y is outside the bounds of the image data
        }

        int color = *(int *)(img_data + (y * img_width + offset) * 4);
        mlx_pixel_put(game->mlx, game->window, x, y, color);
    }
}

void draw_player_3d(t_game *game)
{
    int fov = 60; // adjust as per your game's requirements
    int screen_width = 800; // adjust as per your game's requirements
    //double MAX_RAY_LENGTH = sqrt(game->map->map_width * game->map->map_width + game->map->map_height * game->map->map_height);
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
                //int offset = (int)(ray_length / MAX_RAY_LENGTH * 64);
                //draw_image_slice(game, game->assets->e, offset, i + fov / 2);
            }
        }

        // calculate the height of the line to draw
        double line_height = 800 / ray_length; // adjust the constant as per your game's requirements

        // calculate the start and end points of the line
        int draw_start = -line_height / 2 + game->window_height / 2; // replace screen_height with game->window_height
        int draw_end = line_height / 2 + game->window_height / 2; // replace screen_height with game->window_height

        int x = (i + fov / 2) * (screen_width / fov);
        draw_vertical_line(game->mlx, game->window, x, draw_start, draw_end, 0xFF0000);
    }
}