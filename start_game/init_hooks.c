#include "cub3d.h"

void init_hooks(t_game *game)
{
    mlx_hook(game->window, ESC, 0, &close_window, 0);
    mlx_hook(game->window, KEY_PRESS, 0, &key_pressed, game);
}

int key_pressed(int keycode, t_game *game)
{
    if (keycode == W)
        game->map->player->x += 0.1;
    else if (keycode == S)
        game->map->player->x -= 0.1;
    else if (keycode == A)
        game->map->player->y -= 0.1;
    else if (keycode == D)
        game->map->player->y += 0.1;
    draw_player(game->mlx, game->window, game->map->map, game);
    return (0);
}

int close_window(void)
{
    exit(0);
}