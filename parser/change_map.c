#include "cub3d.h"

void change_map(t_map *map)
{
    int i;

    i = 0;
    while (map->map[1][i])
    {
        if (map->map[1][i] == '1')
        {
            map->map[1][i] = 'N';
        }
        i++;
    }
}