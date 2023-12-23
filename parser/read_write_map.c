#include "cub3d.h"

void read_write_map(char *mapname, t_map *map)
{
    int fd;
    char *line;
    int i;

    fd = open(mapname, O_RDONLY, 0644);
    map->map = malloc(sizeof(char *) * (map->map_height + 3)); //null + top + bottom
    i = 0;
    printf("linetoskip: %d\n", map->line_to_skip);
    map->map[0] = fill_with_spaces(map->map_width);
    while (i < map->line_to_skip)
    {
        get_next_line(fd);
        i++;
    }
    i = 1;
    while ((line = get_next_line(fd)))
    {
        newline_to_null(line);
        map->map[i] = ft_strdup(line);
        ++i;
    }
    map->map[i] = fill_with_spaces(map->map_width);
    map->map[i + 1] = NULL;
    print_char_array(map->map);
}

char *fill_with_spaces(int line_width)
{
    int i;
    char *space_line;

    space_line = malloc(sizeof(char) * (line_width + 1));
    space_line[line_width] = '\0';
    i = 0;
    while (space_line[i] != '\0')
    {
        space_line[i] = ' ';
        ++i;
    }
    return space_line;
}

void newline_to_null(char *line)
{
    int i;

    i = ft_strlen(line) - 1;
    if (line[i] == '\n')
    {
        line[i] = '\0';
    }
}