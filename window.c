/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 14:37:34 by tmongell          #+#    #+#             */
/*   Updated: 2022/04/16 18:57:13 by tmongell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#define WIN_NAME "name of the window"
#define PLAYER "sprites/player.xpm"
#define ITEM "sprites/item.xpm"
#define ITEM1 "sprites/item1.xpm"
#define EXIT "sprites/exit.xpm"
#define ENEMY "sprites/enemy.xpm"
#define WALL "sprites/wall.xpm"
#define FLOOR "sprites/ground.xpm"
#define PERIOD 10

void	put_tile(t_mlx *mlx, int nb_call, int x, int y)
{
	char	tile;

	tile = mlx->map->grid[y / mlx->sprite->s_tile_y][x / mlx->sprite->s_tile_x];
	mlx_put_image_to_window(mlx->serv, mlx->win, mlx->sprite->ground, x, y);
	if (tile == 'P')
		mlx_put_image_to_window(mlx->serv, mlx->win, mlx->sprite->player, x, y);
	else if (tile == 'C' && nb_call <= PERIOD / 2)
		mlx_put_image_to_window(mlx->serv, mlx->win, mlx->sprite->item, x, y);
	else if (tile == 'C' && nb_call >= PERIOD / 2)
		mlx_put_image_to_window(mlx->serv, mlx->win, mlx->sprite->item1, x, y);
	else if (tile == 'E')
		mlx_put_image_to_window(mlx->serv, mlx->win, mlx->sprite->exit, x, y);
	else if (tile == 'K')
		mlx_put_image_to_window(mlx->serv, mlx->win, mlx->sprite->enemy, x, y);
	else if (tile == '1')
		mlx_put_image_to_window(mlx->serv, mlx->win, mlx->sprite->wall, x, y);
}

int	print_map(t_mlx *mlx)
{
	int			i;
	int			j;
	static int	nb_call;

	mlx_clear_window(mlx->serv, mlx->win);
	i = 0;
	while (mlx->map->grid[i])
	{
		j = 0;
		while (mlx->map->grid[i][j])
		{
			put_tile(mlx, nb_call,
				j * mlx->sprite->s_tile_x, i * mlx->sprite->s_tile_y);
			j ++;
		}
		i ++;
	}
	show_nb_moves(mlx->nb_moves, mlx);
	nb_call ++;
	if (nb_call >= PERIOD)
		nb_call = 0;
	return (0);
}

t_sprites	*load_sprites(t_mlx *mlx)
{
	t_sprites	*sprite;
	int			size_x;
	int			size_y;

	sprite = malloc(sizeof (t_sprites));
	sprite->player = mlx_xpm_file_to_image(mlx->serv, PLAYER,
			&sprite->s_tile_x, &sprite->s_tile_y);
	sprite->item = mlx_xpm_file_to_image(mlx->serv, ITEM, &size_x, &size_y);
	sprite->item1 = mlx_xpm_file_to_image(mlx->serv, ITEM1, &size_x, &size_y);
	sprite->exit = mlx_xpm_file_to_image(mlx->serv, EXIT, &size_x, &size_y);
	sprite->enemy = mlx_xpm_file_to_image(mlx->serv, ENEMY, &size_x, &size_y);
	sprite->wall = mlx_xpm_file_to_image(mlx->serv, WALL, &size_x, &size_y);
	sprite->ground = mlx_xpm_file_to_image(mlx->serv, FLOOR, &size_x, &size_y);
	return (sprite);
}

t_mlx	*init_window(t_map *map)
{
	t_mlx	*mlx;

	mlx = malloc(sizeof (t_mlx));
	mlx->serv = mlx_init();
	mlx->sprite = load_sprites(mlx);
	mlx->size_x = (mlx->sprite->s_tile_x * map->nb_tiles_x);
	mlx->size_y = (mlx->sprite->s_tile_y * map->nb_tiles_y);
	mlx->win = mlx_new_window(mlx->serv, mlx->size_x, mlx->size_y, WIN_NAME);
	mlx->map = map;
	mlx->nb_moves = 0;
	return (mlx);
}
