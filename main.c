/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibalik <ibalik@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:58:04 by ibalik            #+#    #+#             */
/*   Updated: 2023/12/14 17:37:02 by ibalik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int argc, char **argv)
{
    // int fd;

    // fd = open("assets/colorstone.xpm", O_RDONLY);
    // if (fd == -1)
    // {
    //     printf("Error\nFile not found\n");
    // }
    // else
    // {
    //     printf("fd: %d\n", fd);
    //     close(fd);
    // }
    t_map map;
    if (argc == 2)
    {
        parse_arg(argv[1]);
        parse_map(argv[1], &map);
    }
    else if (argc > 2)
    {
        printf("Error\nToo many arguments\n");
    }
    else
    {
        printf("Error\nNo arguments\n");
    }
    return 0;
}
