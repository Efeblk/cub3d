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

void parse_map(char *arg)
{
    int fd;
    char *line;

    fd = open(arg, O_RDONLY);
    while ((line = get_next_line(fd)))
    {
        printf("%s\n", line);
        check_line(line);        
        free(line);
    }
    close(fd);
}

void check_line(char *line)
{
    int i;

    i = 0;
    while (line[i])
    {
        while (line[i] == ' ' || line[i] == '\t')
            i++;
        if ((line[i] != 'W' && line[i + 1] != 'E') || 
        (line[i] != 'E' && line[i + 1] != 'A') || 
        (line[i] != 'S' && line[i + 1] != 'O') || 
        (line[i] != 'N' || line[i + 1] != 'O') || 
        line[i] != 'F' || 
        line[i] != 'C')
        {
            printf("Invalid character in map");
            exit(0);    
        }
        else
        {
            route_valid(&line[i]);
        }
        i++;
    }
}

void route_valid(char *line)
{ 
    int i;
    i = 0;
    if ((line[i] != 'W' && line[i + 1] != 'E') || 
        (line[i] != 'E' && line[i + 1] != 'A') || 
        (line[i] != 'S' && line[i + 1] != 'O') || 
        (line[i] != 'N' || line[i + 1] != 'O'))
        {
            check_xpm(&line[2]);
        }
        else if (line[i] != 'F' || line[i] != 'C')
        {
            check_rgb(&line[2]);
        }
}