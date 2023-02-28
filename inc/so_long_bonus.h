/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nradin <nradin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:59:03 by nradin            #+#    #+#             */
/*   Updated: 2023/02/28 18:58:23 by nradin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "libft/libft.h"
# include "printf/ft_printf.h"
# include <limits.h>
# include <fcntl.h>
# include <sys/time.h>
# include <time.h>
# include <stdlib.h>
# include "../mlx/mlx.h"

# define WALL				'1'
# define FLOOR				'0'
# define COLLECTIBLE		'C'
# define PLAYER				'P'
# define MAP_EXIT			'E'
# define ENEMY_VERTICAL		'V'
# define ENEMY_HORIZONTAL	'H'

# define WALL_PATH "sprites/wall.xpm"
# define FLOOR_PATH "sprites/floor.xpm"
# define COLLECTIBLE_PATH "sprites/gryvnya.xpm"
# define PLAYER_UP_0_PATH "sprites/devil_up.xpm"
# define PLAYER_UP_1_PATH "sprites/devil_up_1.xpm"
# define PLAYER_UP_2_PATH "sprites/devil_up_2.xpm"
# define PLAYER_DOWN_0_PATH "sprites/devil_down.xpm"
# define PLAYER_DOWN_1_PATH "sprites/devil_down_1.xpm"
# define PLAYER_DOWN_2_PATH "sprites/devil_down_2.xpm"
# define PLAYER_LEFT_0_PATH "sprites/devil_left.xpm"
# define PLAYER_LEFT_1_PATH "sprites/devil_left_1.xpm"
# define PLAYER_LEFT_2_PATH "sprites/devil_left_2.xpm"
# define PLAYER_RIGHT_0_PATH "sprites/devil_right.xpm"
# define PLAYER_RIGHT_1_PATH "sprites/devil_right_1.xpm"
# define PLAYER_RIGHT_2_PATH "sprites/devil_right_2.xpm"
# define ENEMY_1_UP_0_PATH "sprites/cossack_1_up.xpm"
# define ENEMY_1_UP_1_PATH "sprites/cossack_1_up_1.xpm"
# define ENEMY_1_UP_2_PATH "sprites/cossack_1_up_2.xpm"
# define ENEMY_1_DOWN_0_PATH "sprites/cossack_1_down.xpm"
# define ENEMY_1_DOWN_1_PATH "sprites/cossack_1_down_1.xpm"
# define ENEMY_1_DOWN_2_PATH "sprites/cossack_1_down_2.xpm"
# define ENEMY_1_LEFT_0_PATH "sprites/cossack_1_left.xpm"
# define ENEMY_1_LEFT_1_PATH "sprites/cossack_1_left_1.xpm"
# define ENEMY_1_LEFT_2_PATH "sprites/cossack_1_left_2.xpm"
# define ENEMY_1_RIGHT_0_PATH "sprites/cossack_1_right.xpm"
# define ENEMY_1_RIGHT_1_PATH "sprites/cossack_1_right_1.xpm"
# define ENEMY_1_RIGHT_2_PATH "sprites/cossack_1_right_2.xpm"
# define ENEMY_2_UP_0_PATH "sprites/cossack_2_up.xpm"
# define ENEMY_2_UP_1_PATH "sprites/cossack_2_up_1.xpm"
# define ENEMY_2_UP_2_PATH "sprites/cossack_2_up_2.xpm"
# define ENEMY_2_DOWN_0_PATH "sprites/cossack_2_down.xpm"
# define ENEMY_2_DOWN_1_PATH "sprites/cossack_2_down_1.xpm"
# define ENEMY_2_DOWN_2_PATH "sprites/cossack_2_down_2.xpm"
# define ENEMY_2_LEFT_0_PATH "sprites/cossack_2_left.xpm"
# define ENEMY_2_LEFT_1_PATH "sprites/cossack_2_left_1.xpm"
# define ENEMY_2_LEFT_2_PATH "sprites/cossack_2_left_2.xpm"
# define ENEMY_2_RIGHT_0_PATH "sprites/cossack_2_right.xpm"
# define ENEMY_2_RIGHT_1_PATH "sprites/cossack_2_right_1.xpm"
# define ENEMY_2_RIGHT_2_PATH "sprites/cossack_2_right_2.xpm"
# define MAP_EXIT_0_PATH "sprites/exit_0.xpm"
# define MAP_EXIT_1_PATH "sprites/exit_1.xpm"
# define MAP_EXIT_2_PATH "sprites/exit_2.xpm"
# define MAP_EXIT_3_PATH "sprites/exit_3.xpm"
# define MAP_EXIT_4_PATH "sprites/exit_4.xpm"
# define SHADOW_PATH "sprites/shadow.xpm"

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
	int	enemy;
}	t_comp;

typedef struct s_image
{
	void	*xpm_ptr;
	int		x;
	int		y;
}	t_image;

typedef struct s_being
{
	int		x;
	int		y;
	int		offset_x;
	int		offset_y;
	int		last_move;
	int		type;
}	t_being;

typedef struct s_game
{
	int			win_condition;
	int			movements;
	int			enemy_count;
	int			frame;
	int			map_x_offset;
	int			map_y_offset;
	void		*mlx;
	void		*win;
	char		**map;
	long long	time;
	t_being		player_status;
	t_being		*enemy_status;
	t_image		enemy[2][4][5];
	t_image		player[4][5];
	t_image		wall;
	t_image		floor;
	t_image		collectible;
	t_image		map_exit[5];
	t_image		win_screen;
	t_image		shadow;
}	t_game;

typedef struct s_point
{
	int		x;
	int		y;
	int		dist;
}	t_point;

size_t		ft_strstr_len(char **str);
void		init_comp(t_comp *comps);
void		throw_error(t_comp *comps);
char		**ft_strstrdup(char **str, int size);
void		ft_strstr_free(char **str);

int			count_lines(int fd);
char		**read_map(char	*map);
int			check_rectangular(char **map);
int			check_walls(char **map);
int			components_ifs(char c, t_comp *comps);
t_comp		*check_components(char **map);
void		count_components(char **map, t_comp *comps);
int			compare_components(t_comp *comps1, t_comp *comps2);
void		check_path(char **map, t_comp *comps, int x, int y);
int			find_path(t_game *game, t_comp *comps);
void		check_map(t_game *game);

int			create_trgb(int t, int r, int g, int b);
int			get_t(int trgb);
int			get_r(int trgb);
int			get_g(int trgb);
int			get_b(int trgb);

int			ft_abs(int n);
int			calc_off(int offset);
int			check_move(int *offset, int *coord);
int			move_enemies(t_game *game);
int			check_direction(t_being *being);
void		redraw_backgroung(t_game *game, t_being *being);
int			init_enemies(t_game *game);
void		render_enemies(t_game *game);

void		game_init(t_game *game);
int			game_start(t_game *game);
void		check_interaction(t_game *game, t_being	being);
int			check_win(t_game *game);
int			check_enemies(t_game *game, int x, int y);
int			check_player(t_game *game, int x, int y);

int			init_images(t_game	*game);
void		pick_image(char comp, t_game *game, int x, int y);
void		render_image(t_game *game, t_image sprite, int x, int y);
void		render_map(t_game *game, char **map);
void		render_exit(t_game *game);
void		render_player(t_game *game);
void		show_moves(t_game *game);
long long	millitimestamp(void);

int			key_hook(int keycode, t_game *game);
void		update_player_pos(t_game *game);

void		ft_error_msg(const char *msg, t_game *game);
int			close_game(t_game *game);
void		game_win(t_game *game);
void		game_loose(t_game *game);

#endif
