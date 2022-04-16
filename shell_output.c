/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 18:30:59 by tmongell          #+#    #+#             */
/*   Updated: 2022/04/16 19:49:11 by tmongell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "so_long.h"
#include "library/formating.h"

void	debug_display_map(t_map	*map)
{
	int	i;

	i = 0;
	while (map->grid[i])
	{
		ft_printf("%s", map->grid[i]);
		i ++;
	}
	ft_printf("map dimensions are %d * %d\n", map->nb_tiles_x, map->nb_tiles_y);
	ft_printf("found :\n\t- %d items;\n\t- %d exit;\n\t- %d players;\n\t- "
		"%d enemy\n", map->nb_colectible, map->nb_exit, map->nb_player,
		map->nb_enemy);
}

void	print_map_shell(t_map	*map)
{
	int	i;
	int	j;

	i = 0;
	ft_printf("\n");
	while (map->grid[i])
	{
		j = 0;
		while (map->grid[i][j])
		{
			print_tile_shell(i, j, map);
			j ++;
		}
		i ++;
	}
	printf("\033[0m\n");
}

void	print_tile_shell(int i, int j, t_map *map)
{
	if (map->grid[i][j] == '1')
		printf("\033[47m  ");
	else if (map->grid[i][j] == '0')
		printf("\033[40m  ");
	else if (map->grid[i][j] == 'P')
		printf("\033[44m  ");
	else if (map->grid[i][j] == 'C')
		printf("\033[42m  ");
	else if (map->grid[i][j] == 'E')
		printf("\033[43m  ");
	else if (map->grid[i][j] == 'K')
		printf("\033[41m  ");
	else if (map->grid[i][j] == '\n')
		printf("\033[0m\n");
}
