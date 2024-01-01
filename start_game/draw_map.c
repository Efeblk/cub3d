#include "cub3d.h"

void draw_map(void *mlx, void *window, char **map)
{
    int row, col;
    int height = 64;
    int width = 64;
    void *wall_image = mlx_xpm_file_to_image(mlx, "./assets/greystone.xpm", &height, &width);
    if (!wall_image)
    {
        printf("Error: Could not load image\n");
    }
    row = 0;
    while (map[row] != NULL)
    {
        col = 0;
        while (map[row][col] != '\0')
        {
            if (map[row][col] == '1')
            {               
                mlx_put_image_to_window(mlx, window, wall_image, col * 30, row * 30);
            }
            else if (map[row][col] == '0')
            {
                mlx_pixel_put(mlx, window, col * BLOCK_SIZE, row * BLOCK_SIZE, 0x000000);
            }
            ++col;
        }
        ++row;
    }
}