/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibalik <ibalik@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 20:53:50 by ibalik            #+#    #+#             */
/*   Updated: 2024/02/19 20:53:52 by ibalik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_press(int key, t_game *game)
{
	game->key = key;
	if (key == ESC)
		close_window(game);
	return (0);
}

int	ft_release(int key, t_game *game)
{
	if (key == game->key)
		game->key = -1;
	return (0);
}
