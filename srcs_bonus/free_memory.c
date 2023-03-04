/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nradin <nradin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:23:20 by nradin            #+#    #+#             */
/*   Updated: 2023/03/04 14:01:57 by nradin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	free_exit_sprites(t_game *game)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		if (game->map_exit[i].xpm_ptr)
			mlx_destroy_image(game->mlx, game->map_exit[i].xpm_ptr);
		i++;
	}
}

void	free_player_sprites(t_game *game)
{
	int	j;
	int	k;

	j = 0;
	while (j < 4)
	{
		k = 0;
		while (k < 5)
		{
			if (game->player[j][k].xpm_ptr && k != 2 && k != 4)
				mlx_destroy_image(game->mlx, game->player[j][k].xpm_ptr);
			k++;
		}
		j++;
	}
}

void	free_enemy_sprites(t_game *game)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (i < 2)
	{
		j = 0;
		while (j < 4)
		{
			k = 0;
			while (k < 5)
			{
				if (game->enemy[i][j][k].xpm_ptr && k != 2 && k != 4)
					mlx_destroy_image(game->mlx, game->enemy[i][j][k].xpm_ptr);
				k++;
			}
			j++;
		}
		i++;
	}
}

void	free_other_sprites(t_game *game)
{
	if (game->wall.xpm_ptr)
		mlx_destroy_image(game->mlx, game->wall.xpm_ptr);
	if (game->floor.xpm_ptr)
		mlx_destroy_image(game->mlx, game->floor.xpm_ptr);
	if (game->collectible.xpm_ptr)
		mlx_destroy_image(game->mlx, game->collectible.xpm_ptr);
	if (game->player_win.xpm_ptr)
		mlx_destroy_image(game->mlx, game->player_win.xpm_ptr);
	if (game->player_loose.xpm_ptr)
		mlx_destroy_image(game->mlx, game->player_loose.xpm_ptr);
	if (game->shadow.xpm_ptr)
		mlx_destroy_image(game->mlx, game->shadow.xpm_ptr);
	if (game->shadow_coin.xpm_ptr)
		mlx_destroy_image(game->mlx, game->shadow_coin.xpm_ptr);
	if (game->black.xpm_ptr)
		mlx_destroy_image(game->mlx, game->black.xpm_ptr);
}

void	free_game(t_game *game)
{
	if (game->map)
		ft_strstr_free(game->map);
	free_enemy_sprites(game);
	free_player_sprites(game);
	free_exit_sprites(game);
	free_other_sprites(game);
	free(game->enemy_status);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	free(game);
}
