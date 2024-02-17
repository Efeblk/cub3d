#include "cub3d.h"

void	check_xpm(char *line, t_map *map)
{
	int	i;

	i = last_spaces_tonull(line);
	while (line[i])
	{
		if (line[i] == 'm' && line[i - 1] == 'p'
			&& line[i - 2] == 'x' && line[i - 3] == '.')
		{
			printf("XPM OK: %s \n", line);
			break ;
		}
		else
		{
			printf("XPM ERROR %s \n", line);
			free(map->helpers->free_line);
			exit(0);
		}
		--i;
	}
	if (file_exists(line) == 0)
	{
		free(map->helpers->free_line);
		printf("XPM DOES NOT EXIST: %s\n", line);
		exit(0);
	}
}

void	w_xpm_to_map(char c1, char c2, char *line, t_map *map)
{
	if (c1 == 'W' && c2 == 'E')
	{
		if (map->we != NULL)
			free_and_exit_xpm(map, 0);
		map->we = ft_strdup(line);
	}
	else if (c1 == 'E' && c2 == 'A')
	{
		if (map->ea != NULL)
			free_and_exit_xpm(map, 1);
		map->ea = ft_strdup(line);
	}
	else if (c1 == 'S' && c2 == 'O')
	{
		if (map->so != NULL)
			free_and_exit_xpm(map, 2);
		map->so = ft_strdup(line);
	}
	else if (c1 == 'N' && c2 == 'O')
	{
		if (map->no != NULL)
			free_and_exit_xpm(map, 3);
		map->no = ft_strdup(line);
	}
}

void	free_and_exit_xpm(t_map *map, int error)
{
	if (error == 0)
		printf("Error\nMultiple WE\n");
	else if (error == 1)
		printf("Error\nMultiple EA\n");
	else if (error == 2)
		printf("Error\nMultiple SO\n");
	else if (error == 3)
		printf("Error\nMultiple NO\n");
	free(map->helpers->free_line);
	exit(0);
}
