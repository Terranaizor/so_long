/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   picture_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nradin <nradin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 18:02:57 by nradin            #+#    #+#             */
/*   Updated: 2023/03/01 14:55:22 by nradin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

t_image	read_xmp_image(void *mlx, char *file, t_game *game)
{
	t_image	sprite;

	sprite.xpm_ptr = mlx_xpm_file_to_image(mlx, file, &sprite.x, &sprite.y);
	if (sprite.xpm_ptr == NULL)
		ft_error_msg("Couldn't find a sprite. Does it exist?", game);
	return (sprite);
}

void	init_player_images(t_game	*game)
{
	game->player[1][0] = read_xmp_image(game->mlx, PLAYER_DOWN_0_PATH, game);
	game->player[1][1] = read_xmp_image(game->mlx, PLAYER_DOWN_1_PATH, game);
	game->player[1][2] = game->player[1][0];
	game->player[1][3] = read_xmp_image(game->mlx, PLAYER_DOWN_2_PATH, game);
	game->player[1][4] = game->player[1][0];
	game->player[0][0] = read_xmp_image(game->mlx, PLAYER_LEFT_0_PATH, game);
	game->player[0][1] = read_xmp_image(game->mlx, PLAYER_LEFT_1_PATH, game);
	game->player[0][2] = game->player[0][0];
	game->player[0][3] = read_xmp_image(game->mlx, PLAYER_LEFT_2_PATH, game);
	game->player[0][4] = game->player[0][0];
	game->player[2][0] = read_xmp_image(game->mlx, PLAYER_RIGHT_0_PATH, game);
	game->player[2][1] = read_xmp_image(game->mlx, PLAYER_RIGHT_1_PATH, game);
	game->player[2][2] = game->player[2][0];
	game->player[2][3] = read_xmp_image(game->mlx, PLAYER_RIGHT_2_PATH, game);
	game->player[2][4] = game->player[2][0];
	game->player[3][0] = read_xmp_image(game->mlx, PLAYER_UP_0_PATH, game);
	game->player[3][1] = read_xmp_image(game->mlx, PLAYER_UP_1_PATH, game);
	game->player[3][2] = game->player[3][0];
	game->player[3][3] = read_xmp_image(game->mlx, PLAYER_UP_2_PATH, game);
	game->player[3][4] = game->player[3][0];
}

void	init_enemy_1_images(t_game	*game)
{
	game->enemy[0][1][0] = read_xmp_image(game->mlx, ENEMY_1_DOWN_0_PATH, game);
	game->enemy[0][1][1] = read_xmp_image(game->mlx, ENEMY_1_DOWN_1_PATH, game);
	game->enemy[0][1][2] = game->enemy[0][1][0];
	game->enemy[0][1][3] = read_xmp_image(game->mlx, ENEMY_1_DOWN_2_PATH, game);
	game->enemy[0][1][4] = game->enemy[0][1][0];
	game->enemy[0][0][0] = read_xmp_image(game->mlx, ENEMY_1_LEFT_0_PATH, game);
	game->enemy[0][0][1] = read_xmp_image(game->mlx, ENEMY_1_LEFT_1_PATH, game);
	game->enemy[0][0][2] = game->enemy[0][0][0];
	game->enemy[0][0][3] = read_xmp_image(game->mlx, ENEMY_1_LEFT_2_PATH, game);
	game->enemy[0][0][4] = game->enemy[0][0][0];
	game->enemy[0][2][0] = read_xmp_image(game->mlx, ENEMY_1_RIGHT_0_PATH, \
	game);
	game->enemy[0][2][1] = read_xmp_image(game->mlx, ENEMY_1_RIGHT_1_PATH, \
	game);
	game->enemy[0][2][2] = game->enemy[0][2][0];
	game->enemy[0][2][3] = read_xmp_image(game->mlx, ENEMY_1_RIGHT_2_PATH, \
	game);
	game->enemy[0][2][4] = game->enemy[0][2][0];
	game->enemy[0][3][0] = read_xmp_image(game->mlx, ENEMY_1_UP_0_PATH, game);
	game->enemy[0][3][1] = read_xmp_image(game->mlx, ENEMY_1_UP_1_PATH, game);
	game->enemy[0][3][2] = game->enemy[0][3][0];
	game->enemy[0][3][3] = read_xmp_image(game->mlx, ENEMY_1_UP_2_PATH, game);
	game->enemy[0][3][4] = game->enemy[0][3][0];
}

void	init_enemy_2_images(t_game	*game)
{
	game->enemy[1][1][0] = read_xmp_image(game->mlx, ENEMY_2_DOWN_0_PATH, game);
	game->enemy[1][1][1] = read_xmp_image(game->mlx, ENEMY_2_DOWN_1_PATH, game);
	game->enemy[1][1][2] = game->enemy[1][1][0];
	game->enemy[1][1][3] = read_xmp_image(game->mlx, ENEMY_2_DOWN_2_PATH, game);
	game->enemy[1][1][4] = game->enemy[1][1][0];
	game->enemy[1][0][0] = read_xmp_image(game->mlx, ENEMY_2_LEFT_0_PATH, game);
	game->enemy[1][0][1] = read_xmp_image(game->mlx, ENEMY_2_LEFT_1_PATH, game);
	game->enemy[1][0][2] = game->enemy[1][0][0];
	game->enemy[1][0][3] = read_xmp_image(game->mlx, ENEMY_2_LEFT_2_PATH, game);
	game->enemy[1][0][4] = game->enemy[1][0][0];
	game->enemy[1][2][0] = read_xmp_image(game->mlx, ENEMY_2_RIGHT_0_PATH, \
	game);
	game->enemy[1][2][1] = read_xmp_image(game->mlx, ENEMY_2_RIGHT_1_PATH, \
	game);
	game->enemy[1][2][2] = game->enemy[1][2][0];
	game->enemy[1][2][3] = read_xmp_image(game->mlx, ENEMY_2_RIGHT_2_PATH, \
	game);
	game->enemy[1][2][4] = game->enemy[1][2][0];
	game->enemy[1][3][0] = read_xmp_image(game->mlx, ENEMY_2_UP_0_PATH, game);
	game->enemy[1][3][1] = read_xmp_image(game->mlx, ENEMY_2_UP_1_PATH, game);
	game->enemy[1][3][2] = game->enemy[1][3][0];
	game->enemy[1][3][3] = read_xmp_image(game->mlx, ENEMY_2_UP_2_PATH, game);
	game->enemy[1][3][4] = game->enemy[1][3][0];
}

int	init_images(t_game	*game)
{
	if (!game)
		return (0);
	game->wall = read_xmp_image(game->mlx, WALL_PATH, game);
	game->floor = read_xmp_image(game->mlx, FLOOR_PATH, game);
	game->map_exit[0] = read_xmp_image(game->mlx, MAP_EXIT_0_PATH, game);
	game->map_exit[1] = read_xmp_image(game->mlx, MAP_EXIT_1_PATH, game);
	game->map_exit[2] = read_xmp_image(game->mlx, MAP_EXIT_2_PATH, game);
	game->map_exit[3] = read_xmp_image(game->mlx, MAP_EXIT_3_PATH, game);
	game->map_exit[4] = read_xmp_image(game->mlx, MAP_EXIT_4_PATH, game);
	game->collectible = read_xmp_image(game->mlx, COLLECTIBLE_PATH, game);
	game->shadow = read_xmp_image(game->mlx, SHADOW_PATH, game);
	game->shadow_coin = read_xmp_image(game->mlx, SHADOW_COIN_PATH, game);
	game->player_win = read_xmp_image(game->mlx, PLAYER_WIN_PATH, game);
	game->player_loose = read_xmp_image(game->mlx, PLAYER_LOOSE_PATH, game);
	init_enemy_1_images(game);
	init_enemy_2_images(game);
	init_player_images(game);
	return (1);
}
