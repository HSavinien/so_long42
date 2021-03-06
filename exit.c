/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:59:17 by tmongell          #+#    #+#             */
/*   Updated: 2022/06/15 18:12:13 by tmongell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_msg(char	*msg)
{
	ft_printf("%s\n", msg);
	exit(1);
}

void	free_map_exit(char **map, char *msg)
{
	int	i;

	i = 0;
	while (map[i ++])
		free(map[i]);
	free(map);
	exit_msg(msg);
}

int	close_window(void)
{
	exit(0);
	return (0);
}

int	game_over(t_mlx *mlx)
{
	void	*img;
	int		img_x;
	int		img_y;
	int		pos_x;
	int		pos_y;

	img = mlx_xpm_file_to_image(mlx->serv, "sprites/lose.xpm", &img_x, &img_y);
	if (!img)
		exit_msg("you lose, but for some reason, game over screen isn't there");
	pos_x = (mlx->size_x / 2) - (img_x / 2);
	pos_y = (mlx->size_y / 2) - (img_y / 2);
	mlx_put_image_to_window(mlx->serv, mlx->win, img, pos_x, pos_y);
	ft_printf("you loose!\n");
	mlx_loop_hook(mlx->serv, NULL, mlx);
	mlx_key_hook(mlx->win, end_of_game, mlx);
	return (0);
}

int	winning(t_mlx *mlx)
{
	void	*img;
	int		img_x;
	int		img_y;
	int		pos_x;
	int		pos_y;

	img = mlx_xpm_file_to_image(mlx->serv, "sprites/win.xpm", &img_x, &img_y);
	if (!img)
		exit_msg("you won, but for some reason, victory screen is not there");
	pos_x = (mlx->size_x / 2) - (img_x / 2);
	pos_y = (mlx->size_y / 2) - (img_y / 2);
	mlx_put_image_to_window(mlx->serv, mlx->win, img, pos_x, pos_y);
	ft_printf("you win!\n");
	mlx_loop_hook(mlx->serv, NULL, mlx);
	mlx_key_hook(mlx->win, end_of_game, mlx);
	return (0);
}
