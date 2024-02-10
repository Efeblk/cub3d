#include "cub3d.h"

int key_press(int keycode, t_game *game)
{
    if (keycode == ESC)
        close_window();
    if (keycode == W)
    {
        game->map->player->posY -= MOVE_SPEED;   
    }
    if (keycode == S)
    {
        game->map->player->posY += MOVE_SPEED;   
    }
    if (keycode == A)
    {
        game->map->player->posX -= MOVE_SPEED;   
    }
    if (keycode == D)
    {
        game->map->player->posX += MOVE_SPEED;   
    }
    return 0;
}