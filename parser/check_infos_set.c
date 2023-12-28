#include "cub3d.h"

int check_infos_set(t_map *map)
{
    if (map->ea == NULL || map->so == NULL || map->we == NULL || map->no == NULL)
    {
        printf("Error\n INFOS ARE NOT SET");
        system("leaks cub3d");
        exit(0);
        return 0;
    }
    if (map->ceiling_color == -1 || map->floor_color == -1)
    {
        printf("Error\n INFOS ARE NOT SET");
        system("leaks cub3d");
        exit(0);
        return 0;
    }
    printf("INFOS ARE SET\n");
    return 1;
}