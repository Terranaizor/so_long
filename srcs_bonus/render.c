/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nradin <nradin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:17:39 by nradin            #+#    #+#             */
/*   Updated: 2023/02/28 20:19:18 by nradin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	render_image(t_game *game, t_image sprite, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, sprite.xpm_ptr, x, y);
}

void	pick_image(char comp, t_game *game, int x, int y)
{
	if (comp)
		render_image(game, game->floor, x * 60, y * 60);
	if (comp == WALL)
		render_image(game, game->wall, x * 60, y * 60);
	if (comp == COLLECTIBLE)
		render_image(game, game->collectible, x * 60, y * 60);
	else if (comp == MAP_EXIT)
		render_exit(game);
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
}

int	game_loop(t_game *game)
{
	long long	now;
	long long	diff;

	now = millitimestamp();
	diff = now - game->time;
	if (diff > 120)
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
			render_exit(game);
			render_beings(game);
			// show_moves(game);
		}
		else
			game_win(game);
	}
	return (1);
}

int	game_start(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, 1920, 1080, "Game");
	mlx_sync(3, game->win);
	init_images(game);
	init_enemies(game);
	game_init(game);
	render_map(game, game->map);
	mlx_hook(game->win, 17, 1L << 0, close_game, game);
	mlx_key_hook(game->win, key_hook, game);
	mlx_loop_hook(game->mlx, game_loop, game);
	mlx_loop(game->mlx);
	return (1);
}
