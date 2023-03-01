/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nradin <nradin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 17:30:46 by nradin            #+#    #+#             */
/*   Updated: 2023/03/01 15:48:20 by nradin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

int	main(int argc, char *argv[])
{
	t_game	*game;

	game = ft_calloc(sizeof(t_game), 1);
	if (argc != 2)
		return (0);
	game->map = read_map(argv[1]);
	check_map(game);
	game_start(game);
	return (0);
}
