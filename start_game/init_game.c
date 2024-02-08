#include "cub3d.h"

void init_game(t_game *game)
{   
    init_player(game->map->player);
    load_assets(game->mlx, game);
    init_window(game);
    init_hooks(game);
}

void init_player(t_player *player)
{
    player->posX *= BLOCK_SIZE; // +32 gibi bişi olabilir ikisinede, olduğu blokta başlama noktasını ortalamak için.
    player->posY *= BLOCK_SIZE; 
}

void init_window(t_game *game)
{
    game->map->map_height += 2; // parser hatalı olabilir (?), normalde bu satırın olmaması gerekli
    game->window_width = game->map->map_width * BLOCK_SIZE;
    game->window_height = game->map->map_height * BLOCK_SIZE;
    open_window(game);
}

void init_hooks(t_game *game)
{
    mlx_hook(game->window, ESC, 0, close_window, game);
    mlx_loop_hook(game->mlx, render, game);
}

