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
    // player->posX *= BLOCK_SIZE; 
    // player->posY *= BLOCK_SIZE;
    // player->posX += BLOCK_SIZE / 2; //center of the block
    // player->posY += BLOCK_SIZE / 2; //center of the block
    player->posX += 0.5;
    player->posY += 0.5;
    player->dirY = 0;
    player->dir_radian = M_PI / 4;
    set_dir(player);
    printf("%f", player->dir_radian);

}

void init_window(t_game *game)
{
    // game->window_width = game->map->map_width * BLOCK_SIZE;
    // game->window_height = game->map->map_height * BLOCK_SIZE;
    game->window_width = WINDOW_WIDTH;
    game->window_height = WINDOW_HEIGHT;
    game->img->img = mlx_new_image(game->mlx, game->window_width, game->window_height);
    game->img->addr = mlx_get_data_addr(game->img->img, &game->img->bits_per_pixel, &game->img->line_length, &game->img->endian);
    open_window(game);
}

void init_hooks(t_game *game)
{
    mlx_hook(game->window, ESC, 0, close_window, game);
    mlx_hook(game->window, 2, 0, ft_press, game);
    mlx_hook(game->window, 3, 0, ft_release, game);
    mlx_loop_hook(game->mlx, render, game);
}

void set_dir(t_player *player)
{
    if (player->dir == 'N')
		player->dir_radian = 1.5 * M_PI;
	else if (player->dir == 'S')
		player->dir_radian = 0.5 * M_PI;
	else if (player->dir == 'E')
		player->dir_radian = 0;
	else if (player->dir == 'W')
		player->dir_radian = M_PI;
}
