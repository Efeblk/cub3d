#include "cub3d.h"

void	check_rgb_value(int value, t_map *map, char *tmp_value, int *rgb)
{
	if (value < 0 || value > 255)
	{
		free(rgb);
		free(tmp_value);
		free(map->helpers->free_line);
		printf("Error\n RGB value not between 0 and 255\n");
		exit(0);
	}
}

void	count_coma(char *line, t_map *map)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (line[i])
	{
		if (line[i] == ',')
			count++;
		i++;
	}
	if (count != 2)
	{
		free(map->helpers->free_line);
		printf("Error\n RGB value not valid\n");
		exit(0);
	}
}
