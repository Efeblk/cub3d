#include "cub3d.h"

void draw_minimap(t_game *game, void *mlx, void *window)
{
    int row, col, x, y;
    char **map = game->map->map;

    row = 0;
    while (map[row] != NULL)
    {
        col = 0;
        while (map[row][col] != '\0')
        {
            if (map[row][col] == '1')
            {
                for (y = 0; y < BLOCK_SIZE / MINI_MAP_SCALE; y++)
                {
                    for (x = 0; x < BLOCK_SIZE / MINI_MAP_SCALE; x++)
                    {
                        mlx_pixel_put(mlx, window, col * BLOCK_SIZE / MINI_MAP_SCALE + x, row * BLOCK_SIZE / MINI_MAP_SCALE + y, 0xFFFFFF);
                    }
                }
            }
            else if (map[row][col] == '0' || map[row][col] == ' ')
            {
                mlx_pixel_put(mlx, window, col * BLOCK_SIZE / MINI_MAP_SCALE, row * BLOCK_SIZE / MINI_MAP_SCALE, 0x000000);
            }
            ++col;
        }
        ++row;
    }
}
