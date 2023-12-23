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

    fd = open(arg, O_RDONLY);
    while ((line = get_next_line(fd)))
    {
        printf("get_next_line: %s\n", line);
        parse_line(line, map);
        check_line(line, map);        
        free(line);
    }
    close(fd);
    read_write_map(arg,map);
}

void parse_line(char *line, t_map *map)
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
            printf("space or tab on empty line\n");
            exit(0);
        }
    }
    else
        map->line_to_skip++;
}

void check_line(char *line, t_map *map)
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
                printf("MAP STARTS\n");
                parse_map_line(line, map);
            }
            else
            {
                map->line_to_skip++;
                route_valid(&line[i], map);
            }   
            break;
        }
        else
        {
            printf("Invalid character in infos: %c\n", line[i]);
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
            check_xpm(&line[i]);
            w_xpm_to_map(line[0], line[1], &line[i], map);
        }
        else if (line[i] == 'F' || line[i] == 'C')
        {
            check_rgb(&line[2], line[0], map);
        }  
}