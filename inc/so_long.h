/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nradin <nradin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:59:03 by nradin            #+#    #+#             */
/*   Updated: 2023/03/01 17:03:43 by nradin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "printf/ft_printf.h"
# include <limits.h>
# include <fcntl.h>
# include "../mlx/mlx.h"

# define WALL				'1'
# define FLOOR				'0'
# define COLLECTIBLE		'C'
# define PLAYER				'P'
# define MAP_EXIT			'E'

# define WALL_PATH "sprites/wall.xpm"
# define FLOOR_PATH "sprites/floor.xpm"
# define COLLECTIBLE_PATH "sprites/gryvnya.xpm"
# define PLAYER_PATH "sprites/devil_down.xpm"
# define PLAYER_WIN_PATH "sprites/devil_win.xpm"
# define MAP_EXIT_PATH "sprites/exit_0.xpm"

# define KEY_W				13
# define KEY_A				0
# define KEY_S				1
# define KEY_D				2
# define KEY_ESC			53

typedef struct s_comp
{
	int	exit;
	int	player;
	int	collect;
}	t_comp;

typedef struct s_image
{
	void	*xpm_ptr;
	int		x;
	int		y;
}	t_image;

typedef struct s_coords
{
	int		x;
	int		y;
}	t_coords;

typedef struct s_game
{
	int			win_condition;
	int			movements;
	void		*mlx;
	void		*win;
	char		**map;
	t_coords	player_pos;
	t_image		player;
	t_image		player_win;
	t_image		wall;
	t_image		floor;
	t_image		collectible;
	t_image		map_exit;
	t_image		win_screen;
}	t_game;

typedef struct s_point
{
	int		x;
	int		y;
	int		dist;
}	t_point;

size_t	ft_strstr_len(char **str);
void	init_comp(t_comp *comps);
void	throw_error(t_comp *comps);
char	**ft_strstrdup(char **str, int size);
void	ft_strstr_free(char **str);

int		count_lines(int fd);
char	**read_map(char	*map);
int		check_rectangular(char **map);
int		check_walls(char **map);
int		components_ifs(char c, t_comp *comps);
t_comp	*check_components(char **map);
void	count_components(char **map, t_comp *comps);
int		compare_components(t_comp *comps1, t_comp *comps2);
void	check_path(char **map, t_comp *comps, int x, int y);
int		find_path(t_game *game, t_comp *comps);
void	check_map(t_game *game);

int		create_trgb(int t, int r, int g, int b);
int		get_t(int trgb);
int		get_r(int trgb);
int		get_g(int trgb);
int		get_b(int trgb);

void	game_init(t_game *game);
int		game_start(t_game *game);
int		init_images(t_game	*game);
void	render_image(t_game *game, t_image sprite, int x, int y);
void	render_map(t_game *game, char **map);

int		key_hook(int keycode, t_game *game);

void	ft_error_msg(const char *msg, t_game *game);
int		close_game(t_game *game);
void	game_win(t_game *game);

#endif
