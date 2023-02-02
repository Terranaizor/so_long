/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nradin <nradin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:59:03 by nradin            #+#    #+#             */
/*   Updated: 2023/02/02 15:14:40 by nradin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	check_rectangular(char **map)
{
	int	i;

	if (!map || !map[0])
		return (0);
	i = 1;
	while (map[i])
	{
		if (ft_strlen(map[i - 1]) != ft_strlen(map[i]))
			return (0);
		i++;
	}
	if (i < 2)
		return (0);
	return (1);
}

int	check_walls(char **map)
{
	int	i;
	int	j;

	if (!map || !map[0])
		return (0);
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if ((i == 0 || i == (int)ft_strstr_len(map) - 1 || \
				j == 0 || j == (int)ft_strlen(map[i]) - 2) && \
				map[i][j] != WALL && map[i][j] != '\n')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	components_ifs(char c, t_comp *comps)
{
	if (c == MAP_EXIT)
		comps->exit += 1;
	else if (c == PLAYER)
		comps->player += 1;
	else if (c == COLLECTIBLE)
		comps->collect += 1;
	else if (c != WALL && c != FLOOR && c != '\n')
		return (0);
	return (1);
}

t_comp	*check_components(char **map)
{
	int		i;
	int		j;
	t_comp	*comps;

	if (!map || !map[0])
		return (NULL);
	comps = calloc(sizeof(t_comp), 1);
	init_comp(comps);
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!components_ifs(map[i][j], comps))
				throw_error(comps);
			j++;
		}
		i++;
	}
	if (comps->exit != 1 || comps->player != 1 || comps->collect < 1)
		throw_error(comps);
	return (comps);
}

void	check_map(char	**map)
{
	t_comp	*comps;

	comps = check_components(map);
	if (!check_rectangular(map) || !check_walls(map) || \
		!find_path(map, comps))
		throw_error(comps);
}
