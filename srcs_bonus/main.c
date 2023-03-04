/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nradin <nradin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 17:30:46 by nradin            #+#    #+#             */
/*   Updated: 2023/03/04 14:33:18 by nradin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

int	main(int argc, char *argv[])
{
	t_game	*game;

	game = ft_calloc(sizeof(t_game), 1);
	if (argc != 2)
		throw_error(game, NULL, ARGS_ERROR);
	game->map = read_map(game, argv[1]);
	check_map(game);
	game->mlx = mlx_init();
	game_init(game);
	game->win = mlx_new_window(game->mlx, game->map_x * 60, \
		game->map_y * 60 + 30, "Game");
	init_images(game);
	init_enemies(game);
	render_map(game, game->map);
	mlx_hook(game->win, 17, 1L << 0, close_game, game);
	mlx_key_hook(game->win, key_hook, game);
	mlx_loop_hook(game->mlx, game_loop, game);
	mlx_loop(game->mlx);
	return (0);
}
