/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibalik <ibalik@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 20:53:59 by ibalik            #+#    #+#             */
/*   Updated: 2024/02/20 17:31:45 by ibalik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_turn(t_player *player, char dir)
{
	if (dir == LEFT_ARROW)
	{
		player->dir_radian -= ROT_SPEED;
		if (player->dir_radian < 0)
			player->dir_radian += 2 * M_PI;
	}
	if (dir == RIGHT_ARROW)
	{
		player->dir_radian += ROT_SPEED;
		if (player->dir_radian > 2 * M_PI)
			player->dir_radian -= 2 * M_PI;
	}
}

void	ft_move(t_player *player, int dir, t_game *game)
{
	if (dir == 'N')
	{
		player->pos_x += player->dir_x * (MOVE_SPEED);
		player->pos_y += player->dir_y * (MOVE_SPEED);
		if (is_collide(player->pos_x, player->pos_y, game->map->map))
		{
			player->pos_x -= player->dir_x * (MOVE_SPEED);
			player->pos_y -= player->dir_y * (MOVE_SPEED);
		}
	}
	else if (dir == 'S')
	{
		player->pos_x -= player->dir_x * (MOVE_SPEED);
		player->pos_y -= player->dir_y * (MOVE_SPEED);
		if (is_collide(player->pos_x, player->pos_y, game->map->map))
		{
			player->pos_x += player->dir_x * (MOVE_SPEED);
			player->pos_y += player->dir_y * (MOVE_SPEED);
		}
	}
	else if (dir == 'E' || dir == 'W')
		ft_move2(player, dir, game);
}

void	ft_move2(t_player *player, int dir, t_game *game)
{
	if (dir == 'E')
	{
		player->pos_x -= player->dir_y * (MOVE_SPEED);
		player->pos_y += player->dir_x * (MOVE_SPEED);
		if (is_collide(player->pos_x, player->pos_y, game->map->map))
		{
			player->pos_x += player->dir_y * (MOVE_SPEED);
			player->pos_y -= player->dir_x * (MOVE_SPEED);
		}
	}
	else if (dir == 'W')
	{
		player->pos_x += player->dir_y * (MOVE_SPEED);
		player->pos_y -= player->dir_x * (MOVE_SPEED);
		if (is_collide(player->pos_x, player->pos_y, game->map->map))
		{
			player->pos_x -= player->dir_y * (MOVE_SPEED);
			player->pos_y += player->dir_x * (MOVE_SPEED);
		}
	}
}

int	is_collide(double new_x, double new_y, char **map)
{
	if (map[(int)(new_y)][(int)(new_x)] == '1'
		|| map[(int)(new_y)][(int)(new_x)] == ' '
		|| map[(int)(new_y)][(int)(new_x)] == '\0')
	{
		return (1);
	}
	return (0);
}
