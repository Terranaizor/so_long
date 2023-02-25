/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nradin <nradin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 18:22:34 by nradin            #+#    #+#             */
/*   Updated: 2023/02/24 16:41:27 by nradin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	game_init(t_game *game)
{
	game->map_x_offset = (1920 - ft_strlen(game->map[0]) - 1) / 2;
	game->map_y_offset = (1080 - ft_strstr_len(game->map)) / 2;
	game->player_status.offset_x = 0;
	game->player_status.offset_y = 0;
	game->player_status.last_move = 1;
}
