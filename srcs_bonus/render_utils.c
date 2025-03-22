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

mlx_image_t *show_moves(t_game *game) {
    mlx_image_t *text_img;
    char *moves;

    moves = ft_itoa(game->movements);
    if (!moves)
        return (NULL);
    text_img = mlx_put_string(game->mlx, moves, (game->map_x - 4) / 2 * 60 + 40, game->map_y * 60 + 18);
    free(moves);
    if (text_img) {
        mlx_set_instance_depth(text_img->instances, 100);
    }
    return (text_img);
}