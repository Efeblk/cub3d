#include "cub3d.h"

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
    draw_map(game->mlx, game->window, game->map->map, game);
    return (0);
}
