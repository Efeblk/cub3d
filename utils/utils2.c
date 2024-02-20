/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibalik <ibalik@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:10:30 by ibalik            #+#    #+#             */
/*   Updated: 2024/02/20 15:12:36 by ibalik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 == *s2 && *s1)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int	ft_isalnum(int c)
{
	return (ft_isdigit(c) || ft_isalpha(c));
}

int	file_exists(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		return (0);
	}
	else
	{
		close(fd);
		return (1);
	}
}

int	last_spaces_tonull(char *line)
{
	int	i;

	i = ft_strlen(line) - 1;
	while (line[i] != '\0' && (line[i] == ' ' || line[i] == '\t'))
	{
		line[i] = '\0';
		i--;
	}
	return (i);
}

void	exitor(int error)
{
	system("leaks cub3d");
	exit(error);
}
