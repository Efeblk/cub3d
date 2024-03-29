/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibalik <ibalik@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 20:56:30 by ibalik            #+#    #+#             */
/*   Updated: 2024/02/20 18:48:55 by ibalik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	raycast(t_game *game)
{
	double	angle;
	int		line_height;
	t_ray	ray;
	int		x;

	angle = game->map->player->dir_radian - FOV / 2;
	x = -1;
	while (++x < WINDOW_WIDTH)
	{
		init_ray(game, &ray, angle);
		calculate_step_and_dist(game, &ray);
		calculate_perpetual(game, &ray);
		determine_texture(game, &ray);
		calculate_texture_x(game, &ray);
		ray.perp_wall_dist *= cos(game->map->player->dir_radian - angle);
		line_height = safe_divide(WINDOW_HEIGHT, ray.perp_wall_dist);
		draw_textured_line(game, &ray, x, line_height);
		draw_floor_ceiling(game, x, line_height);
		angle += ANGLE_STEP;
	}
}

void	ray_step(t_ray *ray)
{
	if (ray->side_dist.x < ray->side_dist.y)
	{
		ray->side_dist.x += ray->delta_dist.x;
		ray->map_x += ray->step_x;
		ray->side = EAST_WEST;
	}
	else
	{
		ray->side_dist.y += ray->delta_dist.y;
		ray->map_y += ray->step_y;
		ray->side = NORTH_SOUTH;
	}
}

int	safe_divide(int numerator, double denominator)
{
	if (denominator < 1e-5)
		denominator = 0.001;
	return ((int)(numerator / denominator));
}
