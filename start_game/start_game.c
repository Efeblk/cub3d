/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibalik <ibalik@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 20:54:05 by ibalik            #+#    #+#             */
/*   Updated: 2024/02/20 14:43:50 by ibalik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	start_game(t_game *game)
{
	t_assets	assets;
	t_img_data	img;

	game->mlx = mlx_init();
	game->img = &img;
	game->assets = &assets;
	init_game(game);
	mlx_loop(game->mlx);
}
