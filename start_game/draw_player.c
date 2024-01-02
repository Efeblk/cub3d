#include "cub3d.h"

void draw_player(void *mlx, void *window, char **map, t_game *game)
{
    (void)map;
    printf("x: %f, y: %f\n", game->map->player->x, game->map->player->y);
    mlx_pixel_put(mlx, window, game->map->player->x * BLOCK_SIZE, game->map->player->y * BLOCK_SIZE, 0x00FF00);
}