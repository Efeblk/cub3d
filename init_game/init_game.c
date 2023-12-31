#include "cub3d.h"

#define WIDTH 800
#define HEIGHT 600
#define BLOCK_SIZE 40

int close_window(void)
{
    exit(0);
}

void draw_map(void *mlx, void *window, char **map);

void init_game(t_game *game)
{
    void *mlx;
    void *window;

    mlx = mlx_init();

    int width = 800;
    int height = 600;

    window = mlx_new_window(mlx, width, height, "My MiniLibX Window");
    draw_map(mlx, window, game->map->map);
    mlx_hook(window, 17, 0, &close_window, 0);
    mlx_loop(mlx);
}

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
    for (row = 0; map[row] != NULL; ++row)
    {
        for (col = 0; map[row][col] != '\0'; ++col)
        {
            if (map[row][col] == '1')
            {
                // Load XPM image for walls
               
                // Draw the image on the window
                mlx_put_image_to_window(mlx, window, wall_image, col * BLOCK_SIZE, row * BLOCK_SIZE);
            }
            else if (map[row][col] == '0')
            {
                // Draw a block for empty spaces
                mlx_pixel_put(mlx, window, col * BLOCK_SIZE, row * BLOCK_SIZE, 0x000000); // Black color
            }
            // Add more conditions for other characters if needed
        }
    }
}
