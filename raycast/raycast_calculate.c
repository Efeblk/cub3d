/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_calculate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibalik <ibalik@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 20:56:17 by ibalik            #+#    #+#             */
/*   Updated: 2024/02/20 17:31:57 by ibalik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	calculate_step_and_dist(t_game *game, t_ray *ray)
{
	if (ray->ray_dir.x < 0)
	{
		ray->step_x = -1;
		ray->side_dist.x
			= (game->map->player->pos_x - ray->map_x) * ray->delta_dist.x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist.x = (ray->map_x + 1.0 - game->map->player->pos_x);
		ray->side_dist.x *= ray->delta_dist.x;
	}
	if (ray->ray_dir.y < 0)
	{
		ray->step_y = -1;
		ray->side_dist.y
			= (game->map->player->pos_y - ray->map_y) * ray->delta_dist.y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist.y = (ray->map_y + 1.0 - game->map->player->pos_y);
		ray->side_dist.y *= ray->delta_dist.y;
	}
}

void	calculate_perpetual(t_game *game, t_ray *ray)
{
	while (ray->hit == 0)
	{
		ray_step(ray);
		if (is_hit(ray, game))
			ray->hit = 1;
	}
	if (ray->side == EAST_WEST)
		ray->perp_wall_dist = ray->side_dist.x - ray->delta_dist.x;
	else
		ray->perp_wall_dist = ray->side_dist.y - ray->delta_dist.y;
}

void	determine_texture(t_game *game, t_ray *ray)
{
	if (ray->side == EAST_WEST)
	{
		if (ray->ray_dir.x > 0)
			ray->texture = (game->assets->e);
		else
			ray->texture = (game->assets->w);
	}
	else
	{
		if (ray->ray_dir.y > 0)
			ray->texture = (game->assets->s);
		else
			ray->texture = (game->assets->n);
	}
}

void	calculate_texture_x(t_game *game, t_ray *ray)
{
	double	wallx;

	if (ray->side == EAST_WEST)
		wallx = game->map->player->pos_y + ray->perp_wall_dist * ray->ray_dir.y;
	else
		wallx = game->map->player->pos_x + ray->perp_wall_dist * ray->ray_dir.x;
	wallx -= floor((wallx));
	ray->tex_x = (int)(wallx * (double)(64));
	fix_mirror(ray);
}

void	fix_mirror(t_ray *ray)
{
	if ((ray->side == 0 && ray->ray_dir.x < 0)
		|| (ray->side == 1 && ray->ray_dir.y > 0))
		ray->tex_x = 64 - ray->tex_x - 1;
}
