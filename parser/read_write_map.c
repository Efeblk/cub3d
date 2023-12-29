#include "cub3d.h"

void read_write_map(char *mapname, t_map *map)
{
    int fd;

    fd = open(mapname, O_RDONLY, 0644);
    map->map = malloc(sizeof(char *) * (map->map_height + 3)); //null + top + bottom
    skip_lines(map->line_to_skip, fd);
    fill_map(fd, map);
}

void fill_map(int fd, t_map *map)
{
    int i;
    char *line;

    map->map[0] = fill_with_spaces(map->map_width); //mapin üstüne boşluk
    i = 1;
    while ((line = get_next_line(fd)) && i < map->map_height + 1)
    {
        if (line[0] == '\n')
        {
            printf("another map\n");
            free_char_array(map->map);
            free(line);
            system("leaks cub3d");
            exit(0);
        }
        newline_to_null(line);
        map->map[i] = ft_strdup(line);
        ++i;
        free(line);
    }
    free(line);
    map->map[i] = fill_with_spaces(map->map_width);
    map->map[i + 1] = NULL;
}

void skip_lines(int line_to_skip, int fd)
{
    char *line;

    while (line_to_skip > 0)
    {
        line = get_next_line(fd);
        free(line);
        --line_to_skip;
    }
}

char *fill_with_spaces(int line_width)
{
    int i;
    char *space_line;
    space_line = malloc(sizeof(char) * (line_width + 1));
    space_line[line_width] = '\0';
    i = 0;
    while (i < line_width)
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
