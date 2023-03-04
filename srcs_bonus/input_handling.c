/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nradin <nradin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:21:45 by nradin            #+#    #+#             */
/*   Updated: 2023/03/04 12:26:39 by nradin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

int	move_player(int key, t_game *game)
{
	int	x;
	int	y;

	x = game->player_status.x;
	y = game->player_status.y;
	moves_ifs(key, &x, &y, &game->player_status);
	if (game->map[y][x] != WALL)
		return (1);
	game->player_status.offset_x = 0;
	game->player_status.offset_y = 0;
	return (0);
}

void	move_enemy_horizontal(t_game *game, t_being *enemy)
{
	if (!(enemy->offset_x == 0 && enemy->offset_y == 0))
		return ;
	if (enemy->last_move == 2)
	{
		if (game->map[enemy->y][enemy->x + 1] == WALL || \
			check_enemies(game, enemy->x + 1, enemy->y))
			enemy->last_move = 0;
		else
			enemy->offset_x = -5;
	}
	else if (enemy->last_move == 0)
	{
		if (game->map[enemy->y][enemy->x - 1] == WALL || \
		check_enemies(game, enemy->x - 1, enemy->y))
			enemy->last_move = 2;
		else
			enemy->offset_x = 5;
	}
}

void	move_enemy_vertical(t_game *game, t_being *enemy)
{
	if (!(enemy->offset_x == 0 && enemy->offset_y == 0))
		return ;
	if (enemy->last_move == 3)
	{
		if (game->map[enemy->y - 1][enemy->x] == WALL || \
			check_enemies(game, enemy->x, enemy->y - 1))
			enemy->last_move = 1;
		else
			enemy->offset_y = 5;
	}
	else if (enemy->last_move == 1)
	{
		if (game->map[enemy->y + 1][enemy->x] == WALL || \
		check_enemies(game, enemy->x, enemy->y + 1))
			enemy->last_move = 3;
		else
			enemy->offset_y = -5;
	}
}

int	move_enemies(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->enemy_count)
	{
		if (game->enemy_status[i].last_move % 2 == 0)
			move_enemy_horizontal(game, &game->enemy_status[i]);
		else
			move_enemy_vertical(game, &game->enemy_status[i]);
		i++;
	}
	return (0);
}

int	key_hook(int key, t_game *game)
{
	if (key == KEY_W || key == KEY_A || key == KEY_S || key == KEY_D)
	{
		if (!game->win_condition && game->player_status.offset_x == 0 && \
			game->player_status.offset_y == 0 && move_player(key, game))
		{
			game->movements += 1;
		}
	}
	else if (key == KEY_ESC)
		close_game(game);
	return (0);
}
