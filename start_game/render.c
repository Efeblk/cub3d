#include "cub3d.h"

int render(t_game *game)
{
    static int i = 0;
    ++i;
    printf("render %d \n", i);
    //mustafanın rutini
    game->map->player->dirX = cos(game->map->player->dir_radian);
    game->map->player->dirY = sin(game->map->player->dir_radian);
    clearimg(game);
    raycast(game);
    (printf("raycast done \n"));
    mlx_put_image_to_window(game->mlx, game->window, game->img->img, 0, 0);
    //mustafanın rutini end
    
    //draw_minimap(game);
    //draw_player(game);
    //mlx_put_image_to_window(game->mlx, game->window, game->img->img, 0, 0);
    printf("render %d done \n", i);
    return 0;
}
