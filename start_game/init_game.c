#include "cub3d.h"

void init_game(t_game *game)
{   
    init_mlx_dep(game);
    init_player(game->map->player);
    load_assets(game->mlx, game);
    init_window(game);
}

void init_mlx_dep(t_game *game)
{
    game->mlx = mlx_init();

}

void init_player(t_player *player)
{
    player->posX *= BLOCK_SIZE;
    player->posY *= BLOCK_SIZE;
}

void init_window(t_game *game)
{
    game->map->map_height += 2;
    game->window_width = game->map->map_width * BLOCK_SIZE;
    game->window_height = game->map->map_height * BLOCK_SIZE;
    open_window(game);
}