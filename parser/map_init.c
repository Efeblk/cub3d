#include "cub3d.h"

void map_init(t_map *map)
{
    map->map = NULL;
    map->map_width = 0;
    map->map_height = 0;
    map->player_dir = 'x';
    map->ea = NULL;
    map->so = NULL;
    map->we = NULL;
    map->no = NULL;
    map->ceiling_color = -1;
    map->floor_color = -1;
    map->all_infos_set = 0;
    map->line_to_skip = 0;
}