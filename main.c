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
    t_map map;
    t_game game;
    t_helpers helpers;
    t_player player;

    map_init(&map, &helpers, &player);
    if (argc == 2)
    {
        parse_arg(argv[1]);
        parse_map(argv[1], &map);
        game.map = &map;
        init_game(&game);
    }
    else if (argc > 2)
    {
        printf("Error\nToo many arguments\n");
    }
    else
    {
        printf("Error\nNo arguments\n");
    }
    system("leaks cub3d");
    print_char_array(map.map);
    printf("map C: %d\n", map.ceiling_color);
    printf("map F: %d\n", map.floor_color);
    return 0;
}
