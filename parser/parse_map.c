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
        parse_line(line);
        check_line(line, map);        
        free(line);
    }
    close(fd);
}

void parse_line(char *line)
{
    int i;

    i = ft_strlen(line) - 1;
    line[i] = '\0';
}

void check_line(char *line, t_map *map)
{
    int i = 0;

    while (line[i])
    {
        while (line[i] == ' ' || line[i] == '\t')
            i++;
        if ((line[i] != 'W' || line[i + 1] != 'E') && 
            (line[i] != 'E' || line[i + 1] != 'A') && 
            (line[i] != 'S' || line[i + 1] != 'O') && 
            (line[i] != 'N' || line[i + 1] != 'O') && 
            line[i] != 'F' && 
            line[i] != 'C')
        {
            ++i; 
        }
        else
        {
            printf("Valid character in map: %c%c\n", line[i], line[i + 1]);
            route_valid(&line[i], map);
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
        else if (line[i] != 'F' || line[i] != 'C')
        {
            check_rgb(&line[2]);
        }
}