/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 10:08:43 by nazouz            #+#    #+#             */
/*   Updated: 2024/08/01 10:09:27 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

int	validate_doors(t_game *game, char **map)
{
	int		i;
	int		j;
	int		k;

	(1) && (i = 0, k = 0, game->lvl.doors = alloc_doors(map));
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == DOOR)
			{
				if ((map[i][j + 1] != WALL || map[i][j - 1] != WALL)
					&& (map[i + 1][j] != WALL || map[i - 1][j] != WALL))
					return (0);
				game->lvl.doors[k].closed = 1;
				game->lvl.doors[k].coords.x = j;
				game->lvl.doors[k++].coords.y = i;
			}
			j++;
		}
		i++;
	}
	game->lvl.dcount = k;
	return (1);
}

int	validate_spaces(char **map)
{
	size_t		i;
	size_t		j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == EMPTY)
				if (!valid_left_right(map, i, j) || !valid_up_down(map, i, j))
					return (0);
		}
	}
	return (1);
}
