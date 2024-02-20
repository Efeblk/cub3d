/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibalik <ibalik@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 17:37:25 by ibalik            #+#    #+#             */
/*   Updated: 2024/02/20 17:32:26 by ibalik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	parse_map(char *arg, t_map *map)
{
	int		fd;
	char	*line;
	int		line_count;
	int		map_start_flag;

	map_start_flag = 0;
	line_count = 0;
	fd = open(arg, O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		map->helpers->free_line = line;
		parse_line(line);
		check_line(line, map, line_count, &map_start_flag);
		free(line);
		line_count++;
		line = get_next_line(fd);
	}
	close(fd);
	read_write_map(arg, map);
	check_vertical_walls(map);
}

void	parse_line(char *line)
{
	int	i;

	i = ft_strlen(line) - 1;
	if (line[i] == '\n')
	{
		line[i] = '\0';
	}
	if (i > 0)
	{
		i = 0;
		while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		{
			++i;
		}
		if (line[i] == '\0')
		{
			free(line);
			printf("Error\nSpace or tab on empty line\n");
			exitor(0);
		}
	}
}

void	route_valid(char *line, t_map *map)
{
	int	i;

	i = 0;
	if ((line[i] == 'W' && line[i + 1] == 'E')
		|| (line[i] == 'E' && line[i + 1] == 'A')
		|| (line[i] == 'S' && line[i + 1] == 'O')
		|| (line[i] == 'N' && line[i + 1] == 'O'))
	{
		i += 2;
		while (line[i] == ' ' || line[i] == '\t'
			|| line[i] == '.' || line[i] == '/')
			i++;
		check_xpm(&line[i], map);
		w_xpm_to_map(line[0], line[1], &line[i], map);
	}
	else if (line[i] == 'F' || line[i] == 'C')
	{
		check_rgb(&line[2], line[0], map);
	}
}
