/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibalik <ibalik@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 20:57:11 by ibalik            #+#    #+#             */
/*   Updated: 2024/02/20 17:32:08 by ibalik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	map_init(t_map *map, t_helpers *helpers, t_player *player)
{
	helpers->all_infos_set = 0;
	helpers->line_to_skip = 0;
	helpers->free_line = NULL;
	player->pos_x = 0;
	player->pos_y = 0;
	player->dir = 'x';
	map->player = player;
	map->helpers = helpers;
	map->map = NULL;
	map->map_width = 0;
	map->map_height = 0;
	map->ea = NULL;
	map->so = NULL;
	map->we = NULL;
	map->no = NULL;
	map->ceiling_color = -1;
	map->floor_color = -1;
}
