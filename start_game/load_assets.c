#include "cub3d.h"

void load_assets(void *mlx, t_game *game)
{
    int block_size = BLOCK_SIZE;
    game->assets->n = mlx_xpm_file_to_image(mlx, game->map->no, &block_size, &block_size);
    game->assets->s = mlx_xpm_file_to_image(mlx, game->map->so, &block_size, &block_size);
    game->assets->w = mlx_xpm_file_to_image(mlx, game->map->we, &block_size, &block_size);
    game->assets->e = mlx_xpm_file_to_image(mlx, game->map->ea, &block_size, &block_size);
    if (game->assets->n == NULL || game->assets->s == NULL || game->assets->w == NULL || game->assets->e == NULL)
    {
        printf("Error\nInvalid texture path\n");
        exit(0);
    }
}