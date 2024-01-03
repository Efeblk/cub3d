#include "cub3d.h"

void go_forward(t_game *game)
{
    int x;
    int y;

    x = game->map->player->x/ 64;
    y = (game->map->player->y - MOVE_SPEED) / 64;
    if (game->map->map[y][x] == '1')
        return ;
    game->map->player->y -= 2;
}

void go_down(t_game *game)
{
    int x;
    int y;

    x = game->map->player->x / 64;
    y = (game->map->player->y + MOVE_SPEED) / 64;
    if (game->map->map[y][x] == '1')
        return ;
    game->map->player->y += 2;
}

void go_left(t_game *game)
{
    int x;
    int y;

    x = (game->map->player->x - MOVE_SPEED) / 64;
    y = (game->map->player->y) / 64;
    printf("x: %d, y: %d\n", x, y);
    if (game->map->map[y][x] == '1')
        return ;
    game->map->player->x -= 2;
}

void go_right(t_game *game)
{
    int x;
    int y;

    x = (game->map->player->x + MOVE_SPEED) / 64;
    y = game->map->player->y / 64;
    if (game->map->map[y][x] == '1')
        return ;
    game->map->player->x += 2;
}

int key_pressed(int keycode, t_game *game)
{
    if (keycode == W)
        go_forward(game);
    else if (keycode == S)
        go_down(game);
    else if (keycode == A)
        go_left(game);
    else if (keycode == D)
        go_right(game);
    else if(keycode == LEFT_ARROW)
        game->map->player->look_dir -= 5;
    else if(keycode == RIGHT_ARROW)
        game->map->player->look_dir += 5;
    mlx_clear_window(game->mlx, game->window);
    draw_map(game->mlx, game->window, game->map->map, game);
    draw_player(game->mlx, game->window, game->map->map, game);
    return (0);
}
