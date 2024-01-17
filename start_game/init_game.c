#include "cub3d.h"

void init_game(t_game *game)
{   
    game->map->map_height += 2;
    //game->map->map_width += 1;
    game->window_width = game->map->map_width * BLOCK_SIZE;
    game->window_height = game->map->map_height * BLOCK_SIZE;
    game->mlx = mlx_init();
    game->map->player->x *= BLOCK_SIZE;
    game->map->player->y *= BLOCK_SIZE;
    game->map->player->fov = 60;
    game->map->player->look_dir_2d = 0;
    load_assets(game->mlx, game);
    open_window(game);
    init_hooks(game);
}

int render(t_game *game)
{
    static int i = 0;
    i++;
    printf("render %d\n", i);
    mlx_clear_window(game->mlx, game->window);
    draw_minimap(game, game->mlx, game->window);
    draw_player_2d(game->mlx, game->window, game->map->map, game);
    return 0;
}

void init_hooks(t_game *game)
{
    mlx_hook(game->window, ESC, 0, &close_window, 0);
    mlx_hook(game->window, KEY_PRESS, 0, &key_pressed, game);
    mlx_loop_hook(game->mlx, &render, game);
}