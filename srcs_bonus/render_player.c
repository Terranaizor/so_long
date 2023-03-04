/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nradin <nradin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 12:47:08 by nradin            #+#    #+#             */
/*   Updated: 2023/03/04 12:51:14 by nradin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	render_player(t_game *game, t_being *player)
{
	int	moved;

	moved = check_move(&player->offset_x, &player->x);
	if (!moved)
		moved = check_move(&player->offset_y, &player->y);
	if (moved)
		check_interaction(game, *player);
	if (game->map[player->y][player->x] != MAP_EXIT)
		render_image(game, \
			game->shadow, \
			player->x * 60 + \
			calc_off(player->offset_x) * 15, \
			player->y * 60 + \
			calc_off(player->offset_y) * 15);
	render_image(game, \
		game->player[check_direction(player)] \
		[ft_abs(calc_off(player->offset_x)) + \
		ft_abs(calc_off(player->offset_y))], \
		player->x * 60 + \
		calc_off(player->offset_x) * 15, \
		player->y * 60 + \
		calc_off(player->offset_y) * 15);
}

void	render_player_loose(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j] && game->map[i][j] != '\n')
		{
			if (game->map[i][j] == MAP_EXIT)
			{
				render_image(game, game->floor, j * 60, i * 60);
				render_image(game, game->player_loose, j * 60, i * 60);
			}
			j++;
		}
		i++;
	}
}

void	render_player_win(t_game *game)
{
	render_image(game, game->player_win, \
		game->player_status.x * 60, game->player_status.y * 60);
}
