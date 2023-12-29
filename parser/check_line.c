#include "cub3d.h"

void check_line(char *line, t_map *map, int line_count, int *map_start_flag)
{
    int i;

    i = 0;
    while (line[i])
    {
        while (line[i] == ' ' || line[i] == '\t')
            i++;
        if ((line[i] == 'W' && line[i + 1] == 'E') || 
            (line[i] == 'E' && line[i + 1] == 'A') || 
            (line[i] == 'S' && line[i + 1] == 'O') ||  
            (line[i] == 'N' && line[i + 1] == 'O') || 
            line[i] == 'F' || 
            line[i] == 'C' || line[i] == '1' || line[i] == '0')
        {
            printf("Valid character in infos: %c%c\n", line[i], line[i + 1]);
            if ((line[i] == '1' || line[i] == '0') && check_infos_set(map) == 1)
            {
                if (*map_start_flag == 0)
                {
                    printf("map_start_flag: %s\n", line);
                    map->line_to_skip = line_count;
                    *map_start_flag = 1;
                } 
                parse_map_line(line, map);
            }
            else
            {
                route_valid(&line[i], map);
            }   
            break;
        }
        else
            freeline_and_exit(line);
        i++;
    }
}

void freeline_and_exit(char *line)
{
    free(line);
    printf("Error\nInvalid character in infos\n");
    system("leaks cub3d");
    exit(0);
}

// void route_maporinfo(char *line, int i, t_map *map, int *map_start_flag)
// {
    
// }