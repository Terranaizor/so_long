/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nradin <nradin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:17:39 by nradin            #+#    #+#             */
/*   Updated: 2023/03/03 23:08:45 by nradin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	render_image(t_game *game, t_image sprite, int x, int y)
{
	if (x >= (game->map_x / 2 + 1) * 60)
		x--;
	if (y >= (game->map_y / 2 + 1) * 60)
		y--;
	mlx_put_image_to_window(game->mlx, game->win, sprite.xpm_ptr, x, y);
}

void	pick_image(char comp, t_game *game, int x, int y)
{
	render_image(game, game->floor, x * 60, y * 60);
	if (comp == WALL)
		render_image(game, game->wall, x * 60, y * 60);
}

void	render_map(t_game *game, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] && map[i][j] != '\n')
		{
			pick_image(map[i][j], game, j, i);
			j++;
		}
		i++;
	}
	render_coins(game);
	render_exit(game);
}

int	game_loop(t_game *game)
{
	long long	now;
	long long	diff;
	static int	game_ended;

	now = millitimestamp();
	diff = now - game->time;
	if (diff > 120 && !game_ended)
	{
		game->frame++;
		game->time = now;
		if (game->win_condition == 0)
		{
			if (game->frame == 12)
			{
				game->frame = 0;
				move_enemies(game);
			}
			render_animations(game);
			show_moves(game);
		}
		else
		{
			game_ended = 1;
			game_end(game);
		}
	}
	return (1);
}

int	game_start(t_game *game)
{
	game->mlx = mlx_init();
	game_init(game);
	game->win = mlx_new_window(game->mlx, game->map_x * 60, \
		game->map_y * 60 + 30, "Game");
	init_images(game);
	init_enemies(game);
	render_map(game, game->map);
	mlx_hook(game->win, 17, 1L << 0, close_game, game);
	mlx_key_hook(game->win, key_hook, game);
	mlx_loop_hook(game->mlx, game_loop, game);
	mlx_loop(game->mlx);
	return (1);
}
