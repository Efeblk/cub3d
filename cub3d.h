/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibalik <ibalik@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:58:01 by ibalik            #+#    #+#             */
/*   Updated: 2023/12/14 17:47:30 by ibalik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 1
#define INT_MAX 2147483647
#define INT_MIN -2147483648
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
    char player_dir;
    int player_x;
    int player_y;
    int all_infos_set;
    int line_to_skip;
}               t_map;

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
///////////////////////////
void map_init(t_map *map);

void parse_arg(char *arg);
void checkers(char *arg);
void cub_check(char *arg);

void parse_map(char *arg, t_map *map);
void parse_line(char *line, t_map *map);
void check_line(char *line, t_map *map);
void route_valid(char *line, t_map *map);

void check_xpm(char *line);
void check_rgb(char *line, char c,t_map *map);
void w_xpm_to_map(char c1, char c2, char *line, t_map *map);

void w_rgb_to_map(int *rgb, char c, t_map *map);
void check_rgb_value(int value);
void count_coma(char *line);

int check_infos_set(t_map *map);

void parse_map_line(char *line, t_map *map);
void check_map_line(char *line, t_map *map);
int check_player_dir(char dir, int i, t_map *map);
void check_horizontal_walls(char *line, int i);

void read_write_map(char *mapname, t_map *map);
void newline_to_null(char *line);
char *fill_with_spaces(int line_width);


//GET NEXT LINE
char	*get_next_line(int fd);
char	*ft_strchr(const char *string, int searchedChar );
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t elementCount, size_t elementSize);

#endif