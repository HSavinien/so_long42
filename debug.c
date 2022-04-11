/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 18:30:59 by tmongell          #+#    #+#             */
/*   Updated: 2022/04/11 21:14:13 by tmongell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "so_long.h"
#include "library/formating.h"

void	display_map(t_map	*map)
{
	int	i;

	i = 0;
	while (map->grid[i])
	{
		printf("%s", map->grid[i]);
		i ++;
	}
	printf("map dimensions are %d * %d\n", map->nb_tiles_x, map->nb_tiles_y);
	printf("found :\n \t- %d collectibles;\n\t- %d exit;\n\t- %d players;\n\t- "
		"%d enemy\n", map->nb_colectible, map->nb_exit, map->nb_player,
		map->nb_enemy);
}

void	display_map_color(t_map	*map)
{
	int	i;
	int	j;

	i = 0;
	printf("\n ");
	while (map->grid[i])
	{
		j = 0;
		while (map->grid[i][j])
		{
			if (map->grid[i][j] == '1')
				printf("\033[47m");
			else if (map->grid[i][j] == '0')
				printf("\033[40m");
			else if (map->grid[i][j] == 'P')
				printf("\033[44m");
			else if (map->grid[i][j] == 'C')
				printf("\033[42m");
			else if (map->grid[i][j] == 'E')
				printf("\033[43m");
			else if (map->grid[i][j] == 'K')
				printf("\033[41m");
			else if (map->grid[i][j] == '\n')
				printf("\033[0m\n");
			printf(" ");
			j ++;
		}
		i ++;
	}
	printf("\033[0m\n");
}
