/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibalik <ibalik@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 17:37:25 by ibalik            #+#    #+#             */
/*   Updated: 2023/12/14 18:15:42 by ibalik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void parse_map(char *arg, t_map *map)
{
    int fd;
    char *line;
    int line_count;
    int map_start_flag;

    map_start_flag = 0;
    line_count = 0;
    fd = open(arg, O_RDONLY);
    while ((line = get_next_line(fd)))
    {
        map->free_line = line; //exit olunca orijinal line free yapmak icin
        parse_line(line);
        check_line(line, map, line_count, &map_start_flag);        
        free(line);
        line_count++;
    }
    close(fd);
    read_write_map(arg,map);
    print_char_array(map->map);
    check_vertical_walls(map);
    system("leaks cub3d");
    printf("MAP IS OK!\n");
}

void parse_line(char *line)
{
    int i;

    i = ft_strlen(line) - 1;
    if (line[i] == '\n')
    {
        line[i] = '\0';
    }
    if (i > 0)
    {
        i = 0;
        while (line[i] && (line[i] == ' ' || line[i] == '\t'))
        {
            ++i;
        }
        if (line[i] == '\0')
        {
            free(line);
            printf("space or tab on empty line\n");
            system("leaks cub3d");
            exit(0);
        }
    }    
}

void check_line(char *line, t_map *map, int line_count, int *map_start_flag)
{
    int i = 0;

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
        {
            free(line);
            printf("Invalid character in infos: %c\n", line[i]);
            system("leaks cub3d");
            exit(0);
        }
        i++;
    }
}

void route_valid(char *line, t_map *map)
{ 
    int i;

    i = 0;
    if ((line[i] == 'W' && line[i + 1] == 'E') || 
        (line[i] == 'E' && line[i + 1] == 'A') || 
        (line[i] == 'S' && line[i + 1] == 'O') || 
        (line[i] == 'N' && line[i + 1] == 'O'))
        {
            i += 2;
            while (line[i] == ' ' || line[i] == '\t' || line[i] == '.' || line[i] == '/')
                i++;
            check_xpm(&line[i], map);
            w_xpm_to_map(line[0], line[1], &line[i], map);
        }
        else if (line[i] == 'F' || line[i] == 'C')
        {
            check_rgb(&line[2], line[0], map);
        }  
}