/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibalik <ibalik@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:58:01 by ibalik            #+#    #+#             */
/*   Updated: 2024/02/06 18:16:18 by ibalik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <math.h>

#include "mlx/mlx.h"

#define BUFFER_SIZE 1
#define INT_MAX 2147483647
#define INT_MIN -2147483648
#define BLOCK_SIZE 64
#define MINI_MAP_SCALE 1 //Max 1, min 64
#define ESC 17
#define KEY_PRESS 2
#define KEY_RELEASE 3
#define W 13
#define S 1
#define A 0
#define D 2
#define LEFT_ARROW 123
#define RIGHT_ARROW 124

#define MOVE_SPEED 2
typedef struct s_game
{
    struct s_map *map;
    struct s_assets *assets;
    void *mlx;
    void *window;
    int window_width;
    int window_height;
}               t_game;

typedef struct s_map
{
    char **map;
    int map_width;
    int map_height;
    char *ea;
    char *so;
    char *we;
    char *no;
    int ceiling_color;
    int floor_color;
    struct s_player *player;
    struct s_helpers *helpers;
}               t_map;

typedef struct s_player
{
    double posX;
    double posY;
    double dirX;
    double dirY;
    double planeX;
    double planeY;
    char dir;
    struct s_vector3 *look_dir_3d;
}               t_player;

typedef struct s_helpers
{
    int all_infos_set;
    int line_to_skip;
    char *free_line;
}           t_helpers;

typedef struct s_assets
{
    void *n;
    void *s;
    void *w;
    void *e;
}               t_assets;

typedef struct s_vector3
{
    double x;
    double y;
    double z;
}               t_vector3;
//UTILS
int file_exists(char *file);
int last_spaces_tonull(char *line);

int	ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
int	ft_isalnum(int c);
int	ft_strcmp(const char *s1, const char *s2);
char	*ft_strncpy(char *dest, const char *src, size_t n);
char	*ft_strcpy(char *s1, char *s2);
int	ft_isalpha(int c);
int	ft_isdigit(int c);
char	*ft_strdup(const char *s1);
int	ft_atoi(const char *str);

void print_char_array(char **array); //BUNU SİL!!!!
void free_char_array(char **array);

float convert_to_radian(float angle);
float convert_to_degree(float radian);
///////////////////////////

//main.c
void map_init(t_map *map, t_helpers *helpers, t_player *player);

//parse_arg.c
void parse_arg(char *arg);
void cub_check(char *arg);

//parse_map.c
void parse_map(char *arg, t_map *map);
void parse_line(char *line);
void route_valid(char *line, t_map *map);

//check_line.c
void check_line(char *line, t_map *map, int line_count, int *map_start_flag);
void freeline_and_exit(char *line);

//parse_map_xpm.c
void check_xpm(char *line, t_map *map);
void w_xpm_to_map(char c1, char c2, char *line, t_map *map);

//parse_map_rgb.c
void check_rgb(char *line, char c,t_map *map);
void w_rgb_to_map(int *rgb, char c, t_map *map);
void check_rgb_value(int value, t_map *map, char *tmp_value, int *rgb);
void count_coma(char *line, t_map *map);

//check_infos.c
int check_infos_set(t_map *map);

//parse_map_line.c
void parse_map_line(char *line, t_map *map);
void check_map_line(char *line, t_map *map);
int check_player_dir(char dir, int i, t_map *map);
void check_horizontal_walls(char *line, int i);

//read_write_map.c
void read_write_map(char *mapname, t_map *map);
void newline_to_null(char *line);
char *fill_with_spaces(int line_width);
void skip_lines(int line_to_skip, int fd);
void fill_map(int fd, t_map *map);
void dir_to_zero(char *map_line);
void check_more_maps(char *line, t_map *map);

//check_vertical_walls.c
void check_vertical_walls(t_map *map);

//start_game.c
void start_game(t_game *game);

//init_game.c
void init_game(t_game *game);
void init_mlx_dep(t_game *game);
void init_player(t_player *player);
void init_window(t_game *game);
void load_assets(void *mlx, t_game *game);

//mlx_window.c
void open_window(t_game *game);

//init_hooks.c
void init_hooks(t_game *game);
int key_pressed(int keycode, t_game *game);
int close_window(void);

//draw_map.c
void draw_minimap(t_game *game, void *mlx, void *window);

//draw_player_2d.c
void draw_player_2d(void *mlx, void *window, char **map, t_game *game);

//draw_player_3d.c
void draw_player_3d(t_game *game);

///////////////////
//GET NEXT LINE
char	*get_next_line(int fd);
char	*ft_strchr(const char *string, int searchedChar );
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t elementCount, size_t elementSize);

#endif