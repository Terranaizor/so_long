/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nradin <nradin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 18:09:49 by nradin            #+#    #+#             */
/*   Updated: 2023/03/04 15:15:04 by nradin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

long long	millitimestamp(void)
{
	struct timeval	timeval;
	long long		microtime;

	gettimeofday(&timeval, NULL);
	microtime = timeval.tv_sec * 1000LL + timeval.tv_usec / 1000;
	return (microtime);
}

void	show_moves(t_game *game)
{
	char	*moves;
	char	*num;

	num = ft_itoa(game->movements);
	moves = ft_strjoin("Number of movements:", num);
	render_image(game, game->black, (game->map_x - 4) \
		/ 2 * 60 + 40, game->map_y * 60);
	mlx_string_put(game->mlx, game->win, (game->map_x - 4) \
		/ 2 * 60 + 40, game->map_y * 60 + 18, \
		create_trgb(255, 0, 255, 0), moves);
	free(moves);
	free(num);
}
