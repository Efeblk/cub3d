#include "cub3d.h"

void map_init(t_map *map, t_helpers *helpers, t_player *player)
{
    helpers->all_infos_set = 0;
    helpers->line_to_skip = 0;
    helpers->free_line = NULL;
    player->posX = 0;
    player->posY = 0;
    player->dir = 'x';
    map->player = player;
    map->helpers = helpers;
    map->map = NULL;
    map->map_width = 0;
    map->map_height = 0;
    map->ea = NULL;
    map->so = NULL;
    map->we = NULL;
    map->no = NULL;
    map->ceiling_color = -1;
    map->floor_color = -1;
}