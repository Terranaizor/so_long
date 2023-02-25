/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nradin <nradin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:53:27 by nradin            #+#    #+#             */
/*   Updated: 2023/02/15 18:18:18 by nradin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	init_comp(t_comp *comps)
{
	comps->exit = 0;
	comps->player = 0;
	comps->collect = 0;
	comps->enemy = 0;
}

void	throw_error(t_comp *comps)
{
	if (comps)
		free(comps);
	ft_putstr_fd("Error\n", 2);
	exit(0);
}

size_t	ft_strstr_len(char **str)
{
	size_t	i;

	i = 0;
	while (*(str + i))
		i++;
	return (i);
}

char	**ft_strstrdup(char **str, int size)
{
	char	**res;
	int		i;

	res = (char **)ft_calloc(sizeof(char *), size + 1);
	i = 0;
	while (i < size)
	{
		res[i] = ft_strdup(str[i]);
		i++;
	}
	res[i] = NULL;
	return (res);
}

void	ft_strstr_free(char **str)
{
	int	size;
	int	i;

	i = 0;
	size = ft_strstr_len(str);
	while (i < size)
	{
		free(str[i]);
		i++;
	}
	free(str);
}
