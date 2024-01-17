#include "cub3d.h"
#include <math.h>

void draw_vertical_line(void *mlx, void *window, int x, int draw_start, int draw_end, int color)
{
    for (int y = draw_start; y < draw_end; y++)
    {
        mlx_pixel_put(mlx, window, x, y, color);
    }
}

void draw_player_3d(t_game *game)
{
    int fov = 60;
    int window_width = game->window_width; // Adjust as per your game's requirements
    int window_height = game->window_height; // Adjust as per your game's requirements

    for (int i = 0; i < window_width; i++)
    {
        // Calculate ray direction in camera space
        double cameraX = 2 * i / (double)window_width - 1;
        double rayDirX = game->map->player->dirX + game->map->player->planeX * cameraX;
        double rayDirY = game->map->player->dirY + game->map->player->planeY * cameraX;

        // Map coordinates
        int mapX = (int)game->map->player->x;
        int mapY = (int)game->map->player->y;

        // Length of ray from current position to next x or y-side
        double sideDistX, sideDistY;

        // Delta distance for x and y
        double deltaDistX = fabs(1 / rayDirX);
        double deltaDistY = fabs(1 / rayDirY);

        // Step and initial sideDist
        int stepX, stepY;
        int hit = 0; // Was a wall hit?

        if (rayDirX < 0)
        {
            stepX = -1;
            sideDistX = (game->map->player->x - mapX) * deltaDistX;
        }
        else
        {
            stepX = 1;
            sideDistX = (mapX + 1.0 - game->map->player->x) * deltaDistX;
        }

        if (rayDirY < 0)
        {
            stepY = -1;
            sideDistY = (game->map->player->y - mapY) * deltaDistY;
        }
        else
        {
            stepY = 1;
            sideDistY = (mapY + 1.0 - game->map->player->y) * deltaDistY;
        }

        // DDA
        while (!hit)
        {
            if (sideDistX < sideDistY)
            {
                sideDistX += deltaDistX;
                mapX += stepX;
                game->side = 0;
            }
            else
            {
                sideDistY += deltaDistY;
                mapY += stepY;
                game->side = 1;
            }

            // Check if ray has hit a wall
            if (game->map->map[mapX][mapY] == '1')
                hit = 1;
        }

        // Calculate distance to the projected wall slice
        double perpWallDist;
        if (game->side == 0)
            perpWallDist = (mapX - game->map->player->x + (1 - stepX) / 2) / rayDirX;
        else
            perpWallDist = (mapY - game->map->player->y + (1 - stepY) / 2) / rayDirY;

        // Calculate height of the wall slice
        int lineHeight = (int)(window_height / perpWallDist);

        // Calculate start and end positions for drawing the wall slice
        int drawStart = -lineHeight / 2 + window_height / 2;
        if (drawStart < 0)
            drawStart = 0;
        int drawEnd = lineHeight / 2 + window_height / 2;
        if (drawEnd >= window_height)
            drawEnd = window_height - 1;

        // Choose wall color based on the side (for simplicity, use red and blue)

        // Draw the wall slice
        draw_vertical_line(game->mlx, game->window, i, drawStart, drawEnd, 0xFF0000);
    }
}
