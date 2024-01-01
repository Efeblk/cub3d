#include "cub3d.h"

void load_assets(void *mlx, t_game *game)
{
    int height = 64;
    int width = 64;

    game->assets->n = mlx_xpm_file_to_image(mlx, game->map->no, &height, &width);
    game->assets->s = mlx_xpm_file_to_image(mlx, game->map->so, &height, &width);
    game->assets->w = mlx_xpm_file_to_image(mlx, game->map->we, &height, &width);
    game->assets->e = mlx_xpm_file_to_image(mlx, game->map->ea, &height, &width);
}