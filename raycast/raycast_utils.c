/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibalik <ibalik@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 14:03:46 by mkaraden          #+#    #+#             */
/*   Updated: 2024/02/12 15:39:45 by ibalik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//init ray struct
void	init_ray(t_game *game, t_ray *ray, double angle)
{
	ray->ray_dir.x = cos(angle);
	ray->ray_dir.y = sin(angle);
	ray->map_x = (int)game->map->player->posX;
	ray->map_y = (int)game->map->player->posY;
	ray->delta_dist.x = fabs(1 / ray->ray_dir.x);
	ray->delta_dist.y = fabs(1 / ray->ray_dir.y);
	ray->hit = 0;
}

int	is_hit(t_ray *ray, t_game *game)
{
	if (is_boundary_violated(ray, game->map->map_width))
		return (1);
	if (game->map->map[ray->map_y][ray->map_x] == '1')
		return (1);
	return (0);
}

//check boundaries
int	is_boundary_violated(t_ray *ray, int map_size)
{
	if (ray->map_x < 0 || ray->map_y < 0)
		return (1);
	if (ray->map_x >= map_size || ray->map_y >= map_size)
		return (1);
	return (0);
}

void	clearimg(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (++i < WINDOW_WIDTH)
	{
		while (++j < WINDOW_HEIGHT)
		{
			my_mlx_pixel_put((game->img), i, j, 0x00000000);
		}
	}
}

void	my_mlx_pixel_put(t_img_data *data, int x, int y, int color)
{
	char	*dst;
	int		offset;

	if (x < 0 || x >= WINDOW_WIDTH || y < 0 || y >= WINDOW_HEIGHT)
		return ;
	offset = (y * data->line_length + x * (data->bits_per_pixel / 8));
	dst = data->addr + offset;
	*(unsigned int *)dst = color;
}