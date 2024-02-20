/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_rgb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibalik <ibalik@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 20:57:27 by ibalik            #+#    #+#             */
/*   Updated: 2024/02/20 14:20:15 by ibalik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_rgb(char *l, char c, t_map *map)
{
	t_checkrgb_helper	h;

	load_rgb_helper(&h);
	count_coma(l, map);
	while (l[h.i] && h.rgb_i < 3)
	{
		while (l[h.i] && (l[h.i] == ' ' || l[h.i] == '\t'))
			++h.i;
		if (l[h.i] && !(l[h.i] >= '0' && l[h.i] <= '9') && l[h.i] != ',')
			free_rgb_tmp(h.rgb, h.tmp_value, map);
		while (l[h.i] >= '0' && l[h.i] <= '9' )
		{
			h.tmp_value[h.tmp_i] = l[h.i];
			++h.i;
			++h.tmp_i;
		}
		h.tmp_value[h.tmp_i] = '\0';
		h.rgb[h.rgb_i] = ft_atoi(h.tmp_value);
		check_rgb_value(h.rgb[h.rgb_i], map, h.tmp_value, h.rgb);
		h.tmp_i = 0;
		++h.rgb_i;
		++h.i;
	}
	free(h.tmp_value);
	w_rgb_to_map(h.rgb, c, map);
}

void	load_rgb_helper(t_checkrgb_helper *helper)
{
	helper->tmp_i = 0;
	helper->i = 0;
	helper->rgb_i = 0;
	helper->tmp_value = (char *)malloc(sizeof(char) * 4);
	helper->rgb = (int *)malloc(sizeof(int) * 3);
}

void	free_rgb_tmp(int *rgb, char *tmp_value, t_map *map)
{
	free(tmp_value);
	free(rgb);
	free(map->helpers->free_line);
	exitor(0);
}
