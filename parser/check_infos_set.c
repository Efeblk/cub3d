/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_infos_set.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibalik <ibalik@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 20:56:51 by ibalik            #+#    #+#             */
/*   Updated: 2024/02/19 20:56:52 by ibalik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_infos_set(t_map *map)
{
	if (map->ea == NULL || map->so == NULL
		|| map->we == NULL || map->no == NULL)
	{
		printf("Error\n INFOS ARE NOT SET");
		exit(0);
		return (0);
	}
	if (map->ceiling_color == -1 || map->floor_color == -1)
	{
		printf("Error\n INFOS ARE NOT SET");
		exit(0);
		return (0);
	}
	printf("INFOS ARE SET\n");
	return (1);
}
