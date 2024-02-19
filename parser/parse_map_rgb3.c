/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_rgb3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibalik <ibalik@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 20:57:32 by ibalik            #+#    #+#             */
/*   Updated: 2024/02/19 20:57:33 by ibalik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	w_rgb_to_map(int *rgb, char c, t_map *map)
{
	if (c == 'F')
	{
		if (map->floor_color == -1)
		{
			map->floor_color = (rgb[0] << 16) + (rgb[1] << 8) + rgb[2];
			free(rgb);
		}
		else
		{
			free_rgb(rgb, map, 0);
		}
	}
	else if (c == 'C')
	{
		if (map->ceiling_color == -1)
		{
			map->ceiling_color = (rgb[0] << 16) + (rgb[1] << 8) + rgb[2];
			free(rgb);
		}
		else
		{
			free_rgb(rgb, map, 1);
		}
	}
}

void	free_rgb(int *rgb, t_map *map, int f_or_c)
{
	if (f_or_c == 0)
		printf("Error\n multiple floor color\n");
	else if (f_or_c == 1)
		printf("Error\n Multiple ceiling color\n");
	free(rgb);
	free(map->helpers->free_line);
	exit(0);
}
