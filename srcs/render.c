/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nradin <nradin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:17:39 by nradin            #+#    #+#             */
/*   Updated: 2023/02/02 17:55:17 by nradin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	init_images(t_game	*game)
{
	if (!game)
		return (0);
	game->wall.xpm_ptr = mlx_xpm_file_to_image(game->mlx, "wall.xpm", \
	&game->wall.x, &game->wall.y);
	game->player.xpm_ptr = mlx_xpm_file_to_image(game->mlx, "pacman.xpm", \
	&game->player.x, &game->player.y);
	game->floor.xpm_ptr = mlx_xpm_file_to_image(game->mlx, "black.xpm", \
	&game->floor.x, &game->floor.y);
	game->map_exit.xpm_ptr = mlx_xpm_file_to_image(game->mlx, "portal.xpm", \
	&game->map_exit.x, &game->map_exit.y);
	// game->collectible.xpm_ptr = mlx_xpm_file_to_image(game->mlx, "food.xpm", \
	// &game->collectible.x, &game->collectible.y);
	return (1);
}

void	render_map(t_game *game, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == WALL)
				mlx_put_image_to_window(game->mlx, game->win, game->wall.xpm_ptr, game->wall.x * j, game->wall.y * i);
			// else if (map[i][j] == FLOOR)
			// 	mlx_put_image_to_window(game->mlx, game->win, game->floor.xpm_ptr, game->floor.x * j, game->floor.y * i);
			// else if (map[i][j] == COLLECTIBLE)
			// {
			// 	mlx_put_image_to_window(game->mlx, game->win, game->floor.xpm_ptr, game->floor.x * j, game->floor.y * i);
			// 	mlx_put_image_to_window(game->mlx, game->win, game->collectible.xpm_ptr, game->collectible.x * j, game->collectible.y * i);
			// }
			else if (map[i][j] == PLAYER)
			{
				// mlx_put_image_to_window(game->mlx, game->win, game->floor.xpm_ptr, game->floor.x * j, game->floor.y * i);
				mlx_put_image_to_window(game->mlx, game->win, game->player.xpm_ptr, game->player.x * j, game->player.y * i);
			}
			else if (map[i][j] == MAP_EXIT)
			{
				// mlx_put_image_to_window(game->mlx, game->win, game->floor.xpm_ptr, game->floor.x * j, game->floor.y * i);
				mlx_put_image_to_window(game->mlx, game->win, game->map_exit.xpm_ptr, game->map_exit.x * j, game->map_exit.y * i);
			}
			j++;
		}
		i++;
	}
}

int	game_start(char	**map)
{
	t_game	*game;
	int		i;
	int		j;

	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, 1920, 1080, "Game");
	init_images(game);
	// render_map(game, map);
	mlx_loop(game->mlx);
	return (1);
}
