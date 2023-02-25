/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_beings.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nradin <nradin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 14:09:55 by nradin            #+#    #+#             */
/*   Updated: 2023/02/22 19:21:41 by nradin           ###   ########.fr       */
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
