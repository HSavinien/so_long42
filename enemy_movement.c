/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_movement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 16:43:09 by tmongell          #+#    #+#             */
/*   Updated: 2022/04/15 20:14:31 by tmongell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_enemy(t_mlx *mlx, t_map *map)
{
	int	y;
	int	x;
	int i;

	y = 0;
	while(map->grid[y])
	{
		x = 0;
		while(map->grid[y][x])
		{
			i = 10;
			while(map->grid[y][x] == 'K' && i--)
				enemy_move_from(map, x, y, mlx);
			x ++;
		}
		y ++;
	}
}

void	enemy_move_from(t_map *map, int x, int y, t_mlx *mlx)
{
	int	seed;
	int	dst_x;
	int dst_y;

	dst_x = x;
	dst_y = y;
	seed = (random() % 4) + 1;
	if (seed == 1)
		dst_y --;
	else if (seed == 2)
		dst_x --;
	else if (seed == 3)
		dst_y ++;
	else if (seed == 4)
		dst_x ++;
	if (map->grid[dst_y][dst_x] == 'P')
		game_over(mlx);
	if (map->grid[dst_y][dst_x] == '0')
	{
		map->grid[dst_y][dst_x] = 'K';
		map->grid[y][x] = '0';
	}
}
