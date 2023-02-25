/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nradin <nradin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 18:22:34 by nradin            #+#    #+#             */
/*   Updated: 2023/02/13 13:25:46 by nradin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	game_init(t_game *game)
{
	game->win_condition = 0;
	game->movements = 0;
	game->mlx = NULL;
	game->win = NULL;
	game->wall.xpm_ptr = NULL;
	game->player.xpm_ptr = NULL;
	game->floor.xpm_ptr = NULL;
	game->map_exit.xpm_ptr = NULL;
	game->collectible.xpm_ptr = NULL;
	game->win_screen.xpm_ptr = NULL;
}
