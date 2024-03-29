/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_write_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibalik <ibalik@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 20:57:42 by ibalik            #+#    #+#             */
/*   Updated: 2024/02/20 17:32:27 by ibalik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	read_write_map(char *mapname, t_map *map)
{
	int	fd;

	fd = open(mapname, O_RDONLY, 0644);
	map->map = malloc(sizeof(char *) * (map->map_height + 3));
	skip_lines(map->helpers->line_to_skip, fd);
	fill_map(fd, map);
}

void	fill_map(int fd, t_map *map)
{
	int		i;
	char	*line;

	map->map[0] = fill_with_spaces(map->map_width);
	i = 1;
	line = get_next_line(fd);
	while ((line != NULL) && i < map->map_height + 1)
	{
		check_more_maps(line, map);
		dir_to_zero(line);
		newline_to_null(line);
		map->map[i] = ft_strdup(line);
		++i;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	map->map[i] = fill_with_spaces(map->map_width);
	map->map[i + 1] = NULL;
}

void	skip_lines(int line_to_skip, int fd)
{
	char	*line;

	while (line_to_skip > 0)
	{
		line = get_next_line(fd);
		free(line);
		--line_to_skip;
	}
}

char	*fill_with_spaces(int line_width)
{
	int		i;
	char	*space_line;

	space_line = malloc(sizeof(char) * (line_width + 1));
	space_line[line_width] = '\0';
	i = 0;
	while (i < line_width)
	{
		space_line[i] = ' ';
		++i;
	}
	return (space_line);
}

void	newline_to_null(char *line)
{
	int	i;

	i = ft_strlen(line) - 1;
	if (line[i] == '\n')
	{
		line[i] = '\0';
	}
}
