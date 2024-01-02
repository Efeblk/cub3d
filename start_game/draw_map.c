#include "cub3d.h"

void draw_map(void *mlx, void *window, char **map, t_game *game)
{
    int row, col;

    row = 0;
    while (map[row] != NULL)
    {
        col = 0;
        while (map[row][col] != '\0')
        {
            if (map[row][col] == '1')
            {
                mlx_put_image_to_window(mlx, window, game->assets->e, col * BLOCK_SIZE, row * BLOCK_SIZE);
            }
            else if (map[row][col] == '0' || map[row][col] == ' ')
            {
                mlx_pixel_put(mlx, window, col * BLOCK_SIZE, row * BLOCK_SIZE, 0x000000);
            }
            ++col;
        }
        ++row;
    }
}
