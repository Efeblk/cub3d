#include "cub3d.h"

int render(t_game *game)
{
    static int i = 0;
    ++i;
    printf("render %d \n", i);
    draw_minimap(game);
    draw_player(game);
    mlx_put_image_to_window(game->mlx, game->window, game->img->img, 0, 0);
    printf("render %d done \n", i);
    return 0;
}
