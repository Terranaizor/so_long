/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nradin <nradin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:59:03 by nradin            #+#    #+#             */
/*   Updated: 2023/02/02 16:57:29 by nradin           ###   ########.fr       */
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

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_image	player;
	t_image	wall;
	t_image	floor;
	t_image	collectible;
	t_image	map_exit;
}	t_game;

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
int		compare_components(t_comp *comps1, t_comp *comps2);
void	check_path(char **map, t_comp *comps, int x, int y);
int		find_path(char **map, t_comp *comps);
void	check_map(char	**map);

int		create_trgb(int t, int r, int g, int b);
int		get_t(int trgb);
int		get_r(int trgb);
int		get_g(int trgb);
int		get_b(int trgb);

int		game_start(char	**map);

#endif
