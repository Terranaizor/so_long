/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nradin <nradin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 12:06:08 by nradin            #+#    #+#             */
/*   Updated: 2023/03/01 16:08:55 by nradin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	free_game(t_game *game)
{
	if (game->mlx)
		free(game->mlx);
	if (game->win)
		free(game->win);
	if (game->map)
		free(game->map);
	if (game->wall.xpm_ptr)
		free(game->wall.xpm_ptr);
	// if (game->player[0].xpm_ptr)
	// 	free(game->player[0].xpm_ptr);
	if (game->floor.xpm_ptr)
		free(game->floor.xpm_ptr);
	// if (game->map_exit.xpm_ptr)
	// 	free(game->map_exit.xpm_ptr);
	if (game->collectible.xpm_ptr)
		free(game->collectible.xpm_ptr);
	if (game->win_screen.xpm_ptr)
		free(game->win_screen.xpm_ptr);
	// if (game->enemy.xpm_ptr)
	// 	free(game->enemy.xpm_ptr);
}

void	ft_error_msg(const char *msg, t_game *game)
{
	ft_putstr_fd((char *)msg, 2);
	free_game(game);
	free(game);
	exit (EXIT_FAILURE);
}

int	close_game(t_game *game)
{
	free_game(game);
	free(game);
	exit (0);
	return (0);
}

void	game_end(t_game *game)
{
	int	i;

	i = 0;
	game->player_status.last_move = 1;
	game->player_status.offset_x = 0;
	game->player_status.offset_y = 0;
	while (i < game->enemy_count)
	{
		game->enemy_status[i].last_move = 1;
		game->enemy_status[i].offset_x = 0;
		game->enemy_status[i].offset_y = 0;
		i++;
	}
	render_map(game, game->map);
	render_animations(game);
}
