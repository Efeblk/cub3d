/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibalik <ibalik@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 20:56:57 by ibalik            #+#    #+#             */
/*   Updated: 2024/02/20 14:19:20 by ibalik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_line(char *line, t_map *map, int line_count, int *map_start_flag)
{
	t_checkline_helper	help;

	help.map = map;
	help.line_count = line_count;
	help.map_start_flag = map_start_flag;
	help.line = line;
	help.i = 0;
	while (line[help.i])
	{
		while (line[help.i] == ' ' || line[help.i] == '\t')
			help.i++;
		if ((line[help.i] == 'W' && line[help.i + 1] == 'E')
			|| (line[help.i] == 'E' && line[help.i + 1] == 'A')
			|| (line[help.i] == 'S' && line[help.i + 1] == 'O')
			|| (line[help.i] == 'N' && line[help.i + 1] == 'O')
			|| line[help.i] == 'F' || line[help.i] == 'C'
			|| line[help.i] == '1' || line[help.i] == '0')
		{
			check_line2(&help);
			break ;
		}
		else
			freeline_and_exit(line);
		help.i++;
	}
}

void	check_line2(t_checkline_helper *helper)
{
	if ((helper->line[helper->i] == '1' || helper->line[helper->i] == '0')
		&& check_infos_set(helper->map) == 1)
	{
		if (*(helper->map_start_flag) == 0)
		{
			helper->map->helpers->line_to_skip = helper->line_count;
			*(helper->map_start_flag) = 1;
		}
		parse_map_line(helper->line, helper->map);
	}
	else
		route_valid(&helper->line[helper->i], helper->map);
}

void	freeline_and_exit(char *line)
{
	free(line);
	printf("Error\nInvalid character in infos\n");
	exitor(0);
}
