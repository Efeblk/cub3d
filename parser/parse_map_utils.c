#include "cub3d.h"

void check_xpm(char *line)
{
    int i;
    printf("line: %s\n", line);
    i = ft_strlen(line) - 1;
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
            exit(0);
        }
        --i;
    }
    if (file_exists(line) == 0)
    {
        printf("XPM DOES NOT EXIST: %s\n", line);
        exit(0);
    }
}

void check_rgb(char *line)
{
    (void)line;
}

void w_xpm_to_map(char c1, char c2, char *line, t_map *map)
{
    if (c1 == 'W' && c2 == 'E')
    {
        map->we = ft_strdup(line);
    }
    else if (c1 == 'E' && c2 == 'A')
    {
        map->ea = ft_strdup(line);
    }
    else if (c1 == 'S' && c2 == 'O')
    {
        map->so = ft_strdup(line);
    }
    else if (c1 == 'N' && c2 == 'O')
    {
        map->no = ft_strdup(line);
    }
}