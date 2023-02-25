/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nradin <nradin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 18:57:47 by nradin            #+#    #+#             */
/*   Updated: 2023/02/24 15:26:52 by nradin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	render_player(t_game *game)
{
	int	moved;

	moved = 0;
	render_image(game, \
		game->player[check_direction(&game->player_status)] \
		[ft_abs(calc_off(game->player_status.offset_x)) + \
		ft_abs(calc_off(game->player_status.offset_y))], \
		game->player_status.x * 60 + \
		calc_off(game->player_status.offset_x) * 15, \
		game->player_status.y * 60 + \
		calc_off(game->player_status.offset_y) * 15);
	moved = check_move(&game->player_status.offset_x, &game->player_status.x);
	if (!moved)
		moved = check_move(&game->player_status.offset_y, \
			&game->player_status.y);
	if (moved)
		check_interaction(game, game->player_status);
}
