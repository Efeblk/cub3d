#include "cub3d.h"

void check_rgb(char *line, char c,t_map *map)
{
    int i;
    char *tmp_value;
    int tmp_i;
    int *rgb;
    int rgb_i;

    tmp_i = 0;
    i = 0;
    rgb_i = 0;
    count_coma(line);
    tmp_value = (char *)malloc(sizeof(char) * 4);
    rgb = (int *)malloc(sizeof(int) * 3);
    while (line[i])
    {
        while (line[i] && (line[i] == ' ' || line[i] == '\t'))
            ++i;
        while (line[i] >= '0' && line[i] <= '9' )
        {
            tmp_value[tmp_i] = line[i];
            ++i;
            ++tmp_i;
        }
        tmp_value[tmp_i] = '\0';
        rgb[rgb_i] = ft_atoi(tmp_value);
        check_rgb_value(rgb[rgb_i]);
        tmp_i = 0;
        ++rgb_i;
        ++i;
    }
    w_rgb_to_map(rgb, c, map);
}

void w_rgb_to_map(int *rgb, char c, t_map *map)
{
    if (c == 'F')
    {
        if (map->floor_color == -1)
        {
            map->floor_color = (rgb[0] << 16) + (rgb[1] << 8) + rgb[2];
        }
        else
        {
            //free(rgb);
            printf("Error\n multiple floor color\n");
            exit(0);
        }
    }
    else if (c == 'C')
    {
        if (map->ceiling_color == -1)
        {
            map->ceiling_color = (rgb[0] << 16) + (rgb[1] << 8) + rgb[2];
        }
        else
        {
            //free(rgb);
            printf("Error\n Multiple ceiling color\n");
            exit(0);
        }
    }
}

void check_rgb_value(int value)
{
    if (value < 0 || value > 255)
    {
        printf("Error\n RGB value not between 0 and 255\n");
        exit(0);
    }
}

void count_coma(char *line)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while (line[i])
    {
        if (line[i] == ',')
            count++;
        i++;
    }
    if (count != 2)
    {
        printf("Error\n RGB value not valid\n");
        exit(0);
    }
}