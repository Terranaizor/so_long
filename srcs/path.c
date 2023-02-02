/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nradin <nradin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:55:12 by nradin            #+#    #+#             */
/*   Updated: 2023/02/02 14:39:44 by nradin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	compare_components(t_comp *comps1, t_comp *comps2)
{
	if (comps1->exit != comps2->exit)
		return (0);
	if (comps1->collect != comps2->collect)
		return (0);
	free(comps2);
	return (1);
}

void	check_path(char **map, t_comp *comps, int x, int y)
{
	if (map[y][x] == MAP_EXIT)
		comps->exit = 1;
	else if (map[y][x] == COLLECTIBLE)
		comps->collect += 1;
	else if (map[y][x] == WALL)
		return ;
	map[y][x] = '-';
	if (x > 0 && map[y][x - 1] != '-')
		check_path(map, comps, x - 1, y);
	if (x < ((int)ft_strlen(map[y]) - 2) && map[y][x + 1] != '-')
		check_path(map, comps, x + 1, y);
	if (y > 0 && map[y - 1][x] != '-')
		check_path(map, comps, x, y - 1);
	if (y < ((int)ft_strstr_len(map) - 1) && map[y + 1][x] != '-')
		check_path(map, comps, x, y + 1);
}

int	find_path(char **map, t_comp *comps)
{
	int		i;
	int		j;
	t_comp	*reach;
	char	**mapcpy;

	if (!map || !map[0])
		return (0);
	reach = calloc(sizeof(t_comp), 1);
	init_comp(reach);
	mapcpy = ft_strstrdup(map, ft_strstr_len(map));
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == PLAYER)
				check_path(mapcpy, reach, j, i);
			j++;
		}
		i++;
	}
	ft_strstr_free(mapcpy);
	return (compare_components(comps, reach));
}
