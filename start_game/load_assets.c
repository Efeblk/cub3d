/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_assets.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibalik <ibalik@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 20:53:53 by ibalik            #+#    #+#             */
/*   Updated: 2024/02/20 17:31:41 by ibalik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_assets(t_assets *assets)
{
	assets->n = malloc(sizeof(t_img_data));
	assets->s = malloc(sizeof(t_img_data));
	assets->w = malloc(sizeof(t_img_data));
	assets->e = malloc(sizeof(t_img_data));
}

void	load_assets(void *mlx, t_game *game)
{
	init_assets(game->assets);
	load_images(mlx, game);
	load_images_addr(game);
}

void	load_images(void *mlx, t_game *game)
{
	int	block_size;

	block_size = BLOCK_SIZE;
	game->assets->n->img = mlx_xpm_file_to_image(mlx, game->map->no,
			&block_size, &block_size);
	game->assets->s->img = mlx_xpm_file_to_image(mlx, game->map->so,
			&block_size, &block_size);
	game->assets->w->img = mlx_xpm_file_to_image(mlx, game->map->we,
			&block_size, &block_size);
	game->assets->e->img = mlx_xpm_file_to_image(mlx, game->map->ea,
			&block_size, &block_size);
	if (game->assets->n->img == NULL
		|| game->assets->s->img == NULL
		|| game->assets->w->img == NULL
		|| game->assets->e->img == NULL)
	{
		printf("Error\nXPM File is not valid\n");
		exitor(0);
	}
}

void	load_images_addr(t_game *game)
{
	game->assets->n->addr = mlx_get_data_addr(game->assets->n->img,
			&game->assets->n->bits_per_pixel, &game->assets->n->line_length,
			&game->assets->n->endian);
	game->assets->s->addr = mlx_get_data_addr(game->assets->s->img,
			&game->assets->s->bits_per_pixel, &game->assets->s->line_length,
			&game->assets->s->endian);
	game->assets->w->addr = mlx_get_data_addr(game->assets->w->img,
			&game->assets->w->bits_per_pixel, &game->assets->w->line_length,
			&game->assets->w->endian);
	game->assets->e->addr = mlx_get_data_addr(game->assets->e->img,
			&game->assets->e->bits_per_pixel, &game->assets->e->line_length,
			&game->assets->e->endian);
}
