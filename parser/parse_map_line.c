/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibalik <ibalik@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 20:57:21 by ibalik            #+#    #+#             */
/*   Updated: 2024/02/20 17:32:12 by ibalik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	parse_map_line(char *line, t_map *map)
{
	int	width;

	check_map_line(line, map);
	width = ft_strlen(line);
	if (width > map->map_width)
		map->map_width = width;
	map->map_height++;
}

void	check_map_line(char *line, t_map *map)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 'N' || line[i] == 'S' || line[i] == 'E'
			|| line[i] == 'W' || line[i] == '0'
			|| line[i] == '1' || line[i] == ' ')
		{
			if (check_player_dir(line[i], i, map))
				line[i] = '0';
			if (line[i] == '0')
				check_horizontal_walls(line, i);
		}
		else
		{
			free(map->helpers->free_line);
			printf("Error\nInvalid character in map: ' %d '\n", line[i]);
			exitor(0);
		}
		i++;
	}
}

void	check_horizontal_walls(char *line, int i)
{
	if (i == 0)
	{
		if (line[i + 1] == ' ' || line[i + 1] == '\0'
			|| line[i + 1] == '\n' || line[i - 1] == '\0')
		{
			free(line);
			printf("Error\nInvalid horizontal map\n");
			exitor(0);
		}
	}
	else
	{
		if (line[i - 1] == ' ' || line[i + 1] == ' '
			|| line[i + 1] == '\0' || line[i - 1] == '\n')
		{
			free(line);
			printf("Error\nInvalid horizontal map\n");
			exitor(0);
		}
	}
}

int	check_player_dir(char dir, int i, t_map *map)
{
	if (dir == 'N' || dir == 'S' || dir == 'E' || dir == 'W')
	{
		if (map->player->dir == 'x')
		{
			map->player->dir = dir;
			map->player->pos_x = i;
			map->player->pos_y = map->map_height;
			return (1);
		}
		else
		{
			free(map->helpers->free_line);
			printf("Error\nMultiple player positions\n");
			exitor(0);
		}
	}
	return (0);
}
