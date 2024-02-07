#include "cub3d.h"

void start_game(t_game *game)
{
    t_assets assets;
    game->assets = &assets; //stackde oluşturmak daha rahat
    init_game(game);
    draw_minimap(game, game->mlx, game->window);
    mlx_loop(game->mlx);
}

