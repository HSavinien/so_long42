/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 20:12:05 by tmongell          #+#    #+#             */
/*   Updated: 2022/05/04 18:59:12 by tmongell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//includes    ------------------------------------------------------    includes

# include "library/libft/libft.h"
# include "library/printf/libftprintf.h"
# include "library/get_next_line/get_next_line.h"
# include "library/key_code.h"
# include <mlx.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/errno.h>

//macros    ----------------------------------------------------------    macros

# define TILE_SIZE 

//struct	----------------------------------------------------------    struct

typedef struct s_map {
	int		nb_tiles_x;
	int		nb_tiles_y;
	int		nb_colectible;
	int		nb_exit;
	int		nb_enemy;
	int		nb_player;
	char	**grid;
	int		p_posx;
	int		p_posy;
}	t_map;

typedef struct s_sprites {
	void	*player;
	void	*item;
	void	*item1;
	void	*exit;
	void	*enemy;
	void	*wall;
	void	*ground;
	int		s_tile_x;
	int		s_tile_y;
}	t_sprites;

typedef struct s_mlx {
	void		*serv;
	void		*win;
	t_sprites	*sprite;
	t_map		*map;
	int			size_x;
	int			size_y;
	int			nb_moves;
}	t_mlx;

//parsing    --------------------------------------------------------    parsing

t_map		*parsing(char *map_name);
int			check_limit_line(char *line);
char		*checkline(char *line, t_map *map);
void		fill_map(int map_fd, t_map *map);
void		check_object(t_map *map);

int			count_line(char *file);
void		check_map_name(char *name);
t_map		*map_init(void);
char		*handle_eol(char *line);

//display    --------------------------------------------------------    display

void		put_tile(t_mlx *mlx, int nb_call, int x, int y);
int			print_map(t_mlx *mlx);
t_sprites	*load_sprites(t_mlx *mlx);
t_mlx		*init_window(t_map *map);
int			keyboard_event(int key, t_mlx *mlx);
int			end_of_game(int key, t_mlx *mlx);

//player movement    ----------------------------------------    player movement

int			player_moveto(int dst_x, int dst_y, t_mlx *mlx, t_map *map);
int			find_player(t_map *map);
void		show_nb_moves(int nb_moves, t_mlx *mlx);

//enemy_movement    ------------------------------------------    enemy movement

void		move_enemy(t_map *map);
void		enemy_move_from(t_map *map, int x, int y);
void		clean_map(t_map *map);

//exit functions    ------------------------------------------    exit functions
void		exit_msg(char	*msg);
void		free_map_exit(char	**map, char*msg);
int			close_window(void);
int			game_over(t_mlx *mlx);
int			winning(t_mlx *mlx);

//shell output    ----------------------------------------------    shell output
void		debug_display_map(t_map *map);
void		print_map_shell(t_map *map);
void		print_tile_shell(int i, int j, t_map *map);
#endif
