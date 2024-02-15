#include "cub3d.h"

int render(t_game *game)
{
	//may move ve static i kaldıralabilir öylesine durmakta şuan.
    static int i = 0;
    ++i;
    game->map->player->dirX = cos(game->map->player->dir_radian);
    game->map->player->dirY = sin(game->map->player->dir_radian);
    routine(game);
	static int may_move = 1;
	if(may_move == 1)
	{
		if (game->key == W)
			ft_move(game->map->player, 'N', game);
		else if (game->key == S)
			ft_move(game->map->player, 'S', game);
		else if (game->key == A)
			ft_move(game->map->player, 'W', game);
		else if (game->key == D)
			ft_move(game->map->player, 'E', game);
		may_move = 0;
	}
	if (game->key == LEFT_ARROW)
		ft_turn((game->map->player), LEFT_ARROW);
	else if (game->key == RIGHT_ARROW)
		ft_turn((game->map->player), RIGHT_ARROW);
    routine(game);
	if (i == 5)
	{
		may_move = 1;
		i = 0;
	}
    return 0;
}

void	routine(t_game *game)
{
	clearimg(game);
	raycast(game);
	mlx_put_image_to_window(game->mlx, game->window, game->img->img, 0, 0);
}