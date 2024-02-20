/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibalik <ibalik@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:58:01 by ibalik            #+#    #+#             */
/*   Updated: 2024/02/20 14:55:46 by ibalik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "mlx/mlx.h"

# define BUFFER_SIZE 1
# define INT_MAX 2147483647
# define INT_MIN -2147483648
# define BLOCK_SIZE 64
# define MINI_MAP_SCALE 1 //Max 1, min 64
# define ESC 53
# define KEY_PRESS 2
# define KEY_RELEASE 3
# define W 13
# define S 1
# define A 0
# define D 2
# define LEFT_ARROW 123
# define RIGHT_ARROW 124
# define MOVE_SPEED 0.0000005 //çok hızlıyız bune aqqqqq
# define ROT_SPEED 0.03
# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 600
# define FOV 1.047198 //M_PI / 3
# define ANGLE_STEP 0.001309  //FOV / WIDTH
# define OFFSET 0.6
# define COLLIDE_MULTIPLIER 1.5

typedef struct s_game
{
	struct s_map		*map;
	struct s_assets		*assets;
	struct s_img_data	*img;
	void				*mlx;
	void				*window;
	int					window_width;
	int					window_height;
	int					key;
	int					block_size_2d;
}	t_game;

typedef struct s_map
{
	char				**map;
	int					map_width;
	int					map_height;
	char				*ea;
	char				*so;
	char				*we;
	char				*no;
	int					ceiling_color;
	int					floor_color;
	struct s_player		*player;
	struct s_helpers	*helpers;
}	t_map;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	dir_radian;
	char	dir;
}	t_player;

typedef struct s_assets
{
	struct s_img_data	*n;
	struct s_img_data	*s;
	struct s_img_data	*w;
	struct s_img_data	*e;
}	t_assets;

typedef struct s_img_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}				t_img_data;

typedef struct s_point
{
	double			x;
	double			y;
}					t_point;

typedef struct s_ray
{
	t_point		ray_dir;
	t_point		side_dist;
	t_point		delta_dist;

	int			map_x;
	int			map_y;

	double		perp_wall_dist;

	int			step_x;
	int			step_y;

	int			side;
	int			hit;

	t_img_data	*texture;
	int			tex_x;
}			t_ray;

typedef enum s_side
{
	EAST_WEST,
	NORTH_SOUTH
}	t_side;

typedef struct s_helpers
{
	int		all_infos_set;
	int		line_to_skip;
	char	*free_line;
}	t_helpers;

typedef struct s_checkline_helper
{
	int		*map_start_flag;
	int		line_count;
	t_map	*map;
	char	*line;
	int		i;
}	t_checkline_helper;

typedef struct s_checkrgb_helper
{
	int		i;
	char	*tmp_value;
	int		tmp_i;
	int		*rgb;
	int		rgb_i;
}	t_checkrgb_helper;

typedef struct s_circle_helper
{
	int		x;
	int		y;
	int		err;
	int		color;
}	t_circle_helper;

//UTILS
int				file_exists(char *file);
int				last_spaces_tonull(char *line);
void			exitor(int error);

int				ft_strncmp(const char *s1, const char *s2, size_t n);
size_t			ft_strlen(const char *s);
char			*ft_strjoin(char const *s1, char const *s2);
int				ft_isalnum(int c);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strncpy(char *dest, const char *src, size_t n);
char			*ft_strcpy(char *s1, char *s2);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
char			*ft_strdup(const char *s1);
int				ft_atoi(const char *str);

void			print_char_array(char **array); //BUNU SİL!!!!
void			free_char_array(char **array);

//free_game.c
void			free_game(t_game *game);
void			free_map(t_map *map);
void			free_img_data(t_img_data *img);
void			free_assets(t_assets *assets);

///////////////////////////
//main.c
void			map_init(t_map *map, t_helpers *helpers, t_player *player);

//parse_arg.c
void			parse_arg(char *arg);
void			cub_check(char *arg);

//parse_map.c
void			parse_map(char *arg, t_map *map);
void			parse_line(char *line);
void			route_valid(char *line, t_map *map);

//check_line.c
void			check_line(char *line, t_map *map, int line_count,
					int *map_start_flag);
void			check_line2(t_checkline_helper *helper);
void			freeline_and_exit(char *line);

//parse_map_xpm.c
void			check_xpm(char *line, t_map *map);
void			w_xpm_to_map(char c1, char c2, char *line, t_map *map);
void			free_and_exit_xpm(t_map *map, int error);

//parse_map_rgb.c
void			check_rgb(char *line, char c, t_map *map);
void			load_rgb_helper(t_checkrgb_helper *helper);
void			free_rgb_tmp(int *rgb, char *tmp_value, t_map *map);

//parse_map_rgb2.c
void			check_rgb_value(int value, t_map *map,
					char *tmp_value, int *rgb);
void			count_coma(char *line, t_map *map);

//parse_map_rgb3.c
void			w_rgb_to_map(int *rgb, char c, t_map *map);
void			free_rgb(int *rgb, t_map *map, int f_or_c);

//check_infos.c
int				check_infos_set(t_map *map);

//parse_map_line.c
void			parse_map_line(char *line, t_map *map);
void			check_map_line(char *line, t_map *map);
int				check_player_dir(char dir, int i, t_map *map);
void			check_horizontal_walls(char *line, int i);

//read_write_map.c
void			read_write_map(char *mapname, t_map *map);
void			newline_to_null(char *line);
char			*fill_with_spaces(int line_width);
void			skip_lines(int line_to_skip, int fd);
void			fill_map(int fd, t_map *map);
void			dir_to_zero(char *map_line);
void			check_more_maps(char *line, t_map *map);

//check_vertical_walls.c
void			check_vertical_walls(t_map *map);
void			to_original_map(t_map *map);

//start_game.c
void			start_game(t_game *game);

//init_game.c
void			init_game(t_game *game);
void			init_player(t_player *player);
void			init_window(t_game *game);
void			set_dir(t_player *player);

//load_assets.c
void			load_assets(void			*mlx, t_game *game);
void			init_assets(t_assets *assets);
void			load_images(void			*mlx, t_game *game);
void			load_images_addr(t_game *game);

//mlx_window.c
void			open_window(t_game *game);

//init_hooks.c
void			init_hooks(t_game *game);
int				close_window(t_game *game);

//draw_minimap.c
void			draw_minimap(t_game *game);
void			draw_wall_block(t_game *game, int x, int y, t_img_data *img);
void			draw_empty_block(t_game *game, int x, int y);

//draw_plater.c
void			draw_player(t_game *game);
void			draw_circle(t_img_data *data, int center_x,
					int center_y, int color);
void			circle(t_circle_helper *helper,
					t_img_data *data, int c_x, int c_y);

//key_press.c
int				ft_press(int key, t_game *game);
int				ft_release(int key, t_game *game);

//raycast.c
void			raycast(t_game *game);
void			ray_step(t_ray *ray);
int				safe_divide(int numerator, double denominator);

//raycast_calculate.c
void			calculate_perpetual(t_game *game, t_ray *ray);
void			calculate_step_and_dist(t_game *game, t_ray *ray);
void			determine_texture(t_game *game, t_ray *ray);
void			calculate_texture_x(t_game *game, t_ray *ray);
void			fix_mirror(t_ray *ray);

//raycast_draw.c
void			draw_textured_line(t_game *game, t_ray *ray, int x,
					int line_height);
unsigned int	get_pixel_color(int tex_y, t_ray *ray);
int				get_tex_y(int y, t_ray *ray, int line_height);
void			draw_floor_ceiling(t_game *game, int x, int lineHeight);

//raycast_util.c
void			init_ray(t_game *game, t_ray *ray, double angle);
int				is_hit(t_ray *ray, t_game *game);
int				is_boundary_violated(t_ray *ray, int map_size);
void			my_mlx_pixel_put(t_img_data *data, int x, int y, int color);

//movement.c
void			ft_move(t_player *player, int dir, t_game *game);
void			ft_move2(t_player *player, int dir, t_game *game);
int				is_collide(double new_x, double new_y, char **map);
void			ft_turn(t_player *player, char dir);

//render.c
int				render(t_game *game);
void			routine(t_game *game);

///////////////////
//GET NEXT LINE
char			*get_next_line(int fd);
char			*ft_strchr(const char *string, int searchedChar);
void			ft_bzero(void			*s, size_t n);
void			*ft_calloc(size_t elementCount, size_t elementSize);

#endif