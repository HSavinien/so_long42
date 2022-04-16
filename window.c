/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 14:37:34 by tmongell          #+#    #+#             */
/*   Updated: 2022/04/16 18:01:58 by tmongell         ###   ########.fr       */
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

void	put_tile(t_mlx mlx, char tile, int nb_call, int x, int y)
{
	mlx_put_image_to_window(mlx.serv, mlx.win, mlx.sprites->ground, x, y);
	if (tile == 'P')
		mlx_put_image_to_window(mlx.serv, mlx.win, mlx.sprites->player, x, y);
	else if (tile == 'C' && nb_call < PERIOD/2)
		mlx_put_image_to_window(mlx.serv, mlx.win, mlx.sprites->item, x, y);
	else if (tile == 'C' && nb_call >= PERIOD/2)
		mlx_put_image_to_window(mlx.serv, mlx.win, mlx.sprites->item1, x, y);
	else if (tile == 'E')
		mlx_put_image_to_window(mlx.serv, mlx.win, mlx.sprites->exit, x, y);
	else if (tile == 'K')
		mlx_put_image_to_window(mlx.serv, mlx.win, mlx.sprites->enemy, x, y);
	else if (tile == '1')
		mlx_put_image_to_window(mlx.serv, mlx.win, mlx.sprites->wall, x, y);
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
			put_tile(*mlx, mlx->map->grid[i][j], nb_call,
				j * mlx->sprites->s_tiles_x, i * mlx->sprites->s_tiles_y);
			j ++;
		}
		i ++;
	}
	show_nb_moves(mlx->nb_moves, mlx);
	nb_call  ++;
	if (nb_call >= PERIOD)
		nb_call = 0;
	return (0);
}

t_sprites	*load_sprites(t_mlx *mlx)
{
	t_sprites	*sprites;
	int			size_x;
	int			size_y;

	sprites = malloc(sizeof (t_sprites));
	sprites->player = mlx_xpm_file_to_image(mlx->serv, PLAYER,
			&sprites->s_tiles_x, &sprites->s_tiles_y);
	sprites->item = mlx_xpm_file_to_image(mlx->serv, ITEM, &size_x, &size_y);
	if (size_x != sprites->s_tiles_x || size_y != sprites->s_tiles_y)
		exit_msg("internal error : all sprites must be of the same size.");
	sprites->item1 = mlx_xpm_file_to_image(mlx->serv, ITEM1, &size_x, &size_y);
	if (size_x != sprites->s_tiles_x || size_y != sprites->s_tiles_y)
		exit_msg("internal error : all sprites must be of the same size.");
	sprites->exit = mlx_xpm_file_to_image(mlx->serv, EXIT, &size_x, &size_y);
	if (size_x != sprites->s_tiles_x || size_y != sprites->s_tiles_y)
		exit_msg("internal error : all sprites must be of the same size.");
	sprites->enemy = mlx_xpm_file_to_image(mlx->serv, ENEMY, &size_x, &size_y);
	if (size_x != sprites->s_tiles_x || size_y != sprites->s_tiles_y)
		exit_msg("internal error : all sprites must be of the same size.");
	sprites->wall = mlx_xpm_file_to_image(mlx->serv, WALL, &size_x, &size_y);
	if (size_x != sprites->s_tiles_x || size_y != sprites->s_tiles_y)
		exit_msg("internal error : all sprites must be of the same size.");
	sprites->ground = mlx_xpm_file_to_image(mlx->serv, FLOOR, &size_x, &size_y);
	if (size_x != sprites->s_tiles_x || size_y != sprites->s_tiles_y)
		exit_msg("internal error : all sprites must be of the same size.");
	return (sprites);
}

t_mlx	*init_window(t_map *map)
{
	t_mlx	*mlx;

	mlx = malloc(sizeof (t_mlx));
	mlx->serv = mlx_init();
	mlx->sprites = load_sprites(mlx);
	mlx->size_x = (mlx->sprites->s_tiles_x * map->nb_tiles_x);
	mlx->size_y = (mlx->sprites->s_tiles_y * map->nb_tiles_y);
	mlx->win = mlx_new_window(mlx->serv, mlx->size_x, mlx->size_y, WIN_NAME);
	mlx->map = map;
	mlx->nb_moves = 0;
	return (mlx);
}

/*

player_move : 
check destination tile :
	if destination till is wall, return
	if destination till is exit and not enough collectible picked, return
	if destination is exit, and all collectible picked, success_exit
	if destination tile is enemy, game_over
	if destination till is collectible, collect++,
	tell enemy to move
update map->grid, nb_move ++
re-print_map
print nb_move

move_all_enemy :
read all map->grid
if tile is 'K', call enemy_move
once grid is finished, return (map reprinting will be done by parent fct)
enemy_move :
pick a random dirrection
while destination isn't ground (and nb_check <= 4), check next direction.
update map->grid
exit (map update will be done by parent fct)
*/
