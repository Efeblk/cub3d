#include "cub3d.h"

void	check_vertical_walls(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	while (map->map[x])
	{
		y = 0;
		while (map->map[x][y])
		{
			if (map->map[x][y] == '0')
			{
				if (map->map[x - 1][y] == ' ' || map->map[x + 1][y] == ' '
					|| map->map[x - 1][y] == '\0' || map->map[x + 1][y] == '\0')
				{
					printf("Error\nMap vertical walls\n");
					free_char_array(map->map);
					exit(0);
				}
			}
			++y;
		}
		++x;
	}
	to_original_map(map);
}

void	to_original_map(t_map *map)
{
	char	**original_map;
	int		i;

	i = 1;
	original_map = malloc(sizeof(char *) * (map->map_height + 1));
	while (i < map->map_height + 1)
	{
		original_map[i - 1] = ft_strdup(map->map[i]);
		++i;
	}
	original_map[i - 1] = NULL;
	free_char_array(map->map);
	map->map = original_map;
}