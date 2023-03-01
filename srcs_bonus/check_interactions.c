/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_interactions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nradin <nradin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 14:44:29 by nradin            #+#    #+#             */
/*   Updated: 2023/03/01 17:08:20 by nradin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

int	check_win(t_game *game)
{
	t_comp	*comps;

	comps = calloc(sizeof(t_comp), 1);
	count_components(game->map, comps);
	if (comps->collect == 0)
	{
		free(comps);
		return (1);
	}
	free(comps);
	return (0);
}

int	check_player(t_game *game, int x, int y)
{
	if (x == game->player_status.x - \
		game->player_status.offset_x / 4)
	{
		if (y == game->player_status.y - \
			game->player_status.offset_y / 4)
			return (1);
	}
	return (0);
}

int	check_enemies(t_game *game, int x, int y)
{
	int	i;

	i = 0;
	while (i < game->enemy_count)
	{
		if (x == game->enemy_status[i].x - \
			game->enemy_status[i].offset_x / 4)
		{
			if (y == game->enemy_status[i].y - \
				game->enemy_status[i].offset_y / 4)
				return (1);
		}
		i++;
	}
	return (0);
}

void	check_interaction(t_game *game, t_being	being)
{
	int	x;
	int	y;

	x = being.x;
	y = being.y;
	if (game->map[y][x] == COLLECTIBLE)
		game->map[y][x] = FLOOR;
	if (check_enemies(game, x, y))
	{
		game->win_condition = -1;
		return ;
	}
	if (game->map[y][x] == MAP_EXIT)
	{
		if (check_win(game))
			game->win_condition = 1;
	}
}
