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

#define BUFFER_SIZE 5
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
}               t_map;

int file_exists(char *file);

int	ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
int	ft_isalnum(int c);
int	ft_strcmp(const char *s1, const char *s2);
char	*ft_strncpy(char *dest, const char *src, size_t n);
char	*ft_strcpy(char *s1, char *s2);
int	ft_isalpha(int c);
int	ft_isdigit(int c);

void parse_arg(char *arg);
void checkers(char *arg);
void cub_check(char *arg);

void parse_map(char *arg);
void check_line(char *line);
void route_valid(char *line);

void check_xpm(char *line);
void check_rgb(char *line);

char	*get_next_line(int fd);
char	*ft_strchr(const char *string, int searchedChar );
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t elementCount, size_t elementSize);

#endif