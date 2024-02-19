#include "cub3d.h"

void	free_game(t_game *game)
{
    free_map(game->map);
    free(game->img->img);
    free(game->img->addr);
    free_assets(game->assets);
    free(game->mlx);
    free(game->window);
}

void    free_map(t_map *map)
{
    free_char_array(map->map);
    free(map->ea);
    free(map->so);
    free(map->we);
    free(map->no);
}

void free_img_data(t_img_data *img)
{
    free(img->img);
    free(img->addr);
    free(img);
}

void free_assets(t_assets *assets)
{
    free_img_data(assets->n);
    free_img_data(assets->s);
    free_img_data(assets->w);
    free_img_data(assets->e);
}