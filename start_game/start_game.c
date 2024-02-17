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
