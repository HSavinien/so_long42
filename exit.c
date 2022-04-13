/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:59:17 by tmongell          #+#    #+#             */
/*   Updated: 2022/04/12 17:59:20 by tmongell         ###   ########.fr       */
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
//placeholder
{
	(void) mlx;
	ft_printf("you loose!\n");
	exit(0);
}

int	winning(t_mlx *mlx)
//placeholder
{
	(void) mlx;
	ft_printf("you win!!!\n");
	exit(0);
}
