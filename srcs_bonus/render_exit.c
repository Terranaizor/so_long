/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nradin <nradin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 18:57:47 by nradin            #+#    #+#             */
/*   Updated: 2023/02/28 18:26:25 by nradin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	render_exit(t_game *game)
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
				if (!check_win(game))
					render_image(game, game->map_exit[0], j * 60, i * 60);
				else
					render_image(game, game->map_exit[game->frame % 4 + 1], \
						j * 60, i * 60);
			}
			j++;
		}
		i++;
	}
}
