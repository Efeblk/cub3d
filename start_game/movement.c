#include "cub3d.h"

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
		player->posX += player->dirX * (MOVE_SPEED + OFFSET);
		player->posY += player->dirY * (MOVE_SPEED + OFFSET);
		if (is_collide(player->posX, player->posY, game->map->map))
		{
			player->posX -= player->dirX * (MOVE_SPEED + OFFSET);
			player->posY -= player->dirY * (MOVE_SPEED + OFFSET);
		}
	}
	if (dir == 'S')
	{
		player->posX -= player->dirX * (MOVE_SPEED + OFFSET);
		player->posY -= player->dirY * (MOVE_SPEED + OFFSET);
		if (is_collide(player->posX, player->posY, game->map->map))
		{
			player->posX += player->dirX * (MOVE_SPEED + OFFSET);
			player->posY += player->dirY * (MOVE_SPEED + OFFSET);
		}
	}
	if (dir == 'E')
	{
		player->posX -= player->dirY * (MOVE_SPEED + OFFSET);
		player->posY += player->dirX * (MOVE_SPEED + OFFSET);
		if (is_collide(player->posX, player->posY, game->map->map))
		{
			player->posX += player->dirY * (MOVE_SPEED + OFFSET);
			player->posY -= player->dirX * (MOVE_SPEED + OFFSET);
		}
	}
	if (dir == 'W')
	{
		player->posX += player->dirY * (MOVE_SPEED + OFFSET);
		player->posY -= player->dirX * (MOVE_SPEED + OFFSET);
		if (is_collide(player->posX, player->posY, game->map->map))
		{
			player->posX -= player->dirY * (MOVE_SPEED + OFFSET);
			player->posY += player->dirX * (MOVE_SPEED + OFFSET);
		}
	}
}

int	is_collide(double new_x, double new_y, char **map)
{
	if (map[(int)(new_y)][(int)(new_x)] == '1' || map[(int)(new_y)][(int)(new_x)] == ' ' || map[(int)(new_y)][(int)(new_x)] == '\0')
    {
        return (1);
    }
	return (0);
}
