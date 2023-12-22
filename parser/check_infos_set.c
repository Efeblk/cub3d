#include "cub3d.h"

void check_infos_set(t_map *map)
{
    // if (map->map_width == 0 || map->map_height == 0)
    // {
    //     printf("Error\n");
    //     exit(0);
    // }
    if (map->ea == NULL || map->so == NULL || map->we == NULL || map->no == NULL)
    {
        printf("Error\n INFOS ARE NOT SET");
        exit(0);
    }
    if (map->ceiling_color == -1 || map->floor_color == -1)
    {
        printf("Error\n INFOS ARE NOT SET");
        exit(0);
    }
    printf("INFOS ARE SET\n");
}