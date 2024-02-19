/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibalik <ibalik@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 20:54:30 by ibalik            #+#    #+#             */
/*   Updated: 2024/02/19 20:54:32 by ibalik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//ALTTAKİNİ SİLMEYİ UNUTMA
void	print_char_array(char **array)
{
	int	i;

	i = 0;
	printf("print_char_array:\n");
	while (array[i])
	{
		printf("%s\n", array[i]);
		++i;
	}
	printf("print_char_array end\n");
}

void	free_char_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		++i;
	}
	free(array);
}
