/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_beings.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nradin <nradin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 14:09:55 by nradin            #+#    #+#             */
/*   Updated: 2023/02/28 19:19:49 by nradin           ###   ########.fr       */
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

void	redraw_backgroung(t_game *game, t_being *being)
{
	int	dir;
	int	x;
	int	y;

	if (!being->offset_x && !being->offset_y)
		return ;
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
	if (!check_enemies(game, x, y) && !check_player(game, x, y))
		pick_image(game->map[y][x], game, x, y);
}
