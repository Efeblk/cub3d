#include "cub3d.h"

void start_game(t_game *game)
{
    t_assets assets;
    t_img_data img;
    game->mlx = mlx_init();
    game->assets = &assets; //stackde oluşturmak daha rahat
    init_game(game);

    img.img = mlx_new_image(game->mlx, game->window_width, game->window_height);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    game->img = &img;
    mlx_loop(game->mlx);
}

