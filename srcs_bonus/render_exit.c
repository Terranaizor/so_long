/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nradin <nradin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 18:57:47 by nradin            #+#    #+#             */
/*   Updated: 2023/02/24 16:09:37 by nradin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	render_exit(t_game *game, int x, int y)
{
	if (!check_win(game))
		render_image(game, game->map_exit[0], x * 60, y * 60);
	else
		render_image(game, game->map_exit[game->frame % 4 + 1], x * 60, y * 60);
}
