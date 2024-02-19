#include "cub3d.h"

int	close_window(void)
{
	printf("Window closed\n");
	system("leaks cub3d");
	exit(1);
}

void	open_window(t_game *game)
{
	game->window = mlx_new_window(game->mlx,
			game->window_width, game->window_height, "My MiniLibX Window");
}
