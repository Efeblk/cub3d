#include "cub3d.h"

void dir_to_zero(char *map_line)
{
    int i;

    i = 0;
    while (map_line[i])
    {
        if (map_line[i] == 'N' || map_line[i] == 'S' || map_line[i] == 'E' || map_line[i] == 'W')
        {
            map_line[i] = '0';
            break;
        }
        ++i;
    }
}

void check_more_maps(char *line, t_map *map)
{
    if (line[0] == '\n')
    {
        printf("another map\n");
        free_char_array(map->map);
        free(line);
        system("leaks cub3d");
        exit(0);
    }
}