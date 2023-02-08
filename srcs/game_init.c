/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nradin <nradin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 18:22:34 by nradin            #+#    #+#             */
/*   Updated: 2023/02/08 18:04:00 by nradin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

// void	update_player_pos(t_game *game)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (game->map[i])
// 	{
// 		j = 0;
// 		while (game->map[i][j])
// 		{
// 			if (game->map[i][j] == PLAYER)
// 			{
// 				game->player_pos.x = j;
// 				game->player_pos.y = i;
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// }

void	game_init(t_game *game)
{
	game->mlx = NULL;
	game->win = NULL;
	game->wall.xpm_ptr = NULL;
	game->player.xpm_ptr = NULL;
	game->floor.xpm_ptr = NULL;
	game->map_exit.xpm_ptr = NULL;
	game->collectible.xpm_ptr = NULL;
	game->win_screen.xpm_ptr = NULL;
}
