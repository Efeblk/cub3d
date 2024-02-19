/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibalik <ibalik@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 20:53:35 by ibalik            #+#    #+#             */
/*   Updated: 2024/02/19 20:53:38 by ibalik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	my_get_pixel_color(t_img_data *img, int x, int y)
{
	char			*pixel_addr;
	unsigned int	*pixel;

	pixel_addr = img->addr
		+ (y * img->line_length + x * (img->bits_per_pixel / 8));
	pixel = (unsigned int *)pixel_addr;
	return (*pixel);
}

void	draw_empty_block(t_game *game, int x, int y)
{
	int	dx;
	int	dy;
	int	px;
	int	py;

	dx = 0;
	dy = 0;
	while (dy < game->block_size_2d)
	{
		dx = 0;
		while (dx < game->block_size_2d)
		{
			px = x + dx;
			py = y + dy;
			my_mlx_pixel_put(game->img, px, py, 0);
			dx++;
		}
		dy++;
	}
}

void	draw_wall_block(t_game *game, int x, int y, t_img_data *img)
{
	int	dx;
	int	dy;
	int	px;
	int	py;
	int	color;

	dx = 0;
	dy = 0;
	while (dy < game->block_size_2d)
	{
		dx = 0;
		while (dx < game->block_size_2d)
		{
			px = x + dx;
			py = y + dy;
			color = my_get_pixel_color(img, px % BLOCK_SIZE, py % BLOCK_SIZE);
			my_mlx_pixel_put(game->img, px, py, color);
			dx++;
		}
		dy++;
	}
}

void	draw_minimap(t_game *game)
{
	int	i;
	int	j;
	int	x;
	int	y;
	int	block_size;

	i = 0;
	block_size = game->block_size_2d;
	while (i < game->map->map_height)
	{
		j = 0;
		while (j < game->map->map[i][j] != '\0')
		{
			x = j * block_size;
			y = i * block_size;
			if (game->map->map[i][j] == '1')
				draw_wall_block(game, x, y, game->assets->n);
			else
				draw_empty_block(game, x, y);
			j++;
		}
		i++;
	}
}
