#include "cub3d.h"

void	check_line(char *line, t_map *map, int line_count, int *map_start_flag)
{
	t_checkline_helper	helper;

	helper.map = map;
	helper.line_count = line_count;
	helper.map_start_flag = map_start_flag;
	helper.line = line;
	helper.i = 0;
	while (line[helper.i])
	{
		while (line[helper.i] == ' ' || line[helper.i] == '\t')
			helper.i++;
		if ((line[helper.i] == 'W' && line[helper.i + 1] == 'E') ||
			(line[helper.i] == 'E' && line[helper.i + 1] == 'A') ||
			(line[helper.i] == 'S' && line[helper.i + 1] == 'O') ||
			(line[helper.i] == 'N' && line[helper.i + 1] == 'O') ||
			line[helper.i] == 'F' ||
			line[helper.i] == 'C' || line[helper.i] == '1' || line[helper.i] == '0')
		{
			check_line2(&helper);
			break ;
		}
		else
			freeline_and_exit(line);
		helper.i++;
	}
}

void check_line2(t_checkline_helper *helper)
{
	if ((helper->line[helper->i] == '1' || helper->line[helper->i] == '0') && check_infos_set(helper->map) == 1)
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
	exit(0);
}
