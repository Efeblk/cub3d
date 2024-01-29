#include "cub3d.h"

void go_forward_3d(t_game *game)
{
    double new_x, new_y;

    new_x = game->map->player->x + MOVE_SPEED * cos(game->map->player->look_dir_radian);
    new_y = game->map->player->y + MOVE_SPEED * sin(game->map->player->look_dir_radian);

    int map_x = (int)(new_x / 64);
    int map_y = (int)(new_y / 64);
    if (game->map->map[map_y][map_x] == '1')
        return ;

    game->map->player->x = new_x;
    game->map->player->y = new_y;
}

void go_down_3d(t_game *game)
{
    double new_x, new_y;

    new_x = game->map->player->x - MOVE_SPEED * cos(game->map->player->look_dir_radian);
    new_y = game->map->player->y - MOVE_SPEED * sin(game->map->player->look_dir_radian);

    int map_x = (int)(new_x / 64);
    int map_y = (int)(new_y / 64);
    if (game->map->map[map_y][map_x] == '1')
        return ;

    game->map->player->x = new_x;
    game->map->player->y = new_y;
}

void go_left_3d(t_game *game)
{
    double new_x, new_y;

    new_x = game->map->player->x + MOVE_SPEED * sin(game->map->player->look_dir_radian);
    new_y = game->map->player->y - MOVE_SPEED * cos(game->map->player->look_dir_radian);

    int map_x = (int)(new_x / 64);
    int map_y = (int)(new_y / 64);
    if (game->map->map[map_y][map_x] == '1')
        return ;

    game->map->player->x = new_x;
    game->map->player->y = new_y;
}

void go_right_3d(t_game *game)
{
    double new_x, new_y;

    new_x = game->map->player->x - MOVE_SPEED * sin(game->map->player->look_dir_radian);
    new_y = game->map->player->y + MOVE_SPEED * cos(game->map->player->look_dir_radian);

    int map_x = (int)(new_x / 64);
    int map_y = (int)(new_y / 64);
    if (game->map->map[map_y][map_x] == '1')
        return ;

    game->map->player->x = new_x;
    game->map->player->y = new_y;
}

int key_pressed(int keycode, t_game *game)
{
    if (keycode == W)
        go_forward_3d(game);
    else if (keycode == S)
        go_down_3d(game);
    else if (keycode == A)
        go_left_3d(game);
    else if (keycode == D)
        go_right_3d(game);
    else if(keycode == LEFT_ARROW)
    {
        game->map->player->look_dir_radian -= 0.1;
        if (game->map->player->look_dir_radian < 0)
            game->map->player->look_dir_radian = 2 * M_PI;
    }
    else if(keycode == RIGHT_ARROW)
    {
        game->map->player->look_dir_radian += 0.1;
        if (game->map->player->look_dir_radian > 2 * M_PI)
            game->map->player->look_dir_radian = 0;
    }
    return (0);
}
