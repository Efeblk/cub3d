/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibalik <ibalik@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 20:54:01 by ibalik            #+#    #+#             */
/*   Updated: 2024/02/20 17:31:47 by ibalik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	render(t_game *game)
{
	game->map->player->dir_x = cos(game->map->player->dir_radian);
	game->map->player->dir_y = sin(game->map->player->dir_radian);
	if (game->key == W)
		ft_move(game->map->player, 'N', game);
	else if (game->key == S)
		ft_move(game->map->player, 'S', game);
	else if (game->key == A)
		ft_move(game->map->player, 'W', game);
	else if (game->key == D)
		ft_move(game->map->player, 'E', game);
	else if (game->key == LEFT_ARROW)
		ft_turn((game->map->player), LEFT_ARROW);
	else if (game->key == RIGHT_ARROW)
		ft_turn((game->map->player), RIGHT_ARROW);
	routine(game);
	return (0);
}

void	routine(t_game *game)
{
	raycast(game);
	draw_minimap(game);
	draw_player(game);
	mlx_put_image_to_window(game->mlx, game->window, game->img->img, 0, 0);
}
