/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibalik <ibalik@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 17:37:25 by ibalik            #+#    #+#             */
/*   Updated: 2023/12/14 17:50:55 by ibalik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void parse_map(char *arg)
{
    int fd;
    char *line;
    int i;

    i = 0;
    fd = open(arg, O_RDONLY);
    while (get_next_line(fd, &line))
    {
        printf("%s\n", line);
        while (*line == ' ' || *line == '\t')
            line++;
        
        
        free(line);
    }
    close(fd);
}