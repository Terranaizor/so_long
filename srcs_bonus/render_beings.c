/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_beings.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nradin <nradin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 14:09:55 by nradin            #+#    #+#             */
/*   Updated: 2023/03/01 12:57:55 by nradin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	calc_off(int offset)
{
	if (offset > 0)
	{
		return (-4 + offset);
	}
	else if (offset < 0)
	{
		return (4 + offset);
	}
	return (0);
}

int	check_direction(t_being *being)
{
	if (being->offset_x < 0)
		being->last_move = 2;
	else if (being->offset_x > 0)
		being->last_move = 0;
	else if (being->offset_y > 0)
		being->last_move = 3;
	else if (being->offset_y < 0)
		being->last_move = 1;
	return (being->last_move);
}

int	check_move(int *offset, int *coord)
{
	if ((*offset) > 0)
	{
		(*offset)--;
		if ((*offset) == 0)
		{
			(*coord)--;
			return (1);
		}
	}
	else if ((*offset) < 0)
	{
		(*offset)++;
		if ((*offset) == 0)
		{
			(*coord)++;
			return (1);
		}
	}
	return (0);
}

void	redraw_being_backgroung(t_game *game, t_being *being)
{
	int	dir;
	int	x;
	int	y;

	dir = check_direction(being);
	x = being->x;
	y = being->y;
	pick_image(game->map[y][x], game, x, y);
	if (dir == 0)
		x--;
	else if (dir == 0)
		x--;
	else if (dir == 1)
		y++;
	else if (dir == 2)
		x++;
	else if (dir == 3)
		y--;
	pick_image(game->map[y][x], game, x, y);
}

void	redraw_coins_backgroung(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j] && game->map[i][j] != '\n')
		{
			if (game->map[i][j] == COLLECTIBLE)
			{
				render_image(game, game->floor, j * 60, i * 60);
			}
			j++;
		}
		i++;
	}
}

void	redraw_backgroung(t_game *game)
{
	int	i;

	i = 0;
	redraw_being_backgroung(game, &game->player_status);
	redraw_coins_backgroung(game);
	while (i < game->enemy_count)
	{
		redraw_being_backgroung(game, &game->enemy_status[i]);
		i++;
	}
}
