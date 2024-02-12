#include "cub3d.h"

// int key_press(int keycode, t_game *game)
// {
//     if (keycode == ESC)
//         close_window();
//     if (keycode == W)
//         game->map->player->posY -= MOVE_SPEED;
//     if (keycode == S)
//         game->map->player->posY += MOVE_SPEED;
//     if (keycode == A)
//         game->map->player->posX -= MOVE_SPEED;
//     if (keycode == D)
//         game->map->player->posX += MOVE_SPEED;
//     if (keycode == LEFT_ARROW)
//     {
//         game->map->player->dirX = game->map->player->dirX * cos(ROT_SPEED) - game->map->player->dirY * sin(ROT_SPEED);
//         game->map->player->dirY = game->map->player->dirX * sin(ROT_SPEED) + game->map->player->dirY * cos(ROT_SPEED);
//         game->map->player->planeX = game->map->player->planeX * cos(ROT_SPEED) - game->map->player->planeY * sin(ROT_SPEED);
//         game->map->player->planeY = game->map->player->planeX * sin(ROT_SPEED) + game->map->player->planeY * cos(ROT_SPEED);
//     }
//     if (keycode == RIGHT_ARROW)
//     {
//         game->map->player->dirX = game->map->player->dirX * cos(-ROT_SPEED) - game->map->player->dirY * sin(-ROT_SPEED);
//         game->map->player->dirY = game->map->player->dirX * sin(-ROT_SPEED) + game->map->player->dirY * cos(-ROT_SPEED);
//         game->map->player->planeX = game->map->player->planeX * cos(-ROT_SPEED) - game->map->player->planeY * sin(-ROT_SPEED);
//         game->map->player->planeY = game->map->player->planeX * sin(-ROT_SPEED) + game->map->player->planeY * cos(-ROT_SPEED);
//     }
//     return 0;
// }