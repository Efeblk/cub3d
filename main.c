/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibalik <ibalik@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:58:04 by ibalik            #+#    #+#             */
/*   Updated: 2023/12/14 16:26:08 by ibalik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        parse_arg(argv[1]);
    }
    else if (argc > 2)
    {
        printf("Error\nToo many arguments\n");
    }
    else
    {
        printf("Error\nNo arguments\n");
    }
    return 0;
}
