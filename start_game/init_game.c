#include "cub3d.h"

void init_game(t_game *game)
{
    game->window_width = 800;
    game->window_height = 600;
    game->mlx = mlx_init();
    load_assets(game->mlx, game);
    open_window(game);
}
//örnek 1
/*
NNNNNNNNNNNN
W0000000000E
W0000E00000E
W0000000000E
SSSSSSSSSSSS
*/

//örnek 2
/*
WWWWWWWWWWWW
S0000000000N
S0000E00000N
S0000000000N
EEEEEEEEEEEE
*/
