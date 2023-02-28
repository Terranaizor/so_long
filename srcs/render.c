/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nradin <nradin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:17:39 by nradin            #+#    #+#             */
/*   Updated: 2023/02/28 18:36:23 by nradin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	render_image(t_game *game, t_image sprite, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, sprite.xpm_ptr, \
		sprite.x * x, sprite.y * y);
}

void	pick_image(char comp, t_game *game, int x, int y)
{
	render_image(game, game->floor, x, y);
	if (comp == WALL)
		render_image(game, game->wall, x, y);
	else if (comp == COLLECTIBLE)
		render_image(game, game->collectible, x, y);
	else if (comp == MAP_EXIT)
		render_image(game, game->map_exit, x, y);
}

void	render_map(t_game *game, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			pick_image(map[i][j], game, j, i);
			j++;
		}
		i++;
	}
	render_image(game, game->player, game->player_pos.x, game->player_pos.y);
}

int	game_loop(t_game *game)
{
	if (game->win_condition == 0)
	{
		render_image(game, game->player, \
			game->player_pos.x, game->player_pos.y);
	}
	else
	{
		ft_printf("\n\
██████████████████████████████████████████████████████████████████\n\
██                                                              ██\n\
██  ███  ███  ██████  ██    ██     ██      ██ ██ ██    ██   ██  ██\n\
██   ██  ██  ██    ██ ██    ██     ██      ██ ██ ███   ██   ██  ██\n\
██    ████   █      █ ██    ██     ██  ██  ██ ██ ██ ██ ██   ██  ██\n\
██     ██    ██    ██ ██    ██     ██ ████ ██ ██ ██  ████       ██\n\
██     ██     ██████    ████        ███  ███  ██ ██   ███   ██  ██\n\
██                                                              ██\n\
██████████████████████████████████████████████████████████████████\n\n\
");
		close_game(game);
	}
	return (1);
}

int	game_start(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, 1920, 1080, "Game");
	init_images(game);
	render_map(game, game->map);
	mlx_hook(game->win, 17, 1L << 0, close_game, game);
	mlx_key_hook(game->win, key_hook, game);
	mlx_loop_hook(game->mlx, game_loop, game);
	mlx_loop(game->mlx);
	return (1);
}
