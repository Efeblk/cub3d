#include "cub3d.h"

int	ft_press(int key, t_game *game)
{
	game->key = key;
	if (key == ESC)
		close_window();
	return (0);
}

int	ft_release(int key, t_game *game)
{
	if (key == game->key)
		game->key = -1;
	return (0);
}
