#include "cub3d.h"

int render(t_game *game)
{
    static int i = 0;
    ++i;
    printf("render %d \n", i);
    draw_minimap(game, game->mlx, game->window);
    printf("render %d done \n", i);
    return 0;
}
