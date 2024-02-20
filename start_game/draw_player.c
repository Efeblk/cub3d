/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibalik <ibalik@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 20:53:44 by ibalik            #+#    #+#             */
/*   Updated: 2024/02/20 17:31:36 by ibalik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_circle(t_img_data *data, int center_x, int center_y, int color)
{
	t_circle_helper	helper;

	helper.x = 4;
	helper.y = 0;
	helper.err = 0;
	helper.color = color;
	while (helper.x >= helper.y)
	{
		circle(&helper, data, center_x, center_y);
		if (helper.err <= 0)
		{
			helper.y += 1;
			helper.err += 2 * helper.y + 1;
		}
		if (helper.err > 0)
		{
			helper.x -= 1;
			helper.err -= 2 * helper.x + 1;
		}
	}
}

void	circle(t_circle_helper *helper, t_img_data *data, int c_x, int c_y)
{
	my_mlx_pixel_put(data, c_x + helper->x, c_y + helper->y, helper->color);
	my_mlx_pixel_put(data, c_x + helper->y, c_y + helper->x, helper->color);
	my_mlx_pixel_put(data, c_x - helper->y, c_y + helper->x, helper->color);
	my_mlx_pixel_put(data, c_x - helper->x, c_y + helper->y, helper->color);
	my_mlx_pixel_put(data, c_x - helper->x, c_y - helper->y, helper->color);
	my_mlx_pixel_put(data, c_x - helper->y, c_y - helper->x, helper->color);
	my_mlx_pixel_put(data, c_x + helper->y, c_y - helper->x, helper->color);
	my_mlx_pixel_put(data, c_x + helper->x, c_y - helper->y, helper->color);
}

void	draw_player(t_game *game)
{
	int	player_2d_x;
	int	player_2d_y;

	player_2d_x = game->map->player->pos_x * game->block_size_2d;
	player_2d_y = game->map->player->pos_y * game->block_size_2d;
	draw_circle(game->img, player_2d_x,
		player_2d_y, 0x00FF00);
}
