#include "cub3d.h"

int close_window(void)
{
    exit(0);
}

void init_game(t_map *map)
{
    void *mlx;
    void *window;

    mlx = mlx_init();

    int width = 800;
    int height = 600;

    window = mlx_new_window(mlx, width, height, "My MiniLibX Window");
    // Example: Close the window when the user presses the 'ESC' key
    mlx_hook(window, 17, 0, &close_window, 0);
    mlx_loop(mlx);
    (void)map;
}