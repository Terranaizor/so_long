/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_enemies.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nradin <nradin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 13:57:24 by nradin            #+#    #+#             */
/*   Updated: 2023/02/28 18:30:48 by nradin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	enemy_ifs(t_being *enemy, char direct)
{
	if (direct == ENEMY_HORIZONTAL)
		enemy->last_move = rand() % 2 * 2;
	if (direct == ENEMY_VERTICAL)
		enemy->last_move = rand() % 2 * 2 + 1;
	enemy->type = rand() % 2;
}

void	add_enemies(t_game *game)
{
	int		i;
	int		j;
	int		e;

	srand(time(NULL));
	i = 0;
	e = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == ENEMY_HORIZONTAL || \
				game->map[i][j] == ENEMY_VERTICAL)
			{
				enemy_ifs(&game->enemy_status[e], game->map[i][j]);
				game->enemy_status[e].x = j;
				game->enemy_status[e].y = i;
				e++;
				game->map[i][j] = FLOOR;
			}
			j++;
		}
		i++;
	}
}

int	init_enemies(t_game *game)
{
	t_comp	*comps;

	comps = ft_calloc(sizeof(t_comp), 1);
	count_components(game->map, comps);
	game->enemy_count = comps->enemy;
	game->enemy_status = ft_calloc(sizeof(t_being), comps->enemy);
	add_enemies(game);
	free(comps);
	return (1);
}

void	render_enemies(t_game *game)
{
	int	i;
	int	moved;

	i = 0;
	while (i < game->enemy_count)
	{
		moved = 0;
		redraw_backgroung(game, &game->enemy_status[i]);
		moved = check_move(&game->enemy_status[i].offset_x, \
			&game->enemy_status[i].x);
		if (!moved)
			moved = check_move(&game->enemy_status[i].offset_y, \
				&game->enemy_status[i].y);
		if (moved)
			if (check_player(game, game->enemy_status[i].x, game->enemy_status[i].y))
				game_loose(game);
		render_image(game, \
		game->enemy[game->enemy_status[i].type] \
		[check_direction(&(game->enemy_status[i]))] \
		[ft_abs(calc_off(game->enemy_status[i].offset_x)) + \
		ft_abs(calc_off(game->enemy_status[i].offset_y))], \
		game->enemy_status[i].x * 60 + \
		calc_off(game->enemy_status[i].offset_x) * 15, \
		game->enemy_status[i].y * 60 + \
		calc_off(game->enemy_status[i].offset_y) * 15);
		i++;
	}
}
