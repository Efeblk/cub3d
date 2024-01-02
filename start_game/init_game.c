#include "cub3d.h"

void init_game(t_game *game)
{   
    game->map->map_height += 2;
    //game->map->map_width += 1;
    game->window_width = game->map->map_width * BLOCK_SIZE;
    game->window_height = game->map->map_height * BLOCK_SIZE;
    game->mlx = mlx_init();
    load_assets(game->mlx, game);
    open_window(game);
    init_hooks(game);
}

void init_hooks(t_game *game)
{
    mlx_hook(game->window, ESC, 0, &close_window, 0);
    mlx_hook(game->window, KEY_PRESS, 0, &key_pressed, game);
}