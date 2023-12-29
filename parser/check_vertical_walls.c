#include "cub3d.h"

void check_vertical_walls(t_map *map)
{
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
                if(map->map[x - 1][y] == ' ' || map->map[x + 1][y] == ' ')
                {
                    printf("Error\nMap vertical walls\n");
                    free_char_array(map->map);
                    system("leaks cub3d");
                    exit(0);
                }
            }
            ++y;
        }
        ++x;
    }
}