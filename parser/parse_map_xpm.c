#include "cub3d.h"

void check_xpm(char *line, t_map *map)
{
    int i;

    i = last_spaces_tonull(line);
    while (line[i])
    {
        if (line[i] == 'm' && line[i - 1] == 'p' && line[i - 2] == 'x' && line[i - 3] == '.' /*&& line[i + 1] == '\0'*/)
        {
            printf("XPM OK: %s \n", line);
            break;
        }
        else
        {
            printf("c: %c%c%c%c\n", line[i], line[i - 1], line[i - 2], line[i - 3]);
            printf("XPM ERROR %s \n", line);
            free(map->free_line);
            system("leaks cub3d");
            exit(0);
        }
        --i;
    }
    if (file_exists(line) == 0)
    {
        free(map->free_line);
        printf("XPM DOES NOT EXIST: %s\n", line);
        system("leaks cub3d");
        exit(0);
    }
}

void w_xpm_to_map(char c1, char c2, char *line, t_map *map)
{
    if (c1 == 'W' && c2 == 'E')
    {
        if (map->we != NULL)
        {
            free(map->free_line);
            printf("Error\nMultiple WE\n");
            system("leaks cub3d");
            exit(0);
        }   
        map->we = ft_strdup(line);
    }
    else if (c1 == 'E' && c2 == 'A')
    {
        if (map->ea != NULL)
        {
            free(map->free_line);
            printf("Error\nMultiple EA\n");
            system("leaks cub3d");
            exit(0);
        }
        map->ea = ft_strdup(line);
    }
    else if (c1 == 'S' && c2 == 'O')
    {
        if (map->so != NULL)
        {
            free(map->free_line);
            printf("Error\nMultiple SO\n");
            system("leaks cub3d");
            exit(0);
        }
        map->so = ft_strdup(line);
    }
    else if (c1 == 'N' && c2 == 'O')
    {
        if (map->no != NULL)
        {
            free(map->free_line);
            printf("Error\nMultiple NO\n");
            system("leaks cub3d");
            exit(0);
        }
        map->no = ft_strdup(line);
    }
}