/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nradin <nradin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 12:06:08 by nradin            #+#    #+#             */
/*   Updated: 2023/02/08 18:13:52 by nradin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	free_game(t_game *game)
{
	if (game->mlx)
		free(game->mlx);
	if (game->win)
		free(game->win);
	if (game->wall.xpm_ptr)
		free(game->wall.xpm_ptr);
	if (game->player.xpm_ptr)
		free(game->player.xpm_ptr);
	if (game->floor.xpm_ptr)
		free(game->floor.xpm_ptr);
	if (game->map_exit.xpm_ptr)
		free(game->map_exit.xpm_ptr);
	if (game->collectible.xpm_ptr)
		free(game->collectible.xpm_ptr);
	if (game->win_screen.xpm_ptr)
		free(game->win_screen.xpm_ptr);
}

void	ft_error_msg(const char *msg, t_game *game)
{
	ft_putstr_fd((char *)msg, 2);
	free_game(game);
	free(game);
	exit (EXIT_FAILURE);
}
