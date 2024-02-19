/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibalik <ibalik@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 20:52:25 by ibalik            #+#    #+#             */
/*   Updated: 2024/02/19 20:52:26 by ibalik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	close_window(t_game *game)
{
	free_game(game);
	exit(0);
}

void	open_window(t_game *game)
{
	game->window = mlx_new_window(game->mlx,
			game->window_width, game->window_height, "My MiniLibX Window");
}
