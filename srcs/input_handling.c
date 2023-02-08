/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nradin <nradin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:21:45 by nradin            #+#    #+#             */
/*   Updated: 2023/02/08 18:41:29 by nradin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

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

void	check_interaction(t_game *game)
{
	int	x;
	int	y;

	x = game->player_pos.x;
	y = game->player_pos.y;
	if (game->map[y][x] == COLLECTIBLE)
		game->map[y][x] = FLOOR;
	if (game->map[y][x] == MAP_EXIT)
	{
		if (check_win(game))
			render_image(game, game->win_screen, 0, 0);
	}
}

int	move_player(int key, t_game *game)
{
	int	x;
	int	y;

	x = game->player_pos.x;
	y = game->player_pos.y;
	if (key == KEY_W)
		y -= 1;
	else if (key == KEY_S)
		y += 1;
	else if (key == KEY_A)
		x -= 1;
	else if (key == KEY_D)
		x += 1;
	if (game->map[y][x] != WALL)
	{
		game->player_pos.x = x;
		game->player_pos.y = y;
		check_interaction(game);
		render_map(game, game->map);
		return (1);
	}
	return (0);
}

int	key_hook(int key, t_game *game)
{
	if (key == KEY_W || key == KEY_A || key == KEY_S || key == KEY_D)
		move_player(key, game);
	return (0);
}
