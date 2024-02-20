/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibalik <ibalik@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:59:58 by ibalik            #+#    #+#             */
/*   Updated: 2024/02/20 17:32:11 by ibalik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	parse_arg(char *arg)
{
	int	fd;

	fd = open(arg, O_RDONLY);
	if (fd == -1)
	{
		printf("Error\nFile not found\n");
		exitor(0);
	}
	close(fd);
	cub_check(arg);
}

void	cub_check(char *arg)
{
	int	i;

	i = ft_strlen(arg) - 1;
	while (arg[i])
	{
		if (arg[i - 3] == '.')
		{
			if (arg[i - 2] == 'c' && arg[i - 1] == 'u'
				&& arg[i] == 'b' && arg[i + 1] == '\0')
				return ;
		}
		i--;
	}
	printf("Error\nFile extension is not .cub\n");
	exitor(0);
}
