/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibalik <ibalik@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 20:56:22 by ibalik            #+#    #+#             */
/*   Updated: 2024/02/20 17:31:54 by ibalik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_textured_line(t_game *game, t_ray *ray, int x, int line_height)
{
	int				line_start;
	int				line_end;
	unsigned int	pixel_color;
	int				y;
	int				tex_y;

	line_start = (WINDOW_HEIGHT - line_height) / 2;
	line_end = (WINDOW_HEIGHT + line_height) / 2;
	if (line_start < 0)
		line_start = 0;
	if (line_end > WINDOW_HEIGHT)
		line_end = WINDOW_HEIGHT;
	y = line_start;
	while (++y < line_end)
	{
		tex_y = get_tex_y(y, ray, line_height);
		pixel_color = get_pixel_color(tex_y, ray);
		my_mlx_pixel_put(game->img, x, y, pixel_color);
	}
}

unsigned int	get_pixel_color(int tex_y, t_ray *ray)
{
	unsigned int	pixel_color;
	int				texture_byte_size;
	int				texture_offset;

	texture_byte_size = ray->texture->bits_per_pixel / 8;
	texture_offset = (tex_y * ray->texture->line_length);
	texture_offset += ray->tex_x * texture_byte_size;
	pixel_color = *(unsigned int *)(ray->texture->addr + texture_offset);
	return (pixel_color);
}

int	get_tex_y(int y, t_ray *ray, int line_height)
{
	double	tmp;
	double	half_screen_height;
	double	half_line_height;
	double	texture_height;
	int		tex_y;

	(void)ray;
	half_screen_height = WINDOW_HEIGHT / 2.0;
	half_line_height = line_height / 2.0;
	texture_height = (double)(64);
	tmp = (y - half_screen_height + half_line_height);
	tmp *= texture_height / line_height;
	tex_y = (int)tmp;
	return (tex_y);
}

void	draw_floor_ceiling(t_game *game, int x, int lineHeight)
{
	int	start;
	int	end;
	int	y;

	start = (WINDOW_HEIGHT - lineHeight) / 2;
	end = (WINDOW_HEIGHT + lineHeight) / 2;
	if (start < 0)
		start = 0;
	if (end > WINDOW_HEIGHT)
		end = WINDOW_HEIGHT;
	y = -1;
	while (++y < start)
		my_mlx_pixel_put(game->img, x, y, game->map->ceiling_color);
	y = end - 1;
	while (++y < WINDOW_HEIGHT)
		my_mlx_pixel_put(game->img, x, y, game->map->floor_color);
}
