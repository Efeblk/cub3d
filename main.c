/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibalik <ibalik@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:58:04 by ibalik            #+#    #+#             */
/*   Updated: 2024/02/07 15:55:42 by ibalik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_game		game;
	t_map		map;
	t_helpers	helpers;
	t_player	player;

	map_init(&map, &helpers, &player);
	if (argc == 2)
	{
		parse_arg(argv[1]);
		parse_map(argv[1], &map);
		game.map = &map;
		start_game(&game);
	}
	else if (argc > 2)
	{
		printf("Error\nToo many arguments\n");
	}
	else
	{
		printf("Error\nNo arguments\n");
	}
	return (0);
}
