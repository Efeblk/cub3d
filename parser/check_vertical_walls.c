#include "cub3d.h"

void check_vertical_walls(t_map *map)
{
    printf("check_vertical_walls\n");
    int x;
    int y;

    x = 0;
    while (map->map[x])
    {
        y = 0;
        while (map->map[x][y])
        {
            if (map->map[x][y] == '0')
            {
                printf("x: %d, y: %d\n", x, y);
                if(map->map[x - 1][y] == ' ' || map->map[x + 1][y] == ' ')
                {
                    printf("Error\nMap vertical walls\n");
                    exit(0);
                }
            }
            ++y;
        }
        ++x;
    }
}