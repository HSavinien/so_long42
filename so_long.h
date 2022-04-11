/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 20:12:05 by tmongell          #+#    #+#             */
/*   Updated: 2022/04/11 22:39:10 by tmongell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//includes    ------------------------------------------------------    includes

# include "library/libft/libft.h"
# include "library/printf/libftprintf.h"
# include "library/get_next_line/get_next_line.h"
# include <mlx.h>
# include <fcntl.h>
# include <stdlib.h>
#include <sys/errno.h>
# include <stdio.h>//===========================================================debug


//macros    ----------------------------------------------------------    macros

# define TILE_SIZE 

//struct	----------------------------------------------------------    struct

typedef struct s_sprites {
	void	*player;
	void	*collect;
	void	*exit;
	void	*enemy;
	void	*wall;
	void	*ground;
	int		s_tiles_x;
	int		s_tiles_y;
}	t_sprites;

typedef struct s_mlx {
	void		*serv;
	void		*win;
	t_sprites	*sprites;
	int			size_x;
	int			size_y;
	int			nb_moves;
}	t_mlx;

typedef struct s_map {
	int		nb_tiles_x;
	int		nb_tiles_y;
	int		nb_colectible;
	int		nb_exit;
	int		nb_enemy;
	int		nb_player;
	char	**grid;
}	t_map;

//parsing    --------------------------------------------------------    parsing

t_map	*parsing(char *map_name);
int		check_limit_line(char *line);
char	*checkline(char *line, t_map *map);
void	fill_map(int map_fd, t_map *map);
void	check_object(t_map *map);

int		count_line(char *file);
void	check_map_name(char *name);
t_map	*map_init(void);

//display    --------------------------------------------------------    display

void	put_tile(t_mlx, char tile, int x, int y);
void	print_map(t_mlx *mlx, t_map *map);
t_sprites	*load_sprites(t_mlx *mlx);
t_mlx	*init_window(t_map *map);
void	manage_window(t_map *map);


//error    ------------------------------------------------------------    error
void	exit_msg(char	*msg);
void	free_map_exit(char	**map, char*msg);
int	close_window(void);

//failsafe    ------------------------------------------------------    failsafe

char	*fs_get_next_line(int fd);

//debug    ------------------------------------------------------------    debug
void	display_map(t_map *map);
void	display_map_color(t_map *map);
char	*get_next_line(int fd);
#endif
